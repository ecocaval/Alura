#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define SECRET_WORD_MAX_SIZE 20
#define LETTERS_GUESSED_SIZE 26

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define SECRET_WORD "algum"

unsigned short underline_counter;
unsigned short number_of_tries = 0;

unsigned short get_right;
unsigned short get_hanged;

unsigned short  guess_is_repeated = 0;
unsigned short  repeat_aux = 0;

unsigned short *ptr_aux;

char user_guess;
char secret_word[SECRET_WORD_MAX_SIZE];
char letters_guessed[LETTERS_GUESSED_SIZE];
char word_displayed[SECRET_WORD_MAX_SIZE * 2];

void main()
{
    print_game_header();

    get_secret_word();

    while(!get_right && !get_hanged)
    {   
        get_user_guess();

        compare_guess_to_secret_word(&number_of_tries);

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

void compare_guess_to_secret_word(unsigned short* number_of_tries_aux)
{
    *number_of_tries_aux += 1;
    
    printf("\n%d\n", *number_of_tries_aux);
    
    ptr_aux = letters_guessed;

    for(int counter = 0; counter < strlen(secret_word); counter++)
    {
        if(!check_if_guess_repeated()) 
        {
            if(secret_word[counter] == user_guess)
            {
                word_displayed[counter*2] = user_guess;
                letters_guessed[*number_of_tries_aux] = user_guess;
                underline_counter--;
            }
        }
        else 
        {
            printf("\n Guess is repeated! \n");
            repeat_aux = 0;
        }
    }
}

void check_stop_condition()
{
    if(underline_counter == 0) 
    {
        get_right = true;
        printf("\n You won the game! \n");
    }
}

int check_if_guess_repeated()
{   
    for(unsigned short counter = 0; counter < LETTERS_GUESSED_SIZE; counter++)
    {
        ptr_aux = &letters_guessed[counter];

        if(*ptr_aux == user_guess) repeat_aux = 1;
    }

    if(repeat_aux) return 1;
    
    else 
    {   
        repeat_aux = 0;
        return 0;
    }
}   