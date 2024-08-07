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
    int x = 0;
    int y = 0;
    int option;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(34, 70);
    printf("Copyright 2024 Sudoku Alassane Wade");
    SetConsoleTextAttribute(hConsole, 15);
    sudokuascii();

    // Set the cursor position to the top-left corner of the screen
    SetCursorPos(0, 0);

    gotoligcol(23, 0);
    printf("Press '");
    SetConsoleTextAttribute(hConsole, 6);
    gotoligcol(23, 7);
    printf("arrow keys");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(23, 17);
    printf("' to move the cursor");
    gotoligcol(24, 0);
    printf("Press '");
    gotoligcol(24, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("m");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(24, 8);
    printf("' to go back to menu\n");  
    gotoligcol(25, 0);
    printf("Press '");
    gotoligcol(25, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("s");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(25, 8);
    printf("' to save\n");  
    gotoligcol(26, 0);
    printf("Press '");
    gotoligcol(26, 7);
    SetConsoleTextAttribute(hConsole, 6);
    printf("q");
    SetConsoleTextAttribute(hConsole, 15);
    gotoligcol(26, 8);  
    printf("' to quit\n"); 
    move_cursor(x, y);


    while (1) {
        keypressed = _getch();

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

        // Check for special keys
        if (keypressed == 224) { // Arrow keys have a leading 224
            keypressed = _getch(); // Get the actual key
            switch (keypressed) {
                case 72: // Up
                    y = (y > 0) ? y - 1 : y; // Move up, if possible
                    break;
                case 80: // Down
                    y++; // Move down
                    break;
                case 77: // Right
                    x++; // Move right
                    break;
                case 75: // Left
                    x = (x > 0) ? x - 1 : x; // Move left, if possible
                    break;
            } 
        move_cursor(x, y);
        }
    }
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////