
	
	

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
  int duplicateIndex;
  char checkDuplicate[9];

  inputRecord = 1;
  numChars = duplicateIndex = c = 0;

  while ((c = getchar()) != EOF)
  {
     printf("%c",c);
    
     /* Load 9 elements into this array and see if there are any duplicates */ 
     checkDuplicate[duplicateIndex] = c;
    printf("check duplicates: at - %d , %c\n",duplicateIndex, checkDuplicate[duplicateIndex]); 
     
    /* we are going to check for duplicates */
     if(duplicateIndex == 8) 
     {

       int count = sizeof(checkDuplicate)/sizeof(checkDuplicate[0]);
       int i,j;

       for (i=0;i<count;i++) 
       {
         for(j=i+1;j<count;j++) 
         {
           if (checkDuplicate[i] == checkDuplicate[j]) 
           {
            // printf("duplicate found\n");
             inputRecord = NOTVALID;
           }
         }
       }
       duplicateIndex = 0;
     }
     
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
       else if( (numChars == MAXCHARACTERS) && (inputRecord == VALID))
       {
         printf("OK!!!!\n\n");
         numChars = 0;
       //  inputRecord = VALID;
       }
     }
    else {
          /* you want to add characters to elements here */
          inputRecord = VALID;
          numChars++;
         } 
    duplicateIndex++;
  }/*end of while loop */
return 1;
}











