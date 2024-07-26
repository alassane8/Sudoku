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
#include "rules.h"

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main(){
    
    //Variables definitions
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Sudoku
    system("cls");
    gotoligcol(0, 30);
    SetConsoleTextAttribute(hConsole, 11);
    printf("/////////////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("S U D O K U");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ///////////////////////////////////////\n");
    gotoligcol(3, 30);
    printf("////////////////////////////// ");
    SetConsoleTextAttribute(hConsole, 15);
    printf("Please, open the game page wide");
    SetConsoleTextAttribute(hConsole, 11);
    printf(" ////////////////////////////");
    SetConsoleTextAttribute(hConsole, 15);
    
    //Copyrights
    gotoligcol(44, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");

    //Calling menu
    menu();

}