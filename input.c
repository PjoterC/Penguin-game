#include <stdio.h>
#include "input.h"
// input functions - they take input from the user and assign values for: number of colums, rows, players and penguins for each player

int colInput(){
    int columns;
    printf("Please enter the number of columns that the board will consist of:\n");
    printf("Please enter number of columns: ");
    while((scanf("%d", &columns))<1){
        scanf("%*[^\n]");
        printf("WRONG INPUT! Coordinate has to be a positive integer\n");
        printf("Please enter number of columns: ");
    }
    while(columns<1){
        printf("\nWRONG INPUT! The number of columns must be a positive integer.\n");
        printf("Please enter the number of columns: ");
        while((scanf("%d", &columns))<1){
            scanf("%*[^\n]");
            printf("WRONG INPUT! Coordinate has to be a positive integer\n");
            printf("Please enter number of columns: ");
        }
    }
    return columns;
}

int rowInput(){
    int rows;
    printf("Please enter the number of rows that the board will consist of:\n");
    printf("Please enter number of rows: ");
    while((scanf("%d", &rows))<1){
        scanf("%*[^\n]");
        printf("WRONG INPUT! Coordinate has to be a positive integer\n");
        printf("Please enter number of rows: ");
    }
    while(rows<1){
        printf("\nWRONG INPUT! The number of rows must be a positive integer.\n");
        printf("Please enter the number of rows: ");
        while((scanf("%d", &rows))<1){
            scanf("%*[^\n]");
            printf("WRONG INPUT! Coordinate has to be a positive integer\n");
            printf("Please enter number of rows: ");
        }
    }
    return rows;
}

int playerNumInput(){
    int players = 0;
    printf("Please enter number of players: ");
    while((scanf("%d", &players))<1 && players <1){
        scanf("%*[^\n]");
        printf("WRONG INPUT! Coordinate has to be a positive integer\n");
        printf("Please enter number of players: ");
    }
    return players;
}

int penguinNumInput(){
    int penguins=0;
    printf("Please enter number of penguins for each player: ");
    while((scanf("%d", &penguins))<1 && penguins <1){
        scanf("%*[^\n]");
        printf("WRONG INPUT! Coordinate has to be a positive integer\n");
        printf("Please enter number of penguins for each player: ");
    }
    return penguins;
}

void cmdlineError(){
    printf("\nWrong parameters\n\n");
    printf("Parameters for generation phase (generates the board text file with player IDs): generate output_file_name.txt\n\n");
    printf("Parameters for placement phase (allows players to place their penguins and saves the txt file): phase=placement number_of_penguins input_file_name.txt output_file_name.txt\n\n");
    printf("Parameters for movement phase (allows movement starting from player 1): phase=movement input_file_name.txt output_file_name.txt\n");
}
