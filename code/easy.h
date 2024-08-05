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
    int k =0;
    int randomNumber;
    int randomPositionX;
    int randomPositionY;
    int underscore = 95;
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    //Choose randomly number and positions in grid
    do{
        k ++;
        srand(time(0));
        randomNumber = rand() % (9) + 1;
        randomPositionX = rand() % (9) + 1;
        randomPositionY = rand() % (9) + 1;
        for (i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                if(mat[i][randomPositionY] == randomNumber && i != randomPositionY){
                    randomNumber = rand() % (9) + 1;
                }
                if(mat[randomPositionX][j] == randomNumber && j != randomPositionX){
                    randomNumber = rand() % (9) + 1;
                }
            }
        }
    mat[randomPositionX][randomPositionY] = randomNumber;
    } while(k != 49);
//mat[randomPositionX][randomPositionY] == underscore
        for (i = 0; i < 9; i++){
            for(j = 0; j < 9; j++){
                printf("%2c", mat[i][j]);
                if (mat[i][j] != underscore){
                    printf("%2d", mat[i][j]);
                }
            }
            printf("\n");
        }
        sleep(10);
}
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
