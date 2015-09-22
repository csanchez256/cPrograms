/*********************************************************
* Christopher Sanchez; CS 241
* this program reads a bunch of sudoku puzzles and solves
* them. Each puzzle is given as a line of 81 characters
* with '.' characters representing unknown digits.
*  Run with:
*  ./a.out < single.in > myOut.txt
**********************************************************/

#include <stdio.h>

#define MAXCHARACTERS 81
#define DEBUG 0
#define VALID 1
#define NOTVALID 0
#define EMPTY '.'

void printSolvedBoard();
int checkIfValid();
void printBoard();
int solvePuzzle();
int findEmptyBlock();
int safe();
int duplicateRow();
int duplicateCol();
int duplicateInBox();


void main(void)
{
  int twoDimArray[9][9];
  int characterArray[81];
  int row,col;
  int readChars;
  readChars = 1;
  row = col = 0;

  int x = checkIfValid(characterArray, readChars);
 
  if(x == 0) puts("Try Again");
  else if(x)
  {
    if (DEBUG == 1) puts("passed");
    printBoard(characterArray,twoDimArray); 
    
    if(solvePuzzle(twoDimArray,row,col))
    {        
      printSolvedBoard(twoDimArray); 
    }
    else printf("No Solution");
  //  printBoard(characterArray,twoDimArray); 
  }
}


int checkIfValid(int characterArray[], int readChars)
{
  int characters, c;
  characters = c = 0;
  while ((c = getchar()) != EOF)
  {
    if (characters > MAXCHARACTERS)
    {
      if (DEBUG == 1) puts("Too many characters");
      readChars = NOTVALID;
    }

    else if ((c >= '0' && c <= '9') || (c == '.') && (readChars == VALID))
    { 
      if (DEBUG == 1) puts("ok");

      /* now we are going to load the caracters into an Array */
      characterArray[characters] = c;
      characters++;
    }

    /* Compliment of above conditions */
    else if(c == '\n')
    {
      if (characters < 81)
      {
        printf("Not enough Characters\n");  
        return 0;
      }
      if (DEBUG == 1) puts("End of Record");
    }
    else 
    {
     printf("Invalid Characer\n");
     return 0;
    }
  }
  if (readChars == NOTVALID) return 0;
  else  return 1;
}

/* not: the secon and subsequent dimensions must be given
 * or give a pointer to a pointer */

void printBoard(int characterArray[], int twoDimArray[][9])
{
  int i,j,k;
  k = 0;  
  for (i = 0; i < 9; i++)
  {
    for (j = 0; j < 9; j++)
    {
      twoDimArray[i][j] = characterArray[k];
      printf("%c",twoDimArray[i][j]);
      k++;
    }
    printf("\n");
  }
}


/* Takes an unsolved sudoku matrix and sovles it */
int solvePuzzle(int twoDimArray[][9], int row, int col)
{
  int num;
  
  /* Check if an empty block exits */
  if(findEmptyBlock(twoDimArray,row,col)) return 1;
  
  /* not start checking digits 1 - can be placed */
  for(num = 1; num <=9; num++)
  { 
    if (safe(twoDimArray,row,col,num))
    {
     twoDimArray[row][col] = num;
    
      if (solvePuzzle(twoDimArray,row,col)) return 1;
      /* reassing and try again */
      else twoDimArray[row][col] = EMPTY;
    }
  } 
  

}

/* This finds an available block that needs to be fileld with a number */
int findEmptyBlock(int twoDimArray[][9], int row, int col)
{
 for(row = 0; row < 9; row++)
 {
   for(col = 0; col < 9 ;col++)
   {
     if(twoDimArray[row][col] == EMPTY) return 1;
   }
 }
 return 1;
}

/* checks if it is a valid square */
int safe(int twoDimArray[][9], int row, int col, int num)
{
  if(duplicateRow(twoDimArray,row,num)) return 0;
  if(duplicateCol(twoDimArray,col,num)) return 0;
  if(duplicateInBox(twoDimArray, row - row % 3, col - col % 3, num)) return 0;
 
  else return 1;
}

/*checks if there are any duplicates in the row */
int duplicateRow(int twoDimArray[][9], int row, int num)
{ 
  int col;
  for(col = 0; col < 9; col++)
  {
    if(twoDimArray[row][col] == num) return 1;
  } 
  return 0;

}

/* checks if there are any duplicates in the column */
int duplicateCol(int twoDimArray[][9], int col,int num)
{
  int row;
  for(row = 0; row < 9; row++)
  {
    if(twoDimArray[row][col] == num) return 1;
  }
  return 0;
}


int duplicateInBox(int twoDimArray[][9], int boxRow, int boxCol,int num)
{
  int row, col;
  for(row = 0; row < 3; row++)
  { 
    for(col = 0; col < 3; col++)
    {
      if(twoDimArray[row + boxRow][col + boxCol] == num) return 1;
    }
  }
  return 0;
}

void printSolvedBoard(int twoDimArray[][9])
{
 int i,j;
 for(i = 0; i < 9; i++)
 {
   for(j = 0; j < 9; j++)
   {
     printf("%d", twoDimArray[i][j]);
   }
   printf("\n");
 } 
}


















