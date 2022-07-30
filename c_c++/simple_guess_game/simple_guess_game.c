/**
 * @brief
    teste.c -- created in 30/07/2022 (brazil)
*/

#include <stdio.h>
#include "simple_guess_game.h"

int secret_number;
int secret_number_user_guess;

void main()
{
    print_game_header();
    while(1)
    {
        request_user_guess();
        print_mark();
        if(secret_number_user_guess == secret_number) break;
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

    if(secret_number_user_guess == secret_number)
    {
        printf("\n Your guess is right! \n");
    }
    else
    {
        printf("\n Your guess is wrong! \n");
        if (secret_number_user_guess > secret_number)
        {
            printf("\n Your guess is higher than secret number! \n");
        }
        else
        {
            printf("\n Your guess is lower than secret number! \n");
        }
    }
}