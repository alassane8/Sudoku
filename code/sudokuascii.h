#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sudokumain(){
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(12, 70);
    printf("               _       _ ");
    gotoligcol(13, 70);
    printf("              | |     | | ");
    gotoligcol(14, 70);
    printf(" ___ _   _  __| | ___ | | ___   _ ");
    gotoligcol(15, 70);
    printf("/ __| | | |/ _ `|/ _ L| |/ / | | |");
    gotoligcol(16, 70);
    printf("L__ L |_| | (_| | (_) |   <| |_| |");
    gotoligcol(17, 70);
    printf("|___/L__,_|L__,_|L___/|_|L_LL__,_|");
    SetConsoleTextAttribute(hConsole, 15);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void sudokuascii(){
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(12, 140);
    printf("               _       _ ");
    gotoligcol(13, 140);
    printf("              | |     | | ");
    gotoligcol(14, 140);
    printf(" ___ _   _  __| | ___ | | ___   _ ");
    gotoligcol(15, 140);
    printf("/ __| | | |/ _ `|/ _ L| |/ / | | |");
    gotoligcol(16, 140);
    printf("L__ L |_| | (_| | (_) |   <| |_| |");
    gotoligcol(17, 140);
    printf("|___/L__,_|L__,_|L___/|_|L_LL__,_|");
    SetConsoleTextAttribute(hConsole, 15);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void sudokuload(){
    
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(20, 140);
    printf("               _       _ ");
    gotoligcol(21, 140);
    printf("              | |     | | ");
    gotoligcol(22, 140);
    printf(" ___ _   _  __| | ___ | | ___   _ ");
    gotoligcol(23, 140);
    printf("/ __| | | |/ _ `|/ _ L| |/ / | | |");
    gotoligcol(24, 140);
    printf("L__ L |_| | (_| | (_) |   <| |_| |");
    gotoligcol(25, 140);
    printf("|___/L__,_|L__,_|L___/|_|L_LL__,_|");
    SetConsoleTextAttribute(hConsole, 15);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////