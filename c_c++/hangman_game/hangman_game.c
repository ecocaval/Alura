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

int not_guessed_words;
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

    add_word_to_list();
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
        fscanf(ptr_words_list, "%d", &words_in_list_counter); /* 
                                                                firts line from words data bank gives
                                                                us the total number of word in the list
                                                              */

        random_selector = generate_random_number() % words_in_list_counter; /*
                                                                              creates a selector that goes from 0 
                                                                              to the number of words in the list bank
                                                                            */
        for(int i = 0; i <= random_selector; i++)
        {
            fscanf(ptr_words_list, "%s", secret_word);
        }

        fclose(ptr_words_list); // closing the word_bank file we opened before
        
        not_guessed_words = strlen(secret_word);

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
    if(number_of_guesses != 0)
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
    else
    {
        return 0;
    }
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

            if(!check_repeated_guess()) not_guessed_words--;
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

    printf("\nWords guessed:              %s\n", guesses);
}

int check_if_hanged()
{
    printf("Found guess in secret word: %s", found_word_string);
    for(int guess_counter = 0; guess_counter <= number_of_guesses; guess_counter++)
    {
        found_word = 0; 

        for(int letter_counter = 0; letter_counter < strlen(secret_word); letter_counter++)
        {
            if(guesses[guess_counter] == secret_word[letter_counter]) 
                {
                found_word = 1;
                break;
            }
        }

        if(!found_word && !guess_is_right && !check_repeated_guess()) 
        {
            mistakes++;
            break;
        }
    }

    printf("\nMistakes: %d\n", mistakes);
    return(mistakes == 10);
}

void check_stop_condition()
{
    if(not_guessed_words == 0) 
    {
        get_right = true;
        
        printf("\n%s\n", word_displayed);
        printf("\nYou won the game!\n");
    }
    else if(check_if_hanged()) 
    {
        get_hanged = true;
         
        printf("\n%s\n", word_displayed);
        printf("\nYou lost the game!\n");
        printf("\nSecret word was: %s\n", secret_word);
    }

    if(!get_right && !get_hanged) 
    {
        if(!check_repeated_guess()) number_of_guesses++;
        printf("\nGuesses: %d\n", number_of_guesses);
    }
}

void add_word_to_list()
{
    char user_answer;

    print_mark();
    printf("\nWould you like to add a word to this game? (Y/N): ");

    while(user_answer != 'Y' && user_answer != 'N')
    {
        scanf(" %c", &user_answer);

        if(user_answer == 'Y')
        {
            char user_new_word[SECRET_WORD_MAX_SIZE];

            printf("\nWhat's the new word: ");
            scanf("%s", user_new_word);

            FILE* f_word_list;

            f_word_list = fopen("words/brazilian_words.txt", "r+"); /* 
                                                                        r+ gives us permission
                                                                        to read and write in 
                                                                        txt file
                                                                      */
            if(f_word_list == NULL)
            {
                printf("\nWords list file was not opened sucessfully!\n");
                exit(1);
            }
            else
            {  
                int words_in_list_counter;

                fscanf(f_word_list, "%d", &words_in_list_counter);
                words_in_list_counter++;

                fseek(f_word_list, 0, SEEK_SET); /* 
                                                     points seek to the first line
                                                     of word list .txt, this way we 
                                                     can overwrite the total number
                                                     of words in the file. 
                                                   */
                fprintf(f_word_list, "%d", words_in_list_counter);

                fseek(f_word_list, 0, SEEK_END);                
                fprintf(f_word_list, "\n%s", user_new_word);

                fclose(f_word_list);
            }                                                 
        }
        else if(user_answer == 'N')
        {   
            printf("\nEnding Hangman game, thank you for playing!\n");
            printf("\n");
        }
        else
        {
            printf("\nYour answer is not valid, please enter (Y/N): ");
        }
    }
}