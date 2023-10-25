#include <iostream>
#include <vector>

using namespace std;

bool isSafe(vector<vector<int>>& board, int row, int col, int n) {
    // Check the row on the left side
    for (int i = 0; i < col; i++) {
        if (board[row][i] == 1) {
            return false;
        }
    }

    // Check upper diagonal on the left side
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    // Check lower diagonal on the left side
    for (int i = row, j = col; i < n && j >= 0; i++, j--) {
        if (board[i][j] == 1) {
            return false;
        }
    }

    return true;
}

bool solveNQueensUtil(vector<vector<int>>& board, int col, int n) {
    if (col == n) {
        // All queens are placed
        return true;
    }

    for (int i = 0; i < n; i++) {
        if (isSafe(board, i, col, n)) {
            board[i][col] = 1;

            if (solveNQueensUtil(board, col + 1, n)) {
                return true;
            }

            board[i][col] = 0; // Backtrack
        }
    }

    return false;
}

void printBoard(vector<vector<int>>& board, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int n;
    cout << "Enter the value of n (the size of the N-Queens board): ";
    cin >> n;

    vector<vector<int>> board(n, vector<int>(n, 0));

    int row_for_first_queen;
    cout << "Enter the row index (0-based) for the first queen: ";
    cin >> row_for_first_queen;

    if (row_for_first_queen < 0 || row_for_first_queen >= n) {
        cout << "Invalid starting position for the first queen." << endl;
        return 1;
    }

    // Place the first queen in the specified row
    board[row_for_first_queen][0] = 1;

    if (solveNQueensUtil(board, 1, n)) {
        cout << "Solution found:" << endl;
        printBoard(board, n);
    } else {
        cout << "No solution exists." << endl;
    }

    return 0;
}

