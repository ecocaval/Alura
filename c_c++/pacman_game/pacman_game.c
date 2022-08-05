/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include <time.h>

#include "pacman_game.h"
#include "maps/game_map.h"

void main()
{
    scan_game_map(game_1);
    // printf("%d %d\n", game_total_rows, game_total_columns);

    set_game_map(game_1);  

    do
    {
        get_user_command();
        update_game_map(game_1.total_rows); 
    } 
    while(1);
    //while (!game_is_over());

    free_game_map(game_1.total_rows);
}

void get_user_command()
{
    char user_command;

    user_command = getch();
        
    move_pacman(user_command);
}

int check_if_row_repeat(char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS])
{
    unsigned int right_words_counter = 0;

    for(unsigned int i = 0; i < game_1.total_columns; i++)
    {
        if(past_map_analyser[i] == map_analyser[i]) right_words_counter++;   
    }

    if(game_1.total_columns == right_words_counter)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void move_pacman(char direction)
{
    unsigned int pacman_y_position = 0;
    unsigned int pacman_x_position = 0;
    
    find_pacman(&pacman_y_position, &pacman_x_position);

    set_move_direction(direction, &pacman_y_position, &pacman_x_position);
}

void find_pacman(unsigned int* pacman_y_position, unsigned int* pacman_x_position)
{
    for(int i = 0; i < game_1.total_rows; i++)
    {
        for(int j = 0; j < game_1.total_columns; j++)
        {
            if(game_1.map[i][j] == PACMAN_CHAR)
            {
                *pacman_y_position = i;
                *pacman_x_position = j;
            }
        }
    }
    printf("\nX position %d ---- Y position %d\n\n", *pacman_x_position + 1, *pacman_y_position + 1);
}

void set_move_direction(char direction, unsigned int* pacman_y_position, unsigned int* pacman_x_position)
{
    unsigned int direction_aux;
    unsigned int i = 0;

    switch (direction)
    {
    case MOVE_UP:
        if(game_1.map[*pacman_y_position - 1][*pacman_x_position] == MOVING_SPACE)
        {
            printf("\nYou moved up!\n");
            game_1.map[*pacman_y_position - 1][*pacman_x_position] = PACMAN_CHAR;
            game_1.map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_y_position--;
        }
        break;
    
    case MOVE_DOWN:
        if(game_1.map[*pacman_y_position + 1][*pacman_x_position] == MOVING_SPACE)
        {
            printf("\nYou moved down!\n");
            game_1.map[*pacman_y_position + 1][*pacman_x_position] = PACMAN_CHAR;
            game_1.map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_y_position++;
        }
        break;
    
    case MOVE_RIGHT:
        if(game_1.map[*pacman_y_position][*pacman_x_position + 1] == MOVING_SPACE)
        {
            printf("\nYou moved right!\n");
            game_1.map[*pacman_y_position][*pacman_x_position + 1] = PACMAN_CHAR;
            game_1.map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_x_position++;
        }
        break;

    case MOVE_LEFT:
        if(game_1.map[*pacman_y_position][*pacman_x_position - 1] == MOVING_SPACE)
        {
            printf("\nYou moved left!\n");
            game_1.map[*pacman_y_position][*pacman_x_position - 1] = PACMAN_CHAR;
            game_1.map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_x_position--;
        }
        break;

    case EXIT_BUTTON:
        exit(1);    
    
    default:
        printf("\nYour move is not valid please press (w/a/s/d)!\n");
        break;
    }
}

int game_is_over()
{
    if(0) // game is over condition 
    {

        return 1;
    }   
    else
    {

        return 0;
    }
}
