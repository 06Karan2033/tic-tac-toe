#include <iostream>
#include <vector>

using namespace std;

const int SIZE = 3;
char board[SIZE][SIZE] = { ' ' };

void printBoard() {
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            cout << board[i][j];
            if (j < SIZE - 1) cout << " | ";
        }
        cout << endl;
        if (i < SIZE - 1) {
            for (int j = 0; j < SIZE; j++) {
                cout << "---";
                if (j < SIZE - 1) cout << "+";
            }
            cout << endl;
        }
    }
    cout << endl;
}

bool isBoardFull() {
    for (int i = 0; i < SIZE; i++)
        for (int j = 0; j < SIZE; j++)
            if (board[i][j] == ' ')
                return false;
    return true;
}

bool checkWin(char player) {
    // Check rows
    for (int i = 0; i < SIZE; i++)
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player)
            return true;
    
    // Check columns
    for (int i = 0; i < SIZE; i++)
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player)
            return true;
    
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player)
        return true;
    
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player)
        return true;
    
    return false;
}

void makeMove(char player) {
    int row, col;
    while (true) {
        cout << "Player " << player << ", enter row and column (0-2): ";
        cin >> row >> col;
        if (row >= 0 && row < SIZE && col >= 0 && col < SIZE && board[row][col] == ' ') {
            board[row][col] = player;
            break;
        } else {
            cout << "Invalid move. Try again." << endl;
        }
    }
}

int main() {
    char currentPlayer = 'X';
    
    while (true) {
        printBoard();
        makeMove(currentPlayer);
        
        if (checkWin(currentPlayer)) {
            printBoard();
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        }
        
        if (isBoardFull()) {
            printBoard();
            cout << "It's a draw!" << endl;
            break;
        }
        
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
    
    return 0;
}
