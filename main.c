#include<stdio.h>
#include<stdbool.h>

bool haveTheSameValueAndNotEmpty(char x, char y, char z) {
    if(x == y && x == z && x != ' ') {
        return true;
    }
    return false;
}

int checkWinner(char board[3][3]) {
    //  2: X winner
    // -2: O winner
    //  0: Tie
    //  1: No winner

    // For rows
    for(int i = 0; i < 3; i++) {
        if(haveTheSameValueAndNotEmpty(board[i][0], board[i][1], board[i][2])) {
            return board[i][0] == 'X' ? 2 : -2;
        }
    }

    // For cols
    for(int i = 0; i < 3; i++) {
        if(haveTheSameValueAndNotEmpty(board[0][i], board[1][i], board[2][i])) {
            return board[0][i] == 'X' ? 2 : -2;
        }
    }

    // Diameter 1
    if(haveTheSameValueAndNotEmpty(board[0][0], board[1][1], board[2][2])) {
        return board[0][0] == 'X' ? 2 : -2;
    }

    // Diameter 2
    if(haveTheSameValueAndNotEmpty(board[2][0], board[1][1], board[0][2])) {
        return board[2][0] == 'X' ? 2 : -2;
    }

    // For Tie Case
    bool tie = true;
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            if(board[i][j] == ' ') {
                tie = false;
            }
        }
    }
    if(tie) return 0;

    // Else
    return 1;
}

void drawBoard(char board[3][3]) {
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 3; j++) {
            printf("| %c |", board[i][j]);
        }
        printf("\n -------------- \n");
    }
}

int minimax(char board[3][3], int depth, bool isMaximizing, bool firstTime) {
    int result = checkWinner(board);
    if(depth == 0 || result != 1) {
        return result;
    }

    if(isMaximizing) {
        int finalScore = -10;
        int finalI, finalJ;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'X';
                    int score = minimax(board, depth - 1, false, false);
                    board[i][j] = ' ';
                    if(score > finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                    if(firstTime) {
                        printf("score,%d,%d: %d\n", i, j, score);
                    }
                }
            }
        }
        if(firstTime) {
            board[finalI][finalJ] = 'O';
        }
        return finalScore;
    } else {
        int finalScore = 10;
        int finalI, finalJ;
        for(int i = 0; i < 3; i++) {
            for(int j = 0; j < 3; j++) {
                if(board[i][j] == ' ') {
                    board[i][j] = 'O';
                    int score = minimax(board, depth - 1, true, false);
                    board[i][j] = ' ';
                    if(score < finalScore) {
                        finalScore = score;
                        finalI = i;
                        finalJ = j;
                    }
                    if(firstTime) {
                        printf("score,%d,%d: %d\n", i, j, score);
                    }
                }
            }
        }
        if(firstTime) {
            board[finalI][finalJ] = 'O';
        }
        return finalScore;
    }
}

int main() {
    char board[3][3] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
    int x, y; // 0, 1, 2
    bool has_winner = false;
    char player = 'X';

    while(!has_winner) {
        printf("Enter row and column (0-2) separated by space: ");
        scanf("%d %d", &x, &y);

        // Check if the input indices are within the valid range (0, 1, 2)
        if (x >= 0 && x <= 2 && y >= 0 && y <= 2) {
            if(board[x][y] == ' ') {
                board[x][y] = player;
                int result = minimax(board, 100, false, true);
                drawBoard(board);
                printf("result: %d\n", result);
                has_winner = checkWinner(board) != 1;
            } else {
                printf("The field is not empty\n");
            }
        } else {
            printf("Invalid input. Please enter indices between 0 and 2.\n");
        }
    }

    int result = checkWinner(board);
    if(result == 0) {
        printf("Tie\n");
    } else {
        printf("%s player wins\n", result == 2 ? "X" : "O");
    }
    return 0;
}
