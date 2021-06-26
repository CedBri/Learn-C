#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "pendu.h"




int main(int argc, char * argv[])
{
    char letter = 0;
    char secretWord[] = "MARRON";
    int lettersFound[6] = {0,0,0,0,0,0};
    int guessesLeft = 10;
    int i = 0;
    
    // Greet
    printf("Welcome to CedBri's Hangman!\n\n");

    while(guessesLeft > 0 && !won(lettersFound)){
        printf("\n\nYou have %d guesses left.", guessesLeft);
        printf("\nWhat's the secret word?");

        // Mask the letters
        for (i = 0; i < 6; i++){
            if (lettersFound[i]){
                printf("%c", secretWord[i]);
            } else {
                printf("*");
            }
        }

       printf("\nGuess a letter: ");
       letter = readChar();
        // If not the right letter
       if (!searchLetter(letter, secretWord, lettersFound)){
           guessesLeft--;
       }
    }

    if(won(lettersFound)){
        printf("\n\nYou won! The word was indeed: %s", secretWord);
    } else {
        printf("\n\nYou lost! The secret word was: %s", secretWord);
    }
    return 0;
}

