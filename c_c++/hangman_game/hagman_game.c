#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SECRET_WORD_MAX_SIZE 20

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "random"
#define ALPHABET_SIZE 26

unsigned short underline_counter;
unsigned short number_of_guesses = 0;

unsigned short get_right;
unsigned short get_hanged;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char guesses[ALPHABET_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE * 2];

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

    if(number_of_guesses < ALPHABET_SIZE - 1) guesses[number_of_guesses] = user_guess;
}

void compare_guess_secret_word()
{
    for(unsigned short counter = 0; counter < strlen(secret_word); counter++)
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
    int mistakes = 0;
    int found_word = 0;

    if(number_of_guesses != 1)
    {
        for(int i = 0; i < number_of_guesses; i++)
        {
            found_word = 0; 

            for(int j = 0; j < strlen(secret_word); j++)
            {   
                if(guesses[i] == secret_word[j]) 
                {
                    found_word = 1;
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
