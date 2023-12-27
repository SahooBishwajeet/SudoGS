#include "tui.h"

/**
 * @brief Gets the user's choice for the desired action.
 * 
 * This function displays a menu to the user and waits for their input.
 * The user can choose to generate a Sudoku, solve a Sudoku, or exit the program.
 * The function validates the user's input and repeats the menu until a valid choice is made.
 * 
 * @return The user's choice as an integer.
 */
int getChoice() {
    int choice;

    while(TRUE) {
        clear();
        printw("What Do You Want To Do?\n\n[1] Generate Sudoku\n[2] Solve Sudoku\n[3] Exit\n\n");
        refresh();
        
        scanw("%d", &choice);

        if(choice == 1 || choice == 2 || choice == 3) break;
        
        printw("Invalid Choice, Try Again\n");
        refresh();
        napms(1000);
    }
    return choice;
}

/**
 * @brief Prompts the user to enter a difficulty level for generating a Sudoku puzzle.
 * 
 * @return The difficulty level entered by the user (an integer between 1 and 5).
 */
int getDifficulty() {
    int difficulty;

    while(TRUE) {
        clear();
        printw("Enter Difficulty: [1-5] : ");
        refresh();
        
        scanw("%d", &difficulty);

        if(difficulty >= 1 && difficulty <= 5) {
            clear();
            printw("Generating Sudoku... ");
            refresh();
            napms(1000);
            break;
        }
        else {
            printw("Invalid Difficulty, Try Again\n");
            refresh();
            napms(1000);
        }
    }
    return difficulty;
}

/**
 * Displays the solution of the Sudoku puzzle.
 * 
 * @param sudoku The Sudoku puzzle grid.
 */
void displaySolution(int sudoku[][SUDOKU_SIZE]) {
    char dispAll;  

    while (TRUE) {
        clear();
        printw("<==============SOLUTION==============>\n");
        sudokuSolver(sudoku, false);

        // printw("Do You Want To Display All Solutions? [y/n] : ");
        // scanw("%c", &dispAll);

        // if(dispAll == 'y' || dispAll == 'Y') {
        //     clear();
        //     sudokuSolver(sudoku, true);

        //     printw("Press Any Key To Exit\n");
        //     getch();
        //     break;
        // }
        // else if(dispAll == 'n' || dispAll == 'N') {
        //     break;
        // }
        // else {
        //     printw("Invalid Choice, Try Again\n");
        //     napms(1000);
        // }
        printw("\nPress Any Key To Exit... ");
        getch();
        break;
    }
}