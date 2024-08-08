#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

int Unique(unsigned char ** mat, int row, int col, int num){
    for (int j = 0; j < 9; j++) {
        if (mat[row][j] == num) {
            return 0;  // Number is not unique in the row
        }
    }
    for (int i = 0; i < 9; i++) {
        if (mat[i][col] == num) {
            return 0;  // Number is not unique in the column
        }
    }
    return 1;

}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void easy(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){
    
    //Variables definition
    int randomNumber;
    int underscore = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


    //Choose randomly number and positions in grid
    srand(time(0));
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            do{
                randomNumber = rand() % (9) + 1;
            }while(!Unique(mat, i, j, randomNumber));
            mat[i][j] = randomNumber;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
