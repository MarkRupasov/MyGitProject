#include <iostream>
#include <vector>

using namespace std;

class TicTacToe {
public:
    TicTacToe() : board(3, vector<char>(3, ' ')), currentPlayer('X') {}

    void play() {
        int row, col;
        while (true) {
            printBoard();
            cout << "Игрок " << currentPlayer << ", введите строку и столбец (0-2): ";
            cin >> row >> col;

            if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
                cout << "Некорректный ввод. Попробуйте снова." << endl;
                continue;
            }

            board[row][col] = currentPlayer;

            if (checkWin()) {
                printBoard();
                cout << "Игрок " << currentPlayer << " выиграл!" << endl;
                break;
            }

            if (isDraw()) {
                printBoard();
                cout << "Игра закончилась вничью!" << endl;
                break;
            }

            currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
        }
    }

private:
    vector<vector<char>> board;
    char currentPlayer;

    void printBoard() {
        cout << "Текущая доска:" << endl;
        for (const auto& row : board) {
            for (const auto& cell : row) {
                cout << cell << " ";
            }
            cout << endl;
        }
    }

    bool checkWin() {
        for (int i = 0; i < 3; ++i) {
            if ((board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer) ||
                (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)) {
                return true;
            }
        }
        return (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer) ||
               (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer);
    }

    bool isDraw() {
        for (const auto& row : board) {
            for (const auto& cell : row) {
                if (cell == ' ') return false;
            }
        }
        return true;
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}

