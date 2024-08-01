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

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif