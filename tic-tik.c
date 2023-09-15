#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Enum for game states
typedef enum {
    CONTINUE, WIN, DRAW
} GameState;

typedef struct {
    char name[50];
    char symbol;
} Player;

// Function declarations
void displayBoard(const char *board);
void displayRules();
GameState checkForWin(const char *board);
bool decideSymbols(Player *player1, Player *player2);

int main() {
    char board[9] = {'1','2','3','4','5','6','7','8','9'};
    Player players[2];
    int currentPlayerIndex = 0;

    displayRules();

    printf("\nEnter name of player1: ");
    scanf("%s", players[0].name);

    printf("Enter name of player2: ");
    scanf("%s", players[1].name);

    while (strcmp(players[0].name, players[1].name) == 0) {
        printf("Enter names of different players!\n\n");
        printf("\nEnter name of player1: ");
        scanf("%s", players[0].name);
        printf("Enter name of player2: ");
        scanf("%s", players[1].name);
    }

    decideSymbols(&players[0], &players[1]);

    displayBoard(board);

    GameState state;
    do {
        printf("%s, select a position (1-9): ", players[currentPlayerIndex].name);
        int choice;
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 9 && board[choice - 1] == '0' + choice) {
            board[choice - 1] = players[currentPlayerIndex].symbol;
        } else {
            printf("Invalid choice! Try again.\n");
            continue;
        }

        displayBoard(board);
        state = checkForWin(board);
        currentPlayerIndex = 1 - currentPlayerIndex; // Toggle between 0 and 1

    } while (state == CONTINUE);

    if (state == WIN) {
        printf("\n%s Wins!\n", players[1 - currentPlayerIndex].name);
    } else {
        printf("\nIt's a Draw!\n");
    }

    return 0;
}

void displayBoard(const char *board) {
    system("clear"); // Use 'cls' for Windows
    printf("\tTic-Tac-Toe\n\n");
    for (int i = 0; i < 9; i += 3) {
        printf("  %c |  %c | %c\n", board[i], board[i+1], board[i+2]);
        if (i < 6) printf("----|----|----\n");
    }
}

void displayRules() {
    printf("\tTic-Tac-Toe\n\n");
    printf("Welcome to the game of Tic-Tac-Toe!\n");
    printf("\nRules:\n");
    printf("1. Each player selects a position from 1 to 9.\n");
    printf("2. The aim is to get three of your symbols in a row - horizontally, vertically, or diagonally.\n");
    printf("Enjoy!\n");
}

GameState checkForWin(const char *board) {
    int winningCombinations[8][3] = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8},
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8},
        {0, 4, 8}, {2, 4, 6}
    };

    for (int i = 0; i < 8; i++) {
        if (board[winningCombinations[i][0]] == board[winningCombinations[i][1]] &&
            board[winningCombinations[i][1]] == board[winningCombinations[i][2]]) {
            return WIN;
        }
    }

    for (int i = 0; i < 9; i++) {
        if (board[i] != 'X' && board[i] != 'O') {
            return CONTINUE;
        }
    }

    return DRAW;
}

bool decideSymbols(Player *player1, Player *player2) {
    char symbol;
    do {
        printf("%s, choose X or O: ", player1->name);
        scanf(" %c", &symbol);
    } while (symbol != 'X' && symbol != 'O');

    player1->symbol = symbol;
    player2->symbol = (symbol == 'X') ? 'O' : 'X';

    return true;
}
