#include<stdio.h>
#include<stdbool.h>
#include <stdlib.h>


// a function that takes in a current position of a penguin and number of columns and checks whether the penguin cam make a move
int pengCheck(int *pCurrPos, int columns){
if(*(pCurrPos-columns) != 1 && *(pCurrPos-columns) != 2 && *(pCurrPos-columns) != 3 &&
   *(pCurrPos+columns) != 1 && *(pCurrPos+columns) != 2 && *(pCurrPos+columns) != 3 &&
   *(pCurrPos+1) != 1 && *(pCurrPos+1) != 2 && *(pCurrPos+1) != 3 &&
   *(pCurrPos-1) != 1 && *(pCurrPos-1) != 2 && *(pCurrPos-1) != 3){
   return 1;
   }
else{
    return 0;
}
}

// a function that takes in the pointer to board, numbers of rows and columns, pointer to the array of player's penguins and the amount of penguins and checks whether a player can make a move at all (not yet fully functional)

bool playerCheck(int* pBoard, int rows, int columns, int playerPenguin, int penguinNum){
int j, k;
int checkval = 0;
int *target;

    for(j = 0; j<rows; j++){
        for(k = 0; k<columns; k++){
            if(((*((pBoard+(j*columns))+k)) == playerPenguin)){

                target = pBoard+j*columns+k;

                checkval = checkval + pengCheck(target, columns);
            }
        }
    }


   if(checkval == penguinNum){
    return true;
   }
   else{
    return false;
   }
}

// a function that takes in the pointer to the board, amount of columns and rows, pointer to the array of penguins, amount of penguins and players and checks whether no player can make a move (endgame condition)

bool endGameCheck(int* pBoard, int rows, int columns, int* pPenguinArr, int penguinNum, int playerNum)
{
    int i, j, k;
    int checkval = 0;
    int *target = NULL;
    for(i = 0; i<playerNum; i++){
        for(j = 0; j<rows; j++){
            for(k = 0; k<columns; k++){
                if(((*((pBoard+j*columns)+k)) == *(pPenguinArr+i))){
                    target = pBoard+j*columns+k;
                    checkval += pengCheck(target, columns);

                }
            }
        }

}
if(checkval == penguinNum*playerNum){
    return true;
}
return false;
}



/*
a function that takes in the pointer to the board, amount of rows, columns, penguins and players, the pointer to array of penguins, number of current player and pointer to player's score,
changes the values on the board adequately to the given input and assigns points to players
*/
void movement(int* pBoard, int rows, int columns, int penguinNum, int playerNum, int* pPenguinArr, int currPlayer, int* pPlayerScore){

int playerPenguin;

int x, y, dir;

int k = 1;
int *pCurrPos = NULL;
bool checkP;


// assigns penguins to the player

playerPenguin = *(pPenguinArr+currPlayer-1);
//printf("%c", playerPenguin); //test

//check if the turn should be skipped
    checkP = playerCheck(pBoard, rows, columns, playerPenguin, penguinNum);

    if(checkP == true)
    {
        printf("Player %d has no penguins that can move - skipping turn\n", currPlayer);
    }
    else{

        printf("Player %d will now choose the penguin to move\n", currPlayer);
        printf("Enter coordinate x: ");
        scanf("%d", &x);
        printf("Enter coordinate y: ");
        scanf("%d", &y);



//check if the input was correct

    while(*((pBoard+((y-1)*columns)+x-1)) != playerPenguin){
       printf("Enter coordinate x: ");
        scanf("%d", &x);
        printf("Enter coordinate y: ");
        scanf("%d", &y);
        printf("Choose your penguin correctly!\n");

    }
     pCurrPos = pBoard+(y-1)*columns+x-1;


    int check = pengCheck(pCurrPos, columns); //check if penguin can make a move, if not asks to choose another
    while(check == 1){
        printf("This penguin cannot move, choose another one\n");


        printf("Player %d will now choose the penguin to move\n", currPlayer);
        printf("Enter coordinate x: ");
        scanf("%d", &x);
        printf("Enter coordinate y: ");
        scanf("%d", &y);


//check if the input was correct

while(*((pBoard+((y-1)*columns)+x-1)) != playerPenguin){
    printf("Choose your penguin!\n");
    printf("Enter coordinate x: ");
    scanf("%d", &x);
    printf("Enter coordinate y: ");
    scanf("%d", &y);

}
 pCurrPos = pBoard+(y-1)*columns+x-1;
check = pengCheck(pCurrPos, columns); //check if penguin can move
}


//asking for direction input, movement and adding points to the points array

while(k == 1){
    printf("In what direction would you like to move?\n");
    printf("1 - up\n");
    printf("2 - down\n");
    printf("3 - left\n");
    printf("4 - right\n");
    scanf("%d", &dir);

while(dir != 1 && dir != 2 && dir != 3 && dir != 4){
    printf("Please input correct value: ");
    scanf("%d", &dir);
}


switch (dir){
    case 1:
    if(*(pCurrPos-columns) == 1 || *(pCurrPos-columns) == 2 || *(pCurrPos-columns) == 3){
        *(pPlayerScore + currPlayer - 1) += *(pCurrPos-columns);
        *pCurrPos = 0;
        *(pCurrPos-columns) = playerPenguin;
        k = 0;
    }
    else{
        printf("You cannot move in this direction\n");
    }
    	break;
    case 2:
        if(*(pCurrPos+columns) == 1 || *(pCurrPos+columns) == 2 || *(pCurrPos+columns) == 3){
        *(pPlayerScore + currPlayer - 1) += *(pCurrPos+columns);
        *pCurrPos = 0;
        *(pCurrPos+columns) = playerPenguin;
        k = 0;
    }
    else{
        printf("You cannot move in this direction\n");
    }

   		break;
    case 3:
        if(*(pCurrPos-1) == 1 || *(pCurrPos-1) == 2 || *(pCurrPos-1) == 3){
        *(pPlayerScore + currPlayer - 1) += *(pCurrPos-1);
        *pCurrPos = 0;
        *(pCurrPos-1) = playerPenguin;
        k = 0;
    }
    else{
        printf("You cannot move in this direction\n");
    }

    	break;
    case 4:
        if(*(pCurrPos+1) == 1 || *(pCurrPos+1) == 2 || *(pCurrPos+1) == 3){
        *(pPlayerScore + currPlayer - 1) += *(pCurrPos+1);
        *pCurrPos = 0;
        *(pCurrPos+1) = playerPenguin;
        k = 0;
    }
    else{
        printf("You cannot move in this direction\n");
    }

   		break;
  default:
      printf("Please enter correct direction");
    	break;

}
}
    }
}



