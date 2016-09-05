#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
void randArray(int**prt,int rows,int col);
int inputs(char *message);
int** addMemory(int **prt,int rows,int col);
void printArray (int **prt, int rows,int col);
void freememory(int **prt,int rows);

int main() {
    int **prt;
    int rows=5,col=4;
    srand((unsigned) time(NULL));
    //col=inputs("Input the number of rows");
    //rows=inputs("Input the number of cols");

    prt=addMemory(prt,rows,col);
    randArray(prt,rows,col);
    printArray(prt,rows,col);
    freememory(prt,rows);

    return 0;
}
int** addMemory(int **prt,int rows,int col){
    int i;
    prt = (int**) malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        prt[i] = (int*) malloc(col * sizeof(int));
    }
    return prt;
}
void printArray (int **prt, int rows,int col){
    int i,j;
    printf("Array:\n");
    for(i=0;i<rows;i++){
        for(j=0;j<col;j++){
            printf ("%2d ",prt [i][j]);
        }
        printf("\n");
    }
}
void randArray(int**prt,int rows,int col){
    int i,j;
    for(i=0;i<rows;i++){
        for(j=0;j<col;j++){
            prt[i][j]=10+rand() % 50;
        }
    }
}
void freememory(int **prt,int rows){
    int i;
    for (i = 0; i < rows; i++) {
        free(prt[i]);
    }
    free(prt);
}
int inputs(char *message){
    char input[256];
    while (1)
    {
        printf(message);
        fgets(input, 256, stdin);
        int last = strlen(input)-1;
        input[last] = '\0';
        int i, not_digit = 0;
        for (i = 0; input[i] != '\0'; i++){
            if (!isdigit(input[i]))
            {
                not_digit = 1;
                printf ("Please enter the number! \n");
                break;
            }
        }
        if (not_digit)
            continue;
        return atoi(input);
    }
}
