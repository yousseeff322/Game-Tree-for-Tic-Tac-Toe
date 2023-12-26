# Tic-Tac-Toe Game in C

This program implements a simple command-line version of the Tic-Tac-Toe game in C language. The game allows two players to take turns marking spaces on a 3x3 grid until one of them wins or the game ends in a tie.

## Features

- Supports two players, 'X' and 'O'.
- Displays the game board in the console.
- Determines the winner or declares a tie.

## How to Play

1. **Compile the Program:** Use a C compiler to compile the code, e.g., `gcc -o tic_tac_toe tic_tac_toe.c`.

2. **Run the Program:** Execute the compiled program, e.g., `./tic_tac_toe`.

3. **Gameplay:** Players take turns entering the row and column numbers (0-2) to place their marker ('X' or 'O') on the board.

    Example:
    ```
    Enter row and column (0-2) separated by space: 1 1
    ```

4. **Winning Condition:** The game checks for a winner after each move. The first player to create a row, column, or diagonal of their markers wins.

5. **End of Game:** The game continues until one player wins or the entire board is filled, resulting in a tie.


