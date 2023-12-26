#include "fill_grid.h"

std::array<int, 9> value {1, 2, 3, 4, 5, 6, 7, 8, 9}; 

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

bool hasEmptyCell(int sudoku[][SUDOKU_SIZE]) {
    for(int i = 0; i < SUDOKU_SIZE; i++) {
        for(int j = 0; j < SUDOKU_SIZE; j++) {
            if(sudoku[i][j] == EMPTY_CELL) return true;
        }
    }

    return false;
}

bool fillGrid(int sudoku[][SUDOKU_SIZE]) {
    int row, col;
    for(int i = 0; i < SUDOKU_SIZE * SUDOKU_SIZE; i++) {
        // WHY THE FUCK NOT USE NORMAL ITERATOR??
        // DON'T ASK ME, I'M HIGH RN
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