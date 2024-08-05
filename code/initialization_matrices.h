#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void initialisation_matrice(unsigned char ** mat, unsigned char ** mat_ia1){

    //Variables definition
    int i;
    int j;
    int underscore = 95;

    //Matrices initializaions
    for (i = 0; i < 9; i++){
        for (j = 0; j < 9; j++){
            mat[i][j] = underscore;
            mat_ia1[i][j] = underscore;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////