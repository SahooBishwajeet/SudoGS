#ifndef FILL_GRID_H
#define FILL_GRID_H

#include <random>
#include <algorithm>
#include <chrono>
#include <array>

#define SUDOKU_SIZE 9
#define EMPTY_CELL 0

bool fillGrid(int sudoku[][SUDOKU_SIZE]);
bool isValid(int sudoku[][SUDOKU_SIZE], int row, int col, int num);
bool hasEmptyCell(int sudoku[][SUDOKU_SIZE]);

#endif // FILL_GRID_H