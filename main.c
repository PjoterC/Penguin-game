#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include "input.h"
#include "map.h"
#include "placement.h"
#include "pengsetup.h"
#include "movement.h"
int main()
{
int i;
int columns = colInput();
int rows = rowInput();
int playerNum = playerNumInput();
int penguinNum = penguinNumInput();
int tileamount = rows * columns;
int* pBoard;
pBoard = calloc(tileamount, sizeof(int));
int* pPenguinArr;
pPenguinArr = calloc(playerNum*penguinNum, sizeof(int));
int currPlayer;
int* pPlayerScore;
pPlayerScore = calloc(playerNum, sizeof(int));
for(i = 0; i<playerNum; i++){
    pPlayerScore[i] = penguinNum;
}



penguinSetup(pPenguinArr, penguinNum, playerNum);
GenGrid(pBoard, rows, columns);
PrintGrid(pBoard, rows, columns);
place(pBoard, rows, columns, penguinNum, playerNum, pPenguinArr);



bool endGame = endGameCheck(pBoard, rows, columns, pPenguinArr, penguinNum, playerNum);
while(endGame != true){
for(i = 1; i<=playerNum; i++){
currPlayer = i;
movement(pBoard, rows, columns, penguinNum, playerNum, pPenguinArr, currPlayer, pPlayerScore);
PrintGrid(pBoard, rows, columns);
printf("Score of player %d = %d\n", i, pPlayerScore[i-1]);
}
endGame = endGameCheck(pBoard, rows, columns, pPenguinArr, penguinNum, playerNum);
}
printf("No one can make a move - the game has ended!\n");

for(i = 1; i<=playerNum; i++){
    printf("Score of player %d = %d\n", i, pPlayerScore[i-1]);
}

free(pBoard);
free(pPenguinArr);
free(pPlayerScore);


return 0;
}



