This code is a C program that creates a command-line version of Tic-Tac-Toe for two players. 
The game may be played by two people taking turns until one of them wins or it results in a tie. 
The code constructs a game board, shows the game board and rules, accepts user input for player names and symbol selections ('X' or 'O'), and determines if a win or a draw has occurred. 
In order to maintain code organization and user-friendliness and to guarantee that players adhere to the game's regulations while engaging in a competitive game of Tic-Tac-Toe, it uses functions.

Validation and User Input:

- It asks the players to submit their names. Players are prompted to input alternate names if their names are the same.
- The next step asks players to select "X" or "O" as their symbols.

Loop of Game:

- The primary game loop continues until a winner (WIN) or a draw (DRAW) is reached.
- The current player is requested to choose a spot on the board during each loop iteration.
- The chosen position is verified, and if it is legitimate, the player's sign ('X' or 'O') is put on the board.
- Following each player's move, the board is shown, and the outcome of the game—a victory or a draw—is determined.
- To change players, toggle the currentPlayerIndex.




