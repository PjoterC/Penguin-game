
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "map.h"

//assigns values to the board array depending on the amount of rows and columns
void GenGrid(int* board, int X, int Y) {
    srand(time(NULL));
    int num;
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
                num = rand() % 4;
                *(board + i*Y + j) = num;
        }
    }
    for(int i = 0; i<Y; i++) *(board + i) = 0;
    for(int i = 0; i<Y; i++) *(board + i + X*Y - Y) = 0;
    for(int i = 0; i<X; i++) *(board + i*Y) = 0;
    for(int i = 0; i<X; i++) *(board + Y + i*Y-1) = 0;
}

//prints the board
void PrintGrid(int* arr, int X, int Y) {
    int dashes;
    for(dashes = 0; dashes < Y; dashes++){
        printf("|---");
    }
    printf("|\n");
    for(int i = 0; i < X; i++) {
        for(int j = 0; j < Y; j++) {
            int n = *(arr + i*Y + j);
            if(n == 0 || n == 1 || n == 2 || n == 3) {
                printf("| %d ", n);
            } else{
                printf("| %c ", n);
            }
        }
        printf("|\n");
        for (dashes = 0; dashes < Y; dashes++){
            printf("|---");
        }
        printf("|\n");
    }
}