#include <iostream>
#include <vector>
#include <string>

const int ROWS = 6;
const int COLS = 7;
const char EMPTY = '.';

bool checkWinner(const std::vector<std::vector<char>>& board, char player) {
    // Check horizontal
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == player &&
                board[row][col+1] == player &&
                board[row][col+2] == player &&
                board[row][col+3] == player) {
                return true;
            }
        }
    }

    // Check vertical
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == player &&
                board[row+1][col] == player &&
                board[row+2][col] == player &&
                board[row+3][col] == player) {
                return true;
            }
        }
    }

    // Check diagonal (top-left to bottom-right)
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 0; col <= COLS - 4; col++) {
            if (board[row][col] == player &&
                board[row+1][col+1] == player &&
                board[row+2][col+2] == player &&
                board[row+3][col+3] == player) {
                return true;
            }
        }
    }

    // Check diagonal (top-right to bottom-left)
    for (int row = 0; row <= ROWS - 4; row++) {
        for (int col = 3; col < COLS; col++) {
            if (board[row][col] == player &&
                board[row+1][col-1] == player &&
                board[row+2][col-2] == player &&
                board[row+3][col-3] == player) {
                return true;
            }
        }
    }

    return false;
}

std::string analyzeConnectFour(const std::vector<std::vector<char>>& board) {
    bool redWin = checkWinner(board, 'R');
    bool yellowWin = checkWinner(board, 'Y');

    if (redWin && yellowWin) {
        return "Undecidable";
    } else if (redWin) {
        return "Red wins";
    } else if (yellowWin) {
        return "Yellow wins";
    }

    // Check for draw
    bool isFull = true;
    for (int row = 0; row < ROWS; row++) {
        for (int col = 0; col < COLS; col++) {
            if (board[row][col] == EMPTY) {
                isFull = false;
                break;
            }
        }
        if (!isFull) break;
    }

    if (isFull) {
        return "Draw";
    } else {
        return "Undecidable";
    }
}

int main() {
    std::vector<std::vector<char>> gameBoard = {
        {'R', 'Y', 'R', 'Y', 'R', 'Y', 'R'},
        {'Y', 'R', 'Y', 'R', 'Y', 'R', 'Y'},
        {'R', 'Y', 'R', 'Y', 'R', 'Y', 'R'},
        {'Y', 'R', 'Y', 'R', 'Y', 'R', 'Y'},
        {'R', 'Y', 'R', 'Y', 'R', 'Y', 'R'},
        {'Y', 'R', 'Y', 'R', 'Y', 'R', 'Y'}
    };

    std::string result = analyzeConnectFour(gameBoard);
    std::cout << result << std::endl;

    return 0;
}