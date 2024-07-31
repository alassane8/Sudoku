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
    for (i = 1; i < 10; i++){
        for (j = 1; j < 10; j++){
            mat[i][j] = underscore;
            mat_ia1[i][j] = underscore;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////