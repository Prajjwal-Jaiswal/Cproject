#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int generateRandomNumber(int n)
{
    srand(time(NULL)); //srand takes seed as input and is defined inside stdlib.h
    return rand() % n; // random no.between 0 to n is
}

int greater(char char1,char char2)
{
    //returns 1 if char1>char2 and 0 otherwise. If c1==c2 it will return -1
    if(char1==char2)
    return -1;
    else if((char1=='R'&&char2=='S'))
    return 1;
    else if((char2=='R'&&char1=='S'))
    return 0;
    else if((char1=='R'&&char2=='R'))
    return 1;
    else if((char2=='R'&&char1=='R'))
    return 0;
    else if((char1=='S'&&char2=='P'))
    return 1;
    else if((char2=='S'&&char1=='P'))
    return 0;
   

}

int main()
{
    int playerScore=0,compScore=0,temp;
    char playerChar,compChar;
    char dict[]={'R','P','S'};
    printf("Welcome to the Rock , Paper , Scissors game \n");
   
    for (int i = 0; i < 3; i++)
    {

        //Take player 1's input
      printf("Player 1's turn: \n");
      printf("Choose 1 for Rock , 2 for Paper and 3 for Scissors \n");
      scanf("%d",&temp);
      getchar();//it is used in order to consume the number which remains in input buffer so that program doesn't break 
      playerChar=dict[temp-1];
      printf("You chose %c \n\n",playerChar);


      // Generate Computer's input
      printf("Computer's turn: \n");
      printf("Choose 1 for Rock , 2 for Paper and 3 for Scissors \n");
      temp=generateRandomNumber(3)+1;
      compChar=dict[temp-1];
      printf("Computer chose %c \n\n",compChar);

      //compare the scores
      if(greater(compChar,playerChar)==1)
      {
          compScore+=1;
          printf("Computer got it ! \n");
      }

      else if (greater(compChar,playerChar)==-1)
      {
          printf("Its a draw ! \n");
      }

      else 
      {
      playerScore+=1;
      printf("You got it ! \n");
      }

    printf("You : %d \nComputer : %d \n\n",playerScore , compScore);
    }
    
    if(playerScore>compScore)
    printf("You win the game \n");
    else if(playerScore<compScore)
    printf("Computer wins the game");
    else
    printf("Its a draw");
    return 0;
}