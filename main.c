#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "input.h"
#include "map.h"
#include "placement.h"
#include "movement.h"
#include "txtedit.h"
int main(int argc, char* argv[]){

//definition of game variables
char genphase[] = "generate";
char placephase[] = "phase=placement";
char movephase[] = "phase=movement";
int i, columns=0,rows=0,playerNum=0,penguinNum=0,tileamount;
int* pBoard, *pPlayerScore;
char Name1[20],Name2[20],Name3[20],Name4[20],Name5[20],Name6[20],Name7[20],Name8[20],Name9[20];
char* Names[9];
Names[0] = &Name1[0];
Names[1] = &Name2[0];
Names[2] = &Name3[0];
Names[3] = &Name4[0];
Names[4] = &Name5[0];
Names[5] = &Name6[0];
Names[6] = &Name7[0];
Names[7] = &Name8[0];
Names[8] = &Name9[0];
FILE* filePtr;

//checking commandline argument amount
if(argc<2 || argc>5){
    cmdlineError();
    return -1;
}
//checking if phase argument was implemented correctly
if((strcmp(argv[1], placephase) != 0)&&(strcmp(argv[1], genphase) != 0)&&(strcmp(argv[1], movephase) != 0)){
    cmdlineError();
    return -1;
}
//code for generation phase
if(strcmp(argv[1], genphase) == 0){
    columns = colInput();
    rows = rowInput();
    playerNum = playerNumInput();
    penguinNum = 0;
    tileamount = rows * columns;
    pBoard = calloc(tileamount, sizeof(int));
    GenGrid(pBoard, rows, columns);
    pPlayerScore = calloc(playerNum, sizeof(int));
    for(i = 0; i<playerNum; i++){
        *(pPlayerScore+i) = penguinNum;
        printf("Input name of player %d: ", i+1);
        scanf("%s", Names[i]);
    }
    PrintGrid(pBoard, rows, columns);
    filePtr = fopen(argv[2], "w");
    fileDump(filePtr, &columns, &rows, pBoard, Names, pPlayerScore, &playerNum, &argv[2]);
    fclose(filePtr);
    free(pPlayerScore);
    free(pBoard);
    return 0;
}

//code for placement phase
if(strcmp(argv[1], placephase) == 0){
    if(*argv[2] < 49|| *argv[2]>57){
        cmdlineError();
        return -1;
    }
    if((filePtr = fopen(argv[3], "r")) >0){
        rowColRead(filePtr,&columns, &rows, &argv[3]);
        tileamount = rows*columns;

        pBoard = calloc(tileamount, sizeof(int));
        pPlayerScore = calloc(1, sizeof(int));

        boardRead(filePtr, pBoard, &columns, &rows, &argv[3]);
        scoreRead(filePtr, &Names[0], &rows, pPlayerScore, &playerNum, &argv[3]);

        penguinNum = atoi(argv[2]);
        for(i = 0; i<playerNum; i++){
        *(pPlayerScore+i) = penguinNum;
        }
        PrintGrid(pBoard, rows, columns);

        place(pBoard, rows, columns, penguinNum, playerNum);

        filePtr = fopen(argv[4], "w");
        fileDump(filePtr, &columns, &rows, pBoard, Names, pPlayerScore, &playerNum, &argv[4]);

        fclose(filePtr);
        free(pPlayerScore);
        free(pBoard);
        return 0;
    } else {
        printf("Could not read file.\n");
        return 1;
    }
}

//code for movement phase
if(strcmp(argv[1], movephase) == 0){
    if((filePtr = fopen(argv[2], "r")) > 0){
        rowColRead(filePtr,&columns, &rows, &argv[2]);
        tileamount = rows*columns;

        pBoard = calloc(tileamount, sizeof(int));
        boardRead(filePtr, pBoard, &columns, &rows, &argv[2]);

        pPlayerScore = calloc(1, sizeof(int));
        scoreRead(filePtr, &Names[0],&rows, pPlayerScore, &playerNum, &argv[2]);
        for (i = 0; i <tileamount ; ++i) {
            if(*(pBoard+i)== 65) penguinNum++;
        }

        bool endGame = endGameCheck(pBoard, rows, columns, penguinNum, playerNum);
        while(endGame != true){
            for(i = 1; i<=playerNum; i++){
                PrintGrid(pBoard, rows, columns);
                movement(pBoard, rows, columns, penguinNum, i, pPlayerScore);
                if(fileDump(filePtr, &columns, &rows, pBoard, Names, pPlayerScore, &playerNum, &argv[3])<1) return 1;
                //printf("Score of player %d = %d\n", i, pPlayerScore[i-1]);
            }
            endGame = endGameCheck(pBoard, rows, columns, penguinNum, playerNum);
            //printf("%d", endGame);
        }
        printf("No one can make a move - the game has ended!\n");
        for(i = 1; i<=playerNum; i++){
            printf("Score of %s = %d\n", Names[i-1], pPlayerScore[i-1]);
        }
        free(pPlayerScore);
        free(pBoard);
        return 0;
    }
} else {
    printf("Could not read file.\n");
    return 1;
}
}



