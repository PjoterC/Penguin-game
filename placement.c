#include <stdio.h>
/*
 this function takes the pointer to the board, numbers of rows, columns, amount of players and their penguins, and a pointer to the penguin array and
 assigns the appropriate values on the board, depending on player input
 */
void place(int* pBoard, int rows, int columns, int penguinNum, int playerNum, int*pPenguinArr)
{

    int i, j, x, y;
    int penguins = penguinNum;
    int players = playerNum;
    int target = 0;
    for(j = 0; j<penguins; j++)
    {
        for(i = 0; i<players; i++){
            printf("Player %d now will place their penguin number %d\n", i+1, j+1);
            printf("Enter x coordinate of placement: ");
            scanf("%d", &x);
            printf("Enter y coordinate of placement: ");
            scanf("%d", &y);
            target = *(pBoard+(((x-1)+(y-1)*columns)));

            while(target != 1){
                printf("Can only place on floe with 1 fish\n");

                printf("Enter x coordinate of placement: ");
                scanf("%d", &x);
                printf("Enter y coordinate of placement: ");
                scanf("%d", &y);

                target = *(pBoard+(((x-1)+(y-1)*columns)));
                }

            *(pBoard+(((x-1)+(y-1)*columns))) = *(pPenguinArr+i);
            PrintGrid(pBoard, rows, columns);
            }



    }
}
/*
For example: with 2 players player 1 will have penguins A and player 2 penguins B
*/

