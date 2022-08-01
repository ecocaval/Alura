#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SECRET_WORD_MAX_SIZE 20

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "amarelo"

unsigned short underline_counter;

bool get_right;
bool get_hanged;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE*2];
char *ptr_word_displayed;

void main()
{
    print_game_header();

    sprintf(secret_word, SECRET_WORD);

    underline_counter = strlen(secret_word);

    for (int counter = 0; counter < strlen(secret_word); counter++)
    {
        word_displayed[counter * 2] = UNDERLINE_SPACE;
        word_displayed[counter * 2 + 1] = BLANK_SPACE;
    }   

    while(!get_right && !get_hanged)
    {   
        printf("\n Please enter your guess: ");
        scanf(" %c", &user_guess); // space between %c to avoid "enter key" on buffer;

        for (int counter = 0; counter < strlen(secret_word); counter++)
        {
            if(secret_word[counter] == user_guess)
            {
                word_displayed[counter*2] = user_guess;
                underline_counter--;
            }
        }

        printf("%s\n", word_displayed);
        print_mark();

        if (underline_counter == 0) get_right = true;
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