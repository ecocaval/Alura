/**
 * @brief
    teste.c -- created in 30/07/2022 (brazil)
*/

#include <stdio.h>
#include <stdbool.h>
#include "simple_guess_game.h"

#define NUMBER_OF_TRIES 3

int secret_number = 0;
int secret_number_user_guess = 0;

unsigned int tries_counter = 0;
unsigned int tries_left;

void main()
{
    print_game_header();
    while(tries_counter < NUMBER_OF_TRIES)
    {
        tries_counter++;

        request_user_guess();

        if(secret_number_user_guess == secret_number || tries_counter == NUMBER_OF_TRIES) 
        {
           printf("\n Ending guessing game... \n");
           break;
        }
    }
}

void print_mark()
{
    printf("\n*******************************\n");
}

void print_game_header()
{
    print_mark();
    printf("*Welcome to our guessing game!");
    print_mark();
}

void request_user_guess()
{
    printf("\n What's your guess? ");
    scanf("%d", &secret_number_user_guess);

    bool guess_is_right = (secret_number_user_guess == secret_number);

    bool guess_is_higher = (secret_number_user_guess > secret_number);

    if(guess_is_right)
    {
        printf("\n Your guess is right! \n");
    }
    else
    {
        printf("\n Your guess is wrong! \n");
        if(guess_is_higher)
        {
            tries_left = (NUMBER_OF_TRIES - tries_counter);
            printf("\n Your guess is higher than secret number! \n");
            printf("\n You have %d tries left! \n", tries_left);
        }
        else
        {
            printf("\n Your guess is lower than secret number! \n");
        }
    }
    print_mark();
}