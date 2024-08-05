#ifndef PROTOTYPES_H
#define PROTOTYPES_H

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void menu(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void rules(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void  gotoligcol( int lig, int col );
void initialisation_matrice(unsigned char ** mat, unsigned char ** mat_ia1);
void decors();
void play(unsigned char **mat, unsigned char **mat_bis,  char *pseudo);
void sudokumain();
void sudokuascii();
void sudokuload();
void choice_loading_game(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void choice_saving_game(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void exitgame(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void easy(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void medium(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);
void hard(unsigned char ** mat, unsigned char ** mat_bis, char *pseudo);

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif