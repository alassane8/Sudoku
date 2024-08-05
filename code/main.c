#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#include "prototypes.h"
#include "gotoligcol.h"
#include "menu.h"
#include "decorations.h"
#include "initialization_matrices.h"
#include "choice_loading_game.h"
#include "choice_saving_game.h"
#include "rules.h"
#include "play.h"
#include "exitgame.h"
#include "sudokuascii.h"
#include "easy.h"
#include "medium.h"
#include "hard.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    
    //Variables definitions
    int i;
    unsigned char ** mat = NULL;
    unsigned char ** mat_bis = NULL;
    char pseudo[100];
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Sudoku
    system("cls");
    gotoligcol(0, 30);
    SetConsoleTextAttribute(hConsole, 6);
    printf("/////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("S U D O K U");
    SetConsoleTextAttribute(hConsole, 6);
    printf(" ///////////////////////////////////////\n");
    gotoligcol(3, 30);
    printf("////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Please, open the game page wide");
    SetConsoleTextAttribute(hConsole, 6);
    printf(" ////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);
    
    //Copyrights
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);

    // Pseudo input 
    gotoligcol(5, 70);
    SetConsoleTextAttribute(hConsole, 6);
    printf("Enter your pseudo: ");
    SetConsoleTextAttribute(hConsole, 15);
    gets(pseudo);
    gotoligcol(6, 70);
    gotoligcol(6, 70);
    printf("Welcome %s !\n\n", pseudo);

    sudokumain();

    gotoligcol(30, 70);
    printf("Loading...");
    sleep(3);
    system("cls");

    //Création de la ligne [1][j]
    mat = (unsigned char **)malloc(10 * sizeof(unsigned char*));

    //Création de la ligne [1][j]
    mat_bis = (unsigned char **)malloc(10 * sizeof(unsigned char*));

    for (i = 0; i < 10; i++) {
        mat[i] = (unsigned char *)malloc(10 * sizeof(unsigned char));
        mat_bis[i] = (unsigned char *)malloc(10 * sizeof(unsigned char));
    }

    //Calling menu
    menu(mat, mat_bis, pseudo);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////