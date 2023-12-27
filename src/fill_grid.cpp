#include "fill_grid.h"

std::array<int, 9> value {1, 2, 3, 4, 5, 6, 7, 8, 9}; 

/**
 * @brief Checks the validity of placing a number in a specific position in the Sudoku grid.
 * 
 * This function checks if a number can be placed in a specific position in the Sudoku grid
 * without violating the rules of Sudoku, which are:
 * (1) The number should not appear more than once in the same row.
 * (2) The number should not appear more than once in the same column.
 * (3) The number should not appear more than once in the same 3x3 box.
 * 
 * @param sudoku The Sudoku grid.
 * @param row The row index of the position.
 * @param col The column index of the position.
 * @param num The number to be placed.
 * @return True if the number can be placed in the position, false otherwise.
 */
bool isValid(int sudoku[][SUDOKU_SIZE], int row, int col, int num) {
    // Validity in the Current Row
    for(int i = 0; i < SUDOKU_SIZE; i++) {
        if(sudoku[row][i] == num) return false;
    }

    // Validity in the Current Column
    for(int i = 0; i < SUDOKU_SIZE; i++) {
        if(sudoku[i][col] == num) return false;
    }

    // Validity in the Current Box
    int boxRow = floor(row / 3) * 3, boxCol = floor(col / 3) * 3;
    for(int i = boxRow; i < boxRow + 3; i++) {
        for(int j = boxCol; j < boxCol + 3; j++) {
            if(sudoku[i][j] == num) return false;
        }
    }

    return true;
}

/**
 * @brief Checks if the Sudoku grid has any empty cells.
 * 
 * This function checks if the Sudoku grid has any empty cells, i.e., cells with the value EMPTY_CELL.
 * 
 * @param sudoku The Sudoku grid.
 * @return True if the grid has empty cells, false otherwise.
 */
bool hasEmptyCell(int sudoku[][SUDOKU_SIZE]) {
    for(int i = 0; i < SUDOKU_SIZE; i++) {
        for(int j = 0; j < SUDOKU_SIZE; j++) {
            if(sudoku[i][j] == EMPTY_CELL) return true;
        }
    }

    return false;
}

/**
 * @brief Fills the Sudoku grid recursively.
 * 
 * This function fills the Sudoku grid recursively by placing numbers in empty cells.
 * It uses backtracking to find a valid solution for the Sudoku grid.
 * 
 * @param sudoku The Sudoku grid.
 * @return True if the grid is successfully filled, false otherwise.
 */
bool fillGrid(int sudoku[][SUDOKU_SIZE]) {
    int row, col;
    for(int i = 0; i < SUDOKU_SIZE * SUDOKU_SIZE; i++) {
        row = floor(i / SUDOKU_SIZE);
        col = i % SUDOKU_SIZE;

        if(sudoku[row][col] == EMPTY_CELL) {
            // Referred To Stackoverflow (Random Number Generation In C++) : https://stackoverflow.com/questions/13445688/how-to-generate-a-random-number-in-c
            unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
            std::shuffle(value.begin(), value.end(), std::default_random_engine(seed));

            for(int j = 0; j < SUDOKU_SIZE; j++) {
                if(isValid(sudoku, row, col, value[j])) {
                    sudoku[row][col] = value[j];
                    if(!hasEmptyCell(sudoku) || fillGrid(sudoku)) return true;
                }
            }
            break;
        }
    }
    sudoku[row][col] = EMPTY_CELL;

    return false;
}