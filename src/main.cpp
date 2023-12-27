#include <ncurses.h>

#include "cli.h"
#include "tui.h"
#include "print.h"
#include "sudoku_generator.h"
#include "sudoku_solver.h"

#define SUDOKU_SIZE 9
#define EMPTY_CELL 0

/**
 * @brief The main function of the program.
 * 
 * @param argc The number of command-line arguments.
 * @param argv An array of strings containing the command-line arguments.
 * @return int The exit status of the program.
 */
int main(int argc, const char **argv) {
    
    if(strcmp(argv[0], argv[argc - 1]) == 0) {
        initscr();
    }
    else {
        cli(argv);
        return 0;
    }

    while (TRUE) {
        int choice;
        int difficulty;
        char sol;
        int sudoku[SUDOKU_SIZE][SUDOKU_SIZE];
        choice = getChoice();

        if(choice == 1) {
            difficulty = getDifficulty();
            clear();
            generateSudoku(sudoku, difficulty);
            printw("<==============SOLVE THIS==============>\n");
            printSudoku(sudoku, true);

            napms(1000);
            printw("\nDo You Want To Display Solution? [y/n] : ");
            scanw("%c", &sol);

            if(sol == 'y' || sol == 'Y') {
                displaySolution(sudoku);
            }
            break;
        }
        else if(choice == 2) {
            clear();
            printw("Enter Sudoku:\n");
            refresh();
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[0][0], &sudoku[0][1], &sudoku[0][2], &sudoku[0][3], &sudoku[0][4], &sudoku[0][5], &sudoku[0][6], &sudoku[0][7], &sudoku[0][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[1][0], &sudoku[1][1], &sudoku[1][2], &sudoku[1][3], &sudoku[1][4], &sudoku[1][5], &sudoku[1][6], &sudoku[1][7], &sudoku[1][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[2][0], &sudoku[2][1], &sudoku[2][2], &sudoku[2][3], &sudoku[2][4], &sudoku[2][5], &sudoku[2][6], &sudoku[2][7], &sudoku[2][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[3][0], &sudoku[3][1], &sudoku[3][2], &sudoku[3][3], &sudoku[3][4], &sudoku[3][5], &sudoku[3][6], &sudoku[3][7], &sudoku[3][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[4][0], &sudoku[4][1], &sudoku[4][2], &sudoku[4][3], &sudoku[4][4], &sudoku[4][5], &sudoku[4][6], &sudoku[4][7], &sudoku[4][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[5][0], &sudoku[5][1], &sudoku[5][2], &sudoku[5][3], &sudoku[5][4], &sudoku[5][5], &sudoku[5][6], &sudoku[5][7], &sudoku[5][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[6][0], &sudoku[6][1], &sudoku[6][2], &sudoku[6][3], &sudoku[6][4], &sudoku[6][5], &sudoku[6][6], &sudoku[6][7], &sudoku[6][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[7][0], &sudoku[7][1], &sudoku[7][2], &sudoku[7][3], &sudoku[7][4], &sudoku[7][5], &sudoku[7][6], &sudoku[7][7], &sudoku[7][8]);
            scanw("%d %d %d %d %d %d %d %d %d", &sudoku[8][0], &sudoku[8][1], &sudoku[8][2], &sudoku[8][3], &sudoku[8][4], &sudoku[8][5], &sudoku[8][6], &sudoku[8][7], &sudoku[8][8]);
            printw("Solving Sudoku...\n");
            refresh();
            napms(1000);
            clear();
            printw("<===============SUDOKU===============>\n\n");
            printSudoku(sudoku, true);
            printw("\n<==============SOLUTION==============>\n\n");
            sudokuSolver(sudoku, false);

            printw("\nPress Any Key To Exit... ");
            getch();

            break;
        }
        else if(choice == 3) {
            break;
        }
    }
    endwin();

    return 0;
}