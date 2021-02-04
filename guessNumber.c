//
// Created by Aditi Rajnish on 2020-08-21.
// Guess a random number within a given range within 5 tries.
//

#include <stdio.h>
#include <stdlib.h>
#include <time.h> // for random number generator seed

#define MIN 0
#define MAX 20

int guessNumber(){

    // initialize user's random number, user's guess,
    // maximum number of tries and current number of tries (initially equal
    // to maximum number of tries; decrements in line 39 in game loop)
    int randomNum = 0, guess = 0, maxTries = 5, currentTries = maxTries;

    // generate random number that user must guess correctly;
    // is in min and max range (inclusive), uses rand() function
    time_t t;
    srand((unsigned) time(&t));
    randomNum = (rand() % (MAX - MIN + 1)) + MIN;

    // game introduction
    printf("This is a guessing game.\n");
    printf("I have chosen a number between %d and %d, which you must guess.\n\n", MIN, MAX);

    // game loop runs if user has not run out of tries
    while(currentTries){

        // display number of tries remaining; ternary operator for try/tries
        printf("You have %d tr%s left.\n", currentTries, currentTries == 1 ? "y" : "ies");

        // user enters guess; tries counter decrements
        printf("Enter a guess: ");
        scanf("%d", &guess);
        currentTries--;

        // correct guess displays congratulatory message,
        // w/ number of tries used (ternary for try/tries),
        // and terminates program
        if(guess == randomNum){
            printf("\nCongratulations! You guessed it in %d tr%s.\n", maxTries - currentTries, currentTries == (maxTries - 1) ? "y" : "ies");
            return 0;
        }

        // if user runs out of tries (0 tries left),
        // correct answer is displayed and program terminates
        if(!currentTries){
            printf("\nSorry, you ran out of guesses. The correct answer was %d.\n", randomNum);
            return 0;
        }

        // if user still has 1 or more tries left,
        // game displays whether the user's guess was
        // out of range or too high or too low, then repeats loop
        if (guess > MAX || guess < MIN) {
            printf("You must enter a number between %d and %d.\n\n", MIN, MAX);
        }
        else{
            printf("Sorry, %d is wrong. My number is %s than that.\n\n", guess, guess > randomNum ? "less" : "more");
        }
    }
}