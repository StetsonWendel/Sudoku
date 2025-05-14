// Sudoko.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SudokuBoard.h"

int main() {
    // Generate a random Sudoku board
    SudokuBoard currentGame;

    // Print the initial board
    std::cout << "Initial board:" << std::endl;
    currentGame.printBoard();

    // Loop until the game is complete
    while (true)
    {
        // Prompt the user to enter a move
        std::cout << "Enter a row, column, and number (0 to quit): ";
        int row, col, num;
        std::cin >> row >> col >> num;

        // Check if the user wants to quit
        if (row == 0 || col == 0 || num == 0)
        {
            std::cout << "Game over." << std::endl;
            return 0;
        }

        // Validate the move
        if (currentGame.validateMove(row - 1, col - 1, num))
        {
            // Make the move
            currentGame.gameBoard[row - 1][col - 1] = num;

            // Check if the game is complete
            bool isComplete = true;

            for (int i = 0; i < SIZE; i++)
            {
                for (int j = 0; j < SIZE; j++)
                {
                    if (currentGame.gameBoard[i][j] == 0)
                    {
                        isComplete = false;
                    }
                }
            }

            if (isComplete)
            {
                std::cout << "Congratulations! You won!" << std::endl;
                return 0;
            }

        }
        else
        {
            std::cout << "Invalid move. Try again." << std::endl;
        }

        // Print the updated board
        std::cout << "Current board:" << std::endl;
        currentGame.printBoard();
    }

}

