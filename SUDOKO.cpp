#include <iostream>
using namespace std;

const int SIZE = 9;


void printGrid(int grid[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; row++) {
        for (int col = 0; col < SIZE; col++) {
            cout << grid[row][col] << " ";
        }
        cout << endl;
    }
}


bool isSafe(int grid[SIZE][SIZE], int row, int col, int num) {
    
    for (int x = 0; x < SIZE; x++) {
        if (grid[row][x] == num || grid[x][col] == num)
            return false;
    }

    
    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (grid[i + startRow][j + startCol] == num)
                return false;

    return true;
}


bool solveSudoku(int grid[SIZE][SIZE]) {
    int row, col;
    bool empty = false;

    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (grid[row][col] == 0) {
                empty = true;
                break;
            }
        }
        if (empty) break;
    }

    if (!empty)
        return true; 

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;

            if (solveSudoku(grid))
                return true;

            grid[row][col] = 0; 
        }
    }
    return false;
}

int main() {
    int grid[SIZE][SIZE];

    cout << "Enter Sudoku puzzle (use 0 for empty cells):" << endl;
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            cin >> grid[i][j];

    cout << "\nSolving Sudoku...\n\n";

    if (solveSudoku(grid)) {
        cout << "Solved Sudoku Grid:\n";
        printGrid(grid);
    } else {
        cout << "No solution exists!" << endl;
    }

    return 0;
}

