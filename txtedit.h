#include <stdio.h>

//functions responsible for reading info from save file, and for creating a save file
int rowColRead(FILE*, int*, int*, char**);
int boardRead(FILE* , int*, int*, int*, char**);
int scoreRead(FILE*, char**,int*, int*, int*, char**);
int fileDump(FILE*, int*, int*, int*, char**, int*,int*, char**);
