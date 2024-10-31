#include <iostream>
#include <vector>

#define N 9

bool isSafe(int grid[N][N], int row, int col, int num) {
    for (int x = 0; x < N; x++) {
        if (grid[row][x] == num || grid[x][col] == num) {
            return false;
        }
    }

    int startRow = row - row % 3, startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

bool solveSudoku(int grid[N][N]) {
    int row = -1, col = -1;
    bool isEmpty = true;
    for (int i = 0; i < N && isEmpty; i++) {
        for (int j = 0; j < N && isEmpty; j++) {
            if (grid[i][j] == 0) {
                row = i;
                col = j;
                isEmpty = false;
            }
        }
    }

    if (isEmpty) {
        return true; // Solved
    }

    for (int num = 1; num <= 9; num++) {
        if (isSafe(grid, row, col, num)) {
            grid[row][col] = num;
            if (solveSudoku(grid)) {
                return true;
            }
            grid[row][col] = 0; // Backtracking
        }
    }

    return false; // Trigger backtracking
}

void printGrid(int grid[N][N]) {
    for (int r = 0; r < N; r++) {
        for (int d = 0; d < N; d++) {
            std::cout << grid[r][d] << " ";
        }
        std::cout << std::endl;
    }
}