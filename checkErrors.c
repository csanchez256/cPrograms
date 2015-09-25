
	
	

#include <stdio.h>

#define MAXCHARACTERS 81
#define DEBUG 0
#define DEBUG2 0
#define VALID 1
#define NOTVALID 0
#define EMPTY '.'

int checkIfValid();

void main(void)
{
  char twoDimArray[9][9];
  char characterArray[81];
  int row,col;
  int c,numChars, inputRecord,inputCharacters;
  int i,j,k;
  
  i = j = k= 0;
  row = col = numChars = 0;
  inputCharacters = 1;
  inputRecord = 1;

  int x = checkIfValid(characterArray,twoDimArray, inputCharacters); 

}

int checkIfValid(char characterArray[],char twoDimArray[], int inputCharacters)
{
  int numChars,c,inputRecord;
  inputRecord = 1;
  numChars = c = 0;
  while ((c = getchar()) != EOF)
  {
     printf("%c",c);

     if(numChars > MAXCHARACTERS)
     {
         printf("ERROR: TOO MANY : %d\n",numChars);
         numChars = 0;
         inputRecord = NOTVALID;
     }
     if( c == '\n')
     {
       if((numChars < MAXCHARACTERS) && (inputRecord == VALID))
       {
        printf("ERROR:TOO FEW : %d\n",numChars);
         numChars = 0;
         inputRecord = NOTVALID;
       }
       else if( numChars == MAXCHARACTERS)
       {
         printf("OK!!!!\n\n");
         numChars = 0;
       //  inputRecord = VALID;
       }
     }
    else {
          inputRecord = VALID;
          numChars++;
         }
  }
return 1;
}











