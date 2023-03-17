#include <stdio.h>
#include "pengsetup.h"

//the function takes in pointer to the array of penguins, number of players and penguins and assigns values to the given array starting from 65 (is "A" when displayed as a character)

void penguinSetup(int* pPenguinArr, int playerNum){
    int i;
    int j = 65;
    for(i = 0; i<playerNum; i++){
        *(pPenguinArr+i) = j;
       // printf("%c \n", *(pPenguinArr+i));         //print the whole penguin array (just for testing)
        j = j + 1;
    }
}



