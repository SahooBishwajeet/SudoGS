#ifndef PRINT_H
#define PRINT_H

#include <iostream>
#include <string>
#include <algorithm>
#include <ncurses.h>

#define SUDOKU_SIZE 9
#define EMPTY_CELL 0

void printSudoku(int sudoku[][SUDOKU_SIZE], bool nCurses);

#endif // PRINT_H