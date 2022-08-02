#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SECRET_WORD_MAX_SIZE 20

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "randomm"
#define ALPHABET_SIZE 26

unsigned short underline_counter;
unsigned short number_of_tries = 0;

unsigned short get_right;
unsigned short get_hanged;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char guesses[ALPHABET_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE * 2];

int repeated_guess()
{
    unsigned short letter_repeated = 0;

    for(int counter = 0; counter < number_of_tries; counter++)
    {
        if(guesses[counter] == guesses[number_of_tries]) 
        {
            letter_repeated = 1;
            printf("\nGuess is repeated!\n");

            (number_of_tries)--;
            break;
        }
    }
    return letter_repeated;
}

void print_mark()
{
    printf("\n******************************\n");
}

void game_header()
{
    print_mark();
    printf("*Welcome to our hangman game!*");
    print_mark();
}

void generate_secret_word()
{
    sprintf(secret_word, SECRET_WORD);
    
    underline_counter = strlen(secret_word);

    for(unsigned short counter = 0; counter < strlen(secret_word); counter++)
    {
        word_displayed[counter * 2] = UNDERLINE_SPACE;
        word_displayed[counter * 2 + 1] = BLANK_SPACE;
    }   
}

void get_user_guess()
{
    printf("\nPlease enter your guess: ");
    scanf(" %c", &user_guess); // space between %c to avoid "enter key" on buffer;

    if(number_of_tries < ALPHABET_SIZE - 1) guesses[number_of_tries] = user_guess;
}

void compare_guess_secret_word()
{
    for(unsigned short counter = 0; counter < strlen(secret_word); counter++)
    {
        if(secret_word[counter] == user_guess)
        {
            word_displayed[counter*2] = user_guess;
            if(!repeated_guess()) underline_counter--;
        }
    }
    printf("%s\n", word_displayed);
    print_mark();

    number_of_tries++;

    printf("\nYou had %d guesses!\n", number_of_tries);
}

void check_stop_condition()
{
    if(underline_counter == 0) 
    {
        get_right = true;
        printf("\nYou won the game!\n");
        printf("\n");
    }
    if(number_of_tries == 10)
    {
        get_hanged = true;
        printf("\nYou lost the game!");
        printf("\nThere was %d letter(s) left!\n", underline_counter);
        printf("\n");
    }
}

void main()
{
    game_header();

    generate_secret_word();

    while(!get_right && !get_hanged)
    {   
        get_user_guess();

        compare_guess_secret_word();

        printf("%s\n", guesses);
        printf("%d\n", underline_counter);
        
        check_stop_condition();
    }
}