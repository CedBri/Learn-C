#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <ctype.h>

int searchLetter(char letter, char secretWord[], int letterFound[])
{
    int i = 0;
    int goodLetter = 0;

    // Check each letter if good
    for (i = 0; secretWord[i] != '\0'; i++){
        if (letter == secretWord[i]){
            goodLetter = 1;
            letterFound[i] = 1;
        }
    }

    return goodLetter;
}

int won(int letterFound[])
{
    int i = 0;
    int playerWon = 1;

    for (i = 0; i < 6; i++){
        if (letterFound[i] == 0){
            playerWon = 0;
        }
    }
    return playerWon;
}
char readChar()
{
    char letter = 0;

    letter = getchar();
    letter = toupper(letter);

    while (getchar() != '\n');

    return letter;
}

int randomIndex(arrayLength)
{
    srand(time(NULL));
    return (rand()) % arrayLength;
}
