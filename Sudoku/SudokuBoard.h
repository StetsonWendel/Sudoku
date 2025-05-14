#pragma once
#define SIZE 9

class SudokuBoard
{
public:

    SudokuBoard();
    void printBoard();
    /// <summary>
    /// Validates game move.
    /// True if valid move, False if invalid.
    /// </summary>
    /// <param name="row">int</param>
    /// <param name="col">int</param>
    /// <param name="num">int</param>
    /// <returns>bool</returns>
    bool validateMove(int row, int col, int num);

    int gameBoard[SIZE][SIZE] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

private:
    void generateRandomBoard();



};