#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
void move_cursor(int x, int y) {
    COORD coord = {x, y};
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void play(unsigned char **mat, unsigned char **mat_bis,  char *pseudo)
{
    // Variables definition
    char keypressed;
    int input;
    int x = 5;
    int y = 2;
    int option;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);
    sudokuascii();

    gotoligcol(23, 0);
    printf("Press '");
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(23, 7);
    printf("t,f,g,h");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(23, 14);
    printf("' to move the cursor");
    gotoligcol(24, 0);
    printf("Press '");
    gotoligcol(24, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("m");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(24, 8);
    printf("' to go back to Menu\n");  
    gotoligcol(25, 0);
    printf("Press '");
    gotoligcol(25, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("s");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(25, 8);
    printf("' to Save\n");  
    gotoligcol(26, 0);
    printf("Press '");
    gotoligcol(26, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("q");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(26, 8);  
    printf("' to Quit\n"); 

    // Set the cursor position to the top-left corner of the screen
    SetCursorPos(5, 2);
    move_cursor(x, y);


    while (1) {
        keypressed = _getch();
        if (keypressed >= '1' && keypressed <= '9'){
            gotoligcol(y, x);
            SetConsoleTextAttribute(hConsole, 6);
            printf("%c", keypressed);
            SetConsoleTextAttribute(hConsole, 15);
        }

        if (keypressed == 'q'){
            system("cls");
            exitgame(mat, mat_bis, pseudo);
        }
        
        if (keypressed == 's'){
            system("cls");
            choice_saving_game(mat, mat_bis, pseudo);
        }
        
        if (keypressed == 'm'){
            system("cls");
            menu(mat, mat_bis, pseudo);
        }
        if (keypressed == 't' && y > 2){//up
            y = (y > 1) ? y - 2 : y;
            move_cursor(x, y);
        }
        if (keypressed == 'g' && y < 18){//down
            y = y + 2;
            move_cursor(x, y);
        }
        if (keypressed == 'f'){//left
            x = (x > 0) ? x - 10 : x;
            move_cursor(x, y);
        }
        if (keypressed == 'h' && x < 85){//right
            x = x + 10;
            move_cursor(x, y);
        }
    }
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////