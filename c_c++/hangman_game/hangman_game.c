/**
 * @brief
    hangman_game.c -- created in 30/07/2022 (brazil)
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "hangman_game.h"

#define SECRET_WORD_MAX_SIZE 46 /*
                                    biggest brazilian word has 46 letters according to
                                    the brazilian dictionary, the word is:
                                    pneumoultramicroscopicossilicovulcanoconiótico
                                */

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define ALPHABET_SIZE 26

int words_left;
int number_of_guesses = 0;

int get_right;
int get_hanged;

int guess_is_right;

int mistakes = 0;
int found_word;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char guesses[ALPHABET_SIZE];
char found_word_string[ALPHABET_SIZE];
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
    FILE* ptr_words_list;

    int random_selector, words_in_list_counter;

    ptr_words_list = fopen("words/brazilian_words.txt", "r"); /*
                                                                opens words data bank in read mode,
                                                                one variable must receive it and 
                                                                must be FILE pointer type;
                                                              */
                                                          
    if(ptr_words_list == NULL) // checks if the file was opened
    {
        printf("\nWords list file was not opened sucessfully!\n");
        exit(1);
    }
    else
    {
        fscanf(ptr_words_list, "%d", &words_in_list_counter);

        random_selector = generate_random_number() % words_in_list_counter; /*
                                                                              creates a selector that goes from 0 
                                                                              to the number of words in list bank
                                                                            */
        for(int i = 0; i <= random_selector; i++)
        {
            fscanf(ptr_words_list, "%s", secret_word);
        }

        fclose(ptr_words_list); // closing the word_bank file we opened before
        
        words_left = strlen(secret_word);

        for(int counter = 0; counter < strlen(secret_word); counter++)
        {
            word_displayed[counter * 2] = UNDERLINE_SPACE;
            word_displayed[counter * 2 + 1] = BLANK_SPACE;
        }   
    }
}

int generate_random_number()
{
    srand(time(0));
    return rand();
}

void get_user_guess()
{
    printf("\n%s\n", word_displayed);

    printf("\nPlease enter your guess: ");
    scanf(" %c", &user_guess); // space between %c to avoid "enter key" on buffer;

    if(number_of_guesses < ALPHABET_SIZE - 1 && !check_repeated_guess()) 
    {
        guesses[number_of_guesses] = user_guess;
    }

    print_mark();
}

int check_repeated_guess()
{
    for(int guess_counter = 0; guess_counter < number_of_guesses; guess_counter++)
    {
        if(user_guess == guesses[guess_counter])
        {
            return 1;
        }
    }
    return 0;
}

void compare_guess_secret_word()
{
    int aux_guess = 0;

    for(int counter = 0; counter < strlen(secret_word); counter++)
    {
        if(secret_word[counter] == user_guess)
        {
            word_displayed[counter*2] = user_guess;

            aux_guess = 1;

            if(!check_repeated_guess()) words_left--;
        }
        
        switch (aux_guess)
        {
        case (1):
            guess_is_right = 1;
            if(!check_repeated_guess()) 
            {
                found_word_string[number_of_guesses] = 'Y';
            }
            break;
        
        case (0):
            guess_is_right = 0;
            if(!check_repeated_guess()) 
            {
                found_word_string[number_of_guesses] = 'N';
            }
            break;
        }
    }

    printf("\nGuesses string:             %s\n", guesses);
}

int check_if_hanged()
{
    if(number_of_guesses != 1)
    {
        printf("Found guess in secret word: %s", found_word_string);
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

            if(!found_word && !guess_is_right && !check_repeated_guess()) 
            {
                mistakes++;
                break;
            }
        }
    }
    else
    {
        found_word = false; 

        for(int letter_counter = 0; letter_counter < strlen(secret_word); letter_counter++)
        {   
            if(user_guess == secret_word[letter_counter]) found_word = true;
        }

        printf("Found guess in secret word: %s", found_word_string);

        if(!found_word) mistakes++;
    }

    printf("\nMistakes: %d\n", mistakes);
    return(mistakes == 10);
}

void check_stop_condition()
{

    if(words_left == 0) 
    {
        get_right = true;
        
        printf("\n%s\n", word_displayed);
        printf("\nYou won the game!\n");
        printf("\n");
    }
    else if(check_if_hanged()) 
    {
        get_hanged = true;
         
        printf("\n%s\n", word_displayed);
        printf("\nYou lost the game!\n");
        printf("\nSecret word was: %s\n", secret_word);
        printf("\n");
    }

    if(!check_repeated_guess()) number_of_guesses++;

    printf("\nGuesses: %d\n", number_of_guesses);
}
