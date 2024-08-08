#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void display_files(unsigned char ** mat, unsigned char ** mat_ia1){

    //Variables definition
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Initialisation de la matrice 1
    initialisation_matrice(mat,  mat_ia1);

    //Ouverture de tout les fichier comportant les grilles du joueur et de l'adversaire
    //Ouverture du fichier matrice J1
    FILE *fp0 = NULL;
    fp0 = fopen("sudoku1.0.txt", "r");

    //Gestions des erreurs d'ouverture du fichier
    if (fp0 == NULL){
        gotoligcol(48,70);
        SetConsoleTextAttribute(hConsole, 12);
        printf("Error. File opening problem.\n");
        SetConsoleTextAttribute(hConsole, 15);
    }
    else{
        gotoligcol(0, 0);
        SetConsoleTextAttribute(hConsole, 11);
        printf("Game 1 :");
        SetConsoleTextAttribute(hConsole, 15);
        gotoligcol(1, 0);
        for (int i = 0 ; i < 9 ; i++){
            for (int j = 0 ;j < 9 ; j++){
                //On scan la matrice
                fscanf(fp0, "%2s", &mat[i][j]);
                if (mat[i][j] == 'P' || mat[i][j] == 'C' || mat[i][j] == 'D' || mat[i][j] == 'S'){
                    SetConsoleTextAttribute(hConsole, 10);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'X'){
                    SetConsoleTextAttribute(hConsole, 12);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == 'O'){
                    SetConsoleTextAttribute(hConsole, 9);
                    printf("%2c", mat[i][j]);
                    SetConsoleTextAttribute(hConsole, 15);
                }
                if (mat[i][j] == B){
                    printf("%2c", mat[i][j]);
                }
            }
            printf("\n");
        }
        //Fermeture du fichier.
        fclose(fp0);
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////