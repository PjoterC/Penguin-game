#include <stdio.h>
#include "placement.h"
#include "map.h"
/*
 this function takes the pointer to the board, numbers of rows, columns, amount of players and their penguins, and a pointer to the penguin array and
 assigns the appropriate values on the board, depending on player input
 */
void place(int* pBoard, int rows, int columns, int penguinNum, int playerNum){
    int i, j, x, y;
    int penguins = penguinNum;
    int players = playerNum;
    int target;
    for(j = 0; j<penguins; j++){
        for(i = 0; i<players; i++){
            printf("Player %d now will place their penguin number %d\n", i+1, j+1);
            printf("Enter x coordinate of placement: ");
            while((scanf("%d", &x))<1){
                scanf("%*[^\n]");
                printf("WRONG INPUT! Coordinate has to be a positive integer\n");
                printf("Enter x coordinate of placement: ");
            }
            printf("Enter y coordinate of placement: ");
            while((scanf("%d", &y))<1){
                scanf("%*[^\n]");
                printf("WRONG INPUT! Coordinate has to be a positive integer\n");
                printf("Enter y coordinate of placement: ");
            }
            target = *(pBoard+(((x-1)+(y-1)*columns)));
            while(target != 1){
                printf("Can only place on floe with 1 fish\n");
                printf("Enter x coordinate of placement: ");
                while((scanf("%d", &x))<1){
                    scanf("%*[^\n]");
                    printf("WRONG INPUT! Coordinate has to be a positive integer\n");
                    printf("Enter x coordinate of placement: ");
                }
                printf("Enter y coordinate of placement: ");
                while((scanf("%d", &y))<1){
                    scanf("%*[^\n]");
                    printf("WRONG INPUT! Coordinate has to be a positive integer\n");
                    printf("Enter y coordinate of placement: ");
                }
                target = *(pBoard+(((x-1)+(y-1)*columns)));
            }
            *(pBoard+(((x-1)+(y-1)*columns))) = (i + 65);
            PrintGrid(pBoard, rows, columns);
        }
    }
}

/*
For example: with 2 players having 3 penguins each, player 1 will have penguins A,B,C and player 2 will have D,E,F
*/

