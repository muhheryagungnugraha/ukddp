#include <iostream>
#include <string>

void drawBoard(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << ' ';
        }
        std::cout << '\n';
    }
}

bool checkWin(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] != ' ' && board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            return true;
        }
        if (board[0][i] != ' ' && board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            return true;
        }
    }
    if (board[0][0] != ' ' && board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        return true;
    }
    if (board[0][2] != ' ' && board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        return true;
    }
    return false;
}

bool checkDraw(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                return false;
            }
        }
    }
    return true;
}

void gameLoop() {
    char board[3][3] = {{' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '}};
    char currentPlayer = 'X';
    while (true) {
        drawBoard(board);
        std::cout << "Giliran " << currentPlayer << ". Masukkan koordinat (1-3) di baris kemudian kolom (contoh: 12): ";
        int move;
        std::cin >> move;
        int row = (move / 10) - 1;
        int col = (move % 10) - 1;
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            std::cout << "Masukkan tidak valid!" << std::endl;
            continue;
        }
        board[row][col] = currentPlayer;
        if (checkWin(board)) {
            drawBoard(board);
            std::cout << "Selamat! Pemain " << currentPlayer << " menang!" << std::endl;
            break;
        }
        if (checkDraw(board)) {
            drawBoard(board);
            std::cout << "Permainan berakhir seri!" << std::endl;
            break;
        }
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }
}

int main() {
    std::cout << "Selamat datang di game Tic Tac Toe!" << std::endl;
    gameLoop();
    return 0;
}