#include "SudokuBoard.h"
#include <iostream>
#include <random>


using namespace std;

SudokuBoard::SudokuBoard()
{
    generateRandomBoard();
}


// Function to print the Sudoku board
void SudokuBoard::printBoard()
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            std::cout << gameBoard[i][j] << " ";

            if ((((j + 1) % 3) == 0) && (j != 8))
            {
                cout << "| ";
            }
        }
        std::cout << std::endl;
        if ((((i + 1) % 3) == 0) && (i != 8))
        {
            cout << "------+-------+------" << endl;
        }
    }

}




// Function to generate a random Sudoku board
void SudokuBoard::generateRandomBoard()
{
    // Initialize the board with zeros
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            gameBoard[i][j] = 0;
        }
    }

    // Code from Chat gpt. 
    random_device rd;
    mt19937 gen(rd()); // Mersenne Twister generator

    // Range: 1 to SIZE this is used to build the board. It can be changed to change initial board difficulty.
    uniform_int_distribution<> distDistance(1, 5);

    // Range: 1 to SIZE this needs to be valid sudoku numbers.
    uniform_int_distribution<> distSpaceNum(1, SIZE);

    int curentSpace = 0;
    int row = 0;
    int col = 0;
    int spaceNum = 0;
    int spacesToNextNum = distDistance(gen) - 1;

    do
    {
        col += spacesToNextNum;

        // Move to next row if at end of row.
        if (col >= 9)
        {
            col -= 9;
            row++;
        }

        // Generate a random number and try to stick it in.
        int fillTryCount = 0;
        bool isValid = false;

        do
        {
            // Generate number between 1 and 9 to fill that space .
            spaceNum = distSpaceNum(gen);

            // Avoid infinite loop.
            fillTryCount++;

            isValid = validateMove(row, col, spaceNum);

        } while (!(isValid) && fillTryCount < 100);

        if (fillTryCount >= 100)
        {
            //cout << row << " " << col << " " << spaceNum << endl;
            spaceNum = 0;
        }

        gameBoard[row][col] = spaceNum;

        // Generate a random number to find next space.
        spacesToNextNum = distDistance(gen);

        // Keep total count of how many spaces we pass.
        curentSpace += spacesToNextNum;

    } while (curentSpace < 81);



}

// Function to validate a move in a Sudoku board
// Returns True if valid, False if invalid.
bool SudokuBoard::validateMove(int row, int col, int num)
{

    // See if valid row and column.
    if (row >= SIZE || col >= SIZE)
    {
        //cout << "ConditionZero: Invalid Row or Column\n";
        //cout << row << " " << col << endl;
        return false;
    }

    // See if spot is open.
    if (gameBoard[row][col] != 0)
    {
        //cout << "ConditionZero: Spot not open\n";
        //cout << row << col << "\n";
        printBoard();

        return false;
    }

    // See if number is already in row or col.
    for (int i = 0; i < SIZE - 1; i++)
    {
        // Check if number is in row.
        if (gameBoard[row][i] == num)
        {
            //cout << "ConditionOne: Number in Row\n";
            //cout << row << " " << col << " " << num << endl;
            return false;
        }

        // Check if number is in col.
        if (gameBoard[i][col] == num)
        {
            //cout << "ConditionTwo: Number in Column\n";
            return false;
        }
    }

    // Check if the number is already present in the same 3x3 block.
    // Performs intiger division then multiplies it up to the start of the block.
    int startRowBlock = (row / 3) * 3;
    int startColBlock = (col / 3) * 3;

    for (int i = startRowBlock; i < startRowBlock + 3; i++)
    {
        for (int j = startColBlock; j < startColBlock + 3; j++)
        {
            if (gameBoard[i][j] == num)
            {
                //cout << "ConditionThree:Number in Box\n";
                return false;
            }
        }
    }

    // The move is valid
    //cout << "ConditionFour:NoError\n";
    return true;
}