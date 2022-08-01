/**
 * @brief
    teste.c -- created in 30/07/2022 (brazil)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "simple_guess_game.h"

#define NUMBER_OF_TRIES 10
#define GUESS_INTERVAL 100
#define TOTAL_POINTS 1000

float total_points = TOTAL_POINTS;

int random_number;

short secret_number;
short secret_number_user_guess = 0;
short tries_counter = 1;

bool guess_is_right;
bool guess_is_higher;

void main()
{
    generate_secret_number();

    print_game_header();

    while(1)
    {
        request_user_guess();

        if(check_negative_guess()) continue;

        check_guess();

        if(check_stop_condition()) break;

        tries_counter++;
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
    printf("\n Try number %d of %d \n", tries_counter, NUMBER_OF_TRIES);

    printf("\n What's your guess? ");
    scanf("%d", &secret_number_user_guess);
}

void check_guess()
{
    guess_is_right = secret_number_user_guess == secret_number;
    guess_is_higher = secret_number_user_guess > secret_number;
    
    if(guess_is_right)
    {
        printf("\n Your guess is right! \n");
    }
    else
    {
        printf("\n Your guess is wrong! \n");

        if(guess_is_higher)
        {
            printf("\n Your guess is higher than secret number! \n");
        }
        else
        {
            printf("\n Your guess is lower than secret number! \n");
        }

        total_points -= (double)abs(secret_number_user_guess - secret_number)/2;
    }

    print_mark();
}

void generate_secret_number()
{
    int seconds_ref = time(0);
    srand(seconds_ref);
    random_number = rand();

    secret_number = random_number % GUESS_INTERVAL;
}

bool check_stop_condition()
{
    if(tries_counter == NUMBER_OF_TRIES) 
    {
        printf("\n You've lost, secret number was %d! \n", secret_number);
        printf("\n Ending guessing game... \n");

        return true;
    }
    if(secret_number_user_guess == secret_number) 
    {
        printf("\n You won with a total of %.1f points! \n", total_points);
        printf("\n Ending guessing game... \n");

        return true;
    }
    return false;
}

bool check_negative_guess()
{
    if(secret_number_user_guess < 0)
    {
        tries_counter--;

        printf("\n Negative numbers are not allowed! \n");
        print_mark();

        return true;
    }
    return false;
}