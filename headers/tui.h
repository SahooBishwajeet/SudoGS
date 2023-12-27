#ifndef TUI_H
#define TUI_H

#include <ncurses.h>

#include "sudoku_solver.h"

int getChoice();
int getDifficulty();
void displaySolution(int sudoku[][SUDOKU_SIZE]);

#endif