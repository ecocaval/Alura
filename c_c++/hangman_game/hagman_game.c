#include <stdio.h>
#include <stdbool.h>

#define SECRET_WORD_SIZE 20

bool get_right;
bool get_hanged;

char secret_word[SECRET_WORD_SIZE];

char user_guess;

void main()
{
    sprintf(secret_word, "melancia");

    print_game_header();
    
    while(!get_right && !get_hanged)
    {   

    }
}

void print_mark()
{
    printf("\n***************************\n");
}

void print_game_header()
{
    print_mark();
    printf("*Welcome to our hangman game!");
    print_mark();
}