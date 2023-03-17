#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "txtedit.h"

int rowColRead(FILE* filePtr, int *pColumns, int *pRows, char** fname){
    filePtr = fopen(*fname, "r");
    if (filePtr == NULL) {
        printf("no such file");
        return 0;
    }
    char buf[100];
    char *endPtr = NULL;
    //reading columns and rows numbers
     fgets(buf, 3, filePtr);
     *pRows = strtol(buf, &endPtr, 10);
     fseek(filePtr, 3, SEEK_SET);
     fgets(buf, 3, filePtr);
     *pColumns = strtol(buf, &endPtr, 10);
     return 1;
}



int boardRead(FILE* filePtr, int* pBoard, int *pColumns, int *pRows, char** fname) {
    filePtr = fopen(*fname, "r");
    if (filePtr == NULL) {
        printf("no such file");
        return 0;
    }
    char buf[300];
    char *endPtr = NULL;
    //reading the board
    fscanf(filePtr, "%*[^\n]");
    for (long i = 0; i < *pRows; i++) {
        for (long j = 0; j < *pColumns; j++) {
            fgets(buf, 4, filePtr);
            switch (strtol(buf, &endPtr, 10)) {
                case 0:
                    *(pBoard + j + i * (*pColumns)-1) = 0; //floe or fish
                    break;
                case 10:
                    *(pBoard + j + i * (*pColumns)-1) = 1; //floe or fish
                    break;
                case 20:
                    *(pBoard + j + i * (*pColumns)-1) = 2; //floe or fish
                    break;
                case 30:
                    *(pBoard + j + i * (*pColumns)-1) = 3; //floe or fish
                    break;
                case 1:
                    *(pBoard + j + i * (*pColumns)-1) = 65; //player A (1)
                    break;
                case 2:
                    *(pBoard + j + i * (*pColumns)-1) = 66; //player B (2)
                    break;
                case 3:
                    *(pBoard + j + i * (*pColumns)-1) = 67; //player C (3)
                    break;
                case 4:
                    *(pBoard + j + i * (*pColumns)-1) = 68; //player D (4)
                    break;
                case 5:
                    *(pBoard + j + i * (*pColumns)-1) = 69; //player E (5)
                    break;
                case 6:
                    *(pBoard + j + i * (*pColumns)-1) = 70; //player F (6)
                    break;
                case 7:
                    *(pBoard + j + i * (*pColumns)-1) = 71; //player G (7)
                    break;
                case 8:
                    *(pBoard + j + i * (*pColumns)-1) = 72; //player H (8)
                    break;
                case 9:
                    *(pBoard + j + i * (*pColumns)-1) = 73; //player I (9)
                    break;
            }
        }
    }
    return 1;
}



int scoreRead(FILE* filePtr, char** pPlayerName,int* pRows, int *pScore, int * pNum, char** fname) {
    filePtr = fopen(*fname, "r");
    if (filePtr == NULL) {
        printf("no such file");
        return 0;
    }
    char buf[100];
    int i=0, dump;
    for (int j = 0; j <= *pRows; ++j) fgets(buf,100,filePtr);
    while(!(feof(filePtr))){
        if(i>=1) pScore = realloc(pScore, (1+i)*sizeof(int));
        fscanf(filePtr, "%s %d %d", buf, &dump, (pScore+i));
        //*(*(pPlayerName+i)) = buf;
        //printf("%s", buf);
        strncpy(*(pPlayerName+i), buf, 20);
        (*pNum) = (*pNum)+1;
        i++;
    }
    return 1;
}



int fileDump(FILE* filePtr, int* pColumns, int* pRows, int* pBoard, char** pPlayerName, int* pScore,int* pMaxPlayers, char** fname){
    filePtr = fopen(*fname, "w");
    if (filePtr == NULL) {
        printf("could not create file");
        return 0;
    }
    //printing Rows and Columns
    fprintf(filePtr, "%d %d\n", *pRows, *pColumns);
    //printing Board
    for (long i = 0; i < *pRows; i++) {
        for (long j = 0; j < *pColumns; j++) {
            switch(*(pBoard+j+(i*(*pColumns)))){
                case 0:
                    fprintf(filePtr, "00"); //floe or fish
                    break;
                case 1:
                    fprintf(filePtr, "10"); //floe or fish
                    break;
                case 2:
                    fprintf(filePtr, "20"); //floe or fish
                    break;
                case 3:
                    fprintf(filePtr, "30"); //floe or fish
                    break;
                case 65:
                    fprintf(filePtr, "01"); //player A (1)
                    break;
                case 66:
                    fprintf(filePtr, "02"); //player B (2)
                    break;
                case 67:
                    fprintf(filePtr, "03"); //player C (3)
                    break;
                case 68:
                    fprintf(filePtr, "04"); //player D (4)
                    break;
                case 69:
                    fprintf(filePtr, "05"); //player E (5)
                    break;
                case 70:
                    fprintf(filePtr, "06"); //player F (6)
                    break;
                case 71:
                    fprintf(filePtr, "07"); //player G (7)
                    break;
                case 72:
                    fprintf(filePtr, "08"); //player H (8)
                    break;
                case 73:
                    fprintf(filePtr, "09"); //player I (9)
                    break;
            }
            if(j<(-1+*pColumns)) fprintf(filePtr, " ");
        }
        fprintf(filePtr, "\n");
    }

    //printing Scores
    for (int i = 0; i < *pMaxPlayers; i++){
        fprintf(filePtr, "%s %d %d", *(pPlayerName+i), 1+i, *(pScore+i));
        if(1+i<*pMaxPlayers) fprintf(filePtr, "\n");
    }
    fclose(filePtr);
    return 1;
}

