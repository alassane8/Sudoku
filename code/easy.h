#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void easy(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo){
    
    //Variables definition
    int index;
    int randomNumber;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    int values[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int size = sizeof(values) / sizeof(values[0]);

    //Choose randomly number and positions in grid
    srand(time(0));
    for (int i = 0; i < 9; i++){
        for(int j = 0; j < 9; j++){
            do {
                // Sélectionner un indice aléatoire dans le tableau
                index = rand() % size;
                // Récupérer la valeur correspondante
                randomNumber = values[index];
            }while(randomNumber == 0);
            values[index] = 0;
            mat[i][j] = randomNumber;
        }
        for (int k = 0; k < 9; k ++ ){
            values[k] = k + 1;
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
