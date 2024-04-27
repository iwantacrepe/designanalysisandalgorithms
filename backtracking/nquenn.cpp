#include <iostream>

const int N = 4;

bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check the column
    for (i = 0; i < row; i++) {
        if (board[i][col] == 1)
            return false;
    }

    // Check upper left diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1)
            return false;
    }

    // Check upper right diagonal
    for (i = row, j = col; i >= 0 && j < N; i--, j++) {
        if (board[i][j] == 1)
            return false;
    }

    return true;
}

bool solveNQueensUtil(int board[N][N], int row) {
    if (row == N)
        return true;

    for (int col = 0; col < N; col++) {
        if (isSafe(board, row, col)) {
            board[row][col] = 1;
            if (solveNQueensUtil(board, row + 1))
                return true;
            board[row][col] = 0;  // backtrack
        }
    }
    return false;
}

void printBoard(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << "\n";
    }
}

int main() {
    int board[N][N] = {0};

    if (solveNQueensUtil(board, 0)) {
        std::cout << "Solution for 4x4 board:\n";
        printBoard(board);
    } else {
        std::cout << "No solution exists\n";
    }

    return 0;
}
