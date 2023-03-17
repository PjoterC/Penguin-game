#include <stdbool.h>

// movement functions - they change the values of the board array, validate movement and add score
int pengCheck(int *pCurrPos, int columns);
bool playerCheck(int* pBoard, int rows, int columns, int playerPenguin, int penguinNum);
bool endGameCheck(int* pBoard, int rows, int columns, int* pPenguinArr, int penguinNum, int playerNum);
void movement(int* pBoard, int rows, int columns, int penguinNum, int playerNum, int* pPenguinArr, int currPlayer, int* pPlayerScore);
