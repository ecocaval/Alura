#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SECRET_WORD_MAX_SIZE 20

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "fodasse"

unsigned short underline_counter;

bool get_right;
bool get_hanged;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE * 2];

void main()
{
    print_game_header();

    get_secret_word();

    while(!get_right && !get_hanged)
    {   
        get_user_guess();

        compare_guess_to_secret_word();

        printf("%s\n", word_displayed);
        print_mark();

        check_stop_condition();
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

void get_secret_word()
{
    sprintf(secret_word, SECRET_WORD);
    
    underline_counter = strlen(secret_word);

    for(int counter = 0; counter < strlen(secret_word); counter++)
    {
        word_displayed[counter * 2] = UNDERLINE_SPACE;
        word_displayed[counter * 2 + 1] = BLANK_SPACE;
    }   
}

void get_user_guess()
{
    printf("\n Please enter your guess: ");
    scanf(" %c", &user_guess); // space between %c to avoid "enter key" on buffer;
}

void compare_guess_to_secret_word()
{
    for(int counter = 0; counter < strlen(secret_word); counter++)
    {
        if(secret_word[counter] == user_guess)
        {
            word_displayed[counter*2] = user_guess;
            underline_counter--;
        }
    }
}

void check_stop_condition()
{
    if(underline_counter == 0) get_right = true;
}