//
// Created by Aditi Rajnish on 2020-08-24.
// Run a Tic-Tac-Toe game.
//

#include <stdio.h>

// initialized game board; numbers are placeholders
// which the players will replace with X's and O's
char board[9] = {'1', '2', '3',
                 '4', '5', '6',
                 '7', '8', '9'};

/*******************************
Displays game board; loops through characters; uses global variable for board;
does not return anything, does not take any arguments
*******************************/
void drawBoard(void){
    printf("\n\t\t ");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            printf("%c   ", board[j + i * 3]);
        }
        printf("\n\t\t ");
    }
}

/*******************************
Modifies the game board; replaces a placeholder with the player's symbol;
does not return anything; takes player number and position given by user as arguments
*******************************/
void changeBoard(int position, int player){
    char symbol;
    if(player == 1){
        symbol = 'X';
    }
    else{
        symbol = 'O';
    }
    board[position] = symbol;
}

/*******************************
Checks if user's inputted position is valid, meaning the position
does not already contain an 'X' or 'O' and that the position exists in
the array (between 1 and 9); returns a Boolean indicating whether
the position is valid or not; takes position given by user as an argument
*******************************/
_Bool validatePosition(int position){
    _Bool valid = 1;
    if(board[position] == 'X' || board[position] == 'O' || position > 8 || position < 0){
        valid = 0;
    }
    return valid;
}
/*******************************
Asks user to input a position, which is used as an index in the game board array;
returns the position (index in array) and takes the player number as an argument
*******************************/
int getPosition(int player){
    int position;
    printf("\nPlayer %d, please enter your position: ", player);
    scanf("%d", &position);
    return position - 1;
}

/*******************************
Loops through game board to check if all 3 characters
in a row, column, or diagonal are identical; returns a Boolean
indicating whether there is a winner; takes no arguments
*******************************/
_Bool checkWin(void){
    _Bool winner = 0;
    for(int i = 0; i < 3; i++){
        char rowOne = board[i], rowTwo = board[i + 3], rowThree = board[i + 6];
        if(rowOne == rowTwo && rowTwo == rowThree){
            winner = 1;
        }
        char columnOne = board[i * 3], columnTwo = board[i * 3 + 1], columnThree = board[i * 3 + 2];
        if(columnOne == columnTwo && columnTwo == columnThree){
            winner = 1;
        }
    }
    if(board[0] == board[4] && board[4] == board[8]){
        winner = 1;
    }
    if(board[2] == board[4] && board[4] == board[6]){
        winner = 1;
    }
    return winner;
}
/*******************************
Calculates the player number, 1 or 2, depending on the turn;
odd-numbered turn is for player 1, even-numbered turn is for player 2;
returns player number and takes the turn number as an argument
*******************************/
int getPlayerNumber(int turn){
    int player;
    if(turn % 2){
        player = 1;
    }
    else{
        player = 2;
    }
    return player;
}

int ticTacToe(){

    // main game loop runs for 9 turns
    for(int turn = 1; turn <= 9; turn++){
        printf("\t\tTic Tac Toe\nPlayer 1: X\t\tPlayer 2: O\n");
        drawBoard();

        int player = getPlayerNumber(turn);

        if(checkWin()){
            int winningPlayer = (player == 1 ? 2 : 1);
            printf("\n\t  Player %d has won!\n", winningPlayer);
            return 0; // display winner and end program
        }

        // if there is not a winner, get input from user and validate
        int position = getPosition(player);
        _Bool valid = validatePosition(position);
        while(!valid){ // user is continuously prompted to enter a valid position
            printf("Invalid position. Please try again.\n");
            position = getPosition(player);
            valid = validatePosition(position);
        }

        // if given a valid position, board is changed and game loop repeats
        changeBoard(position, player);
        printf("\n\n\n");
    }

    // if loop ends without a winner, the game was a draw and the program ends
    printf("\n\t  There was a draw!\n");

    return 0;
}