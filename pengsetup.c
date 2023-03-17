#include <stdio.h>

//the function takes in pointer to the array of penguins, number of players and penguins and assigns values to the given array starting from 65 (is "A" when displayed as a character)

void penguinSetup(int* pPenguinArr, int penguinNum, int playerNum){
    int i;
    int j = 65;
    int penguins = penguinNum;
    int players = playerNum;
    int mult = penguins*players;

    for(i = 0; i<playerNum; i++){
        *(pPenguinArr+i) = j;
    //printf("%c \n", *(pPenguinArr+i));         //print the whole penguin array (just for testing)
        j = j + 1;
}
}



