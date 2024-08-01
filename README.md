# Sudoku

<h1 align="center">
Alassane WADE Sudoku Game
</h1>  

<h2 align="center">
 "⣾⣿⠿⠿⠶⠿⢿⣿⣿⣿⣿⣦⣤⣄⢀⡅⢠⣾⣛⡉⠄⠄⠄⠸⢀⣿. "
</h2>                                      

Game of Sudoku in C Language.

## Instructions
To play Sudoku, follow the instructions :

## Open a terminal in full screen.
- Clone this github repository in the path of your choice: 
```bash
git clone https://github.com/alassane8/Sudoko.git
```
- Go to the Sudoku folder :
```bash
cd Sudoku/code
```
- Run the Executable: 
```bash
./Sudoku.exe
```

## Have fun !
You are now ready to play !

## Rules
- Rule 1 - The player must focus on filling each row of the grid while ensuring there are
    no duplicated numbers. The placement order of the digits is irrelevant.
    Every puzzle, regardless of the difficulty level, begins with allocated numbers on the grid.
    The player should use these numbers as clues to find which digits are missing in each row.
    
- Rule 2 - Each column must contain the numbers from 1 to 9, without repetitions
    The Sudoku rules for the columns on the grid are exactly the same as for the rows. The player must
    also fill these with the numbers from 1 to 9, making sure each digit occurs only once per column.
    The numbers allocated at the beginning of the puzzle work as clues to find which digits are missing
    in each column and their position.

- Rule 3 - The digits can only occur once per block (nonet)
    A regular 9 x 9 grid is divided into 9 smaller blocks of 3 x 3, also known as nonets. The numbers
    from 1 to 9 can only occur once per nonet.
    In practice, this means that the process of filling the rows and columns without duplicated digits
    finds inside each block another restriction to the numbers’ positioning.

- Rule 4 - The sum of every single row, column, and nonet must equal 45
    To find out which numbers are missing from each row, column, or block or if there are any duplicates,
    the player can simply count or flex their math skills and sum the numbers. When the digits occur only once,
    the total of each row, column, and group must be 45.
    
    1+2+3+4+5+6+7+8+9= 45

## Area for improvement
Here, you can find the features I am currently working on in this repository.
This allows you to be aware of the changes that are to come and see what needs to be improve. 