#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void easy(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){
    
    //Variables definition
    int i;
    int j;
    int randomNumber;
    int underscore = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Choose randomly number and positions in grid
    srand(time(0));
    for (i = 0; i < 9; i++){
        for(j = 0; j < 9; j++){
            randomNumber = rand() % (9) + 1;
            mat[i][j] = randomNumber;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
