#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SECRET_WORD_MAX_SIZE 20

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "paredu"
#define ALPHABET_SIZE 26

unsigned short underline_counter;
unsigned short number_of_tries = 0;

unsigned short get_right;
unsigned short get_hanged;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char guesses[ALPHABET_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE * 2];

int repeated_guess(char guess_letter, char guesses_aux[ALPHABET_SIZE], int *number_of_tries_aux)
{
    int letter_repeated = 0;

    for(int counter = 0; counter < *number_of_tries_aux; counter++)
    {
        if(guesses_aux[counter] == guesses_aux[*number_of_tries_aux]) 
        {
            letter_repeated = 1;
            printf("\nGuess is repeated!\n");

            (*number_of_tries_aux)--;
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

    for(int counter = 0; counter < strlen(secret_word); counter++)
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

void compare_guess_secret_word(unsigned short* number_of_tries_aux)
{
    for(int counter = 0; counter < strlen(secret_word); counter++)
    {
        if(secret_word[counter] == user_guess)
        {
            word_displayed[counter*2] = user_guess;
            if(!repeated_guess(user_guess, guesses, &number_of_tries)) underline_counter--;
        }
    }
    printf("%s\n", word_displayed);
    print_mark();

    (*number_of_tries_aux)++;

    printf("\nYou had %d guesses!\n", *number_of_tries_aux);
}

void check_stop_condition()
{
    if(underline_counter == 0) 
    {
        get_right = true;
        printf("\nYou won the game!\n");
    }
    if(number_of_tries == 10)
    {
        get_hanged = true;
        printf("\nYou lost the game!\n");
    }
}

void main()
{
    game_header();

    generate_secret_word();

    while(!get_right && !get_hanged)
    {   
        get_user_guess();

        compare_guess_secret_word(&number_of_tries);
        
        // printf("%s", guesses);
        
        check_stop_condition();
    }
}