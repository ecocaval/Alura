/**
 * @brief
    hangman_game.c -- created in 30/07/2022 (brazil)
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "hangman_game.h"

#define SECRET_WORD_MAX_SIZE 20

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "abobora"
#define ALPHABET_SIZE 26

int underline_counter;
int number_of_guesses = 0;

int get_right;
int get_hanged;

int mistakes = 0;
int found_word;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char guesses[ALPHABET_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE * 2];

void main()
{
    game_header();

    generate_secret_word();

    while(!get_right && !get_hanged)
    {   
        get_user_guess();

        compare_guess_secret_word();
        
        check_stop_condition();
    }
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

    if(number_of_guesses < ALPHABET_SIZE - 1) 
    {
        guesses[number_of_guesses] = user_guess;
    }
}

void compare_guess_secret_word()
{
    for(int counter = 0; counter < strlen(secret_word); counter++)
    {
        if(secret_word[counter] == user_guess)
        {
            word_displayed[counter*2] = user_guess;
            underline_counter--;
        }
    }
    printf("%s\n", word_displayed);
    print_mark();

    number_of_guesses++;

    printf("\nYou had %d guesses!\n", number_of_guesses);

     // printf("%s\n", guesses);
}

void check_stop_condition()
{
    if(underline_counter == 0) 
    {
        get_right = true;
        printf("\nYou won the game!\n");
        printf("\n");
    }
    if(check_if_hanged()) get_hanged = true;
}

int check_if_hanged()
{
    if(number_of_guesses != 1)
    {
        for(int guess_counter = 0; guess_counter < number_of_guesses; guess_counter++)
        {
            found_word = false; 

            for(int letter_counter = 0; letter_counter < strlen(secret_word); letter_counter++)
            {   
                if(guesses[guess_counter] == secret_word[letter_counter]) 
                {
                    found_word = true;
                    break;
                }
            }

            // printf("%d", found_word);
            
            if(!found_word) 
            {
                mistakes++;
            }
        }
    }

    // printf("\n %d \n", mistakes);
    return(mistakes > 10);
}

