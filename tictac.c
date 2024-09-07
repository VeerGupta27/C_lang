#include <stdio.h>

// Function declarations
void printBoard(char board[3][3]);
int checkWin(char board[3][3]);
int isFull(char board[3][3]);
void playMove(char board[3][3], int row, int col, char player);

// Main function
int main() {
    char board[3][3] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    
    int row, col;
    char currentPlayer = 'X';
    int winner = 0;
    int moves = 0;

    while (1) {
        printBoard(board);
        
        // Get player move
        printf("Player %c, enter row and column (0, 1, 2): ", currentPlayer);
        scanf("%d %d", &row, &col);

        // Check for valid move
        if (row < 0 || row > 2 || col < 0 || col > 2 || board[row][col] != ' ') {
            printf("Invalid move, try again.\n");
            continue;
        }

        // Make the move
        playMove(board, row, col, currentPlayer);
        moves++;

        // Check for a win
        winner = checkWin(board);
        if (winner != 0) {
            printBoard(board);
            printf("Player %c wins!\n", winner);
            break;
        }

        // Check for a draw
        if (isFull(board)) {
            printBoard(board);
            printf("The game is a draw.\n");
            break;
        }

        // Switch players
        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    return 0;
}

// Function to print the board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---|---|---\n");
    }
    printf("\n");
}

// Function to check if the board is full
int isFull(char board[3][3]) {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') return 0;
        }
    }
    return 1;
}

// Function to check for a win
int checkWin(char board[3][3]) {
    // Check rows and columns
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][0] != ' ') 
            return board[i][0];
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[0][i] != ' ') 
            return board[0][i];
    }

    // Check diagonals
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[0][0] != ' ') 
        return board[0][0];
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[0][2] != ' ') 
        return board[0][2];

    return 0;
}

// Function to make a move
void playMove(char board[3][3], int row, int col, char player) {
    board[row][col] = player;
}
