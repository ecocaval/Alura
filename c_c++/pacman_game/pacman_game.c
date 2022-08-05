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

GAME game_1;
POSITION pacman;
POSITION ghost;

void main()
{
    scan_game_map(&game_1);
    // printf("%d %d\n", game_total_rows, game_total_columns);

    set_game_map(&game_1);  

    do
    {
        get_user_command(&game_1, &pacman);
        move_ghosts(&game_1, &ghost);

        update_game_map(&game_1); 

    } 
    while(1);
    //while (!game_is_over());

    free_game_map(&game_1);
}

void get_user_command(GAME* map, POSITION* char_position)
{
    char user_command;

    user_command = getch();
        
    move_pacman(map, char_position, user_command);
}

void move_pacman(GAME* map, POSITION* char_position, char direction)
{
    char_position -> x_position = 0;
    char_position -> y_position = 0;
    
    find_in_game_map(map, char_position, PACMAN_CHAR, FIND_FIRST);

    set_move_direction(map, char_position, direction);
}

void find_in_game_map(GAME* map, POSITION* char_position, 
                      char finding_char, char position_to_find)
{
    for(int i = 0; i < map -> total_rows; i++)
    {
        for(int j = 0; j < map -> total_columns; j++)
        {
            if(map -> map[i][j] == finding_char)
            {
                char_position -> y_position = i;
                char_position -> x_position = j;
                if(position_to_find == FIND_FIRST) 
                {
                    return;
                }
            }    
        }
    }
}

void set_move_direction(GAME* map, POSITION* char_position, char direction)
{
    switch (direction)
    {
        case MOVE_UP:
            if(map -> map[char_position -> y_position - 1][char_position -> x_position] == MOVING_SPACE)
            {
                map -> map[char_position -> y_position - 1][char_position -> x_position] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> y_position--;
            }
            break;
        
        case MOVE_DOWN:
            if(map -> map[char_position -> y_position + 1][char_position -> x_position] == MOVING_SPACE)
            {
                map -> map[char_position -> y_position + 1][char_position -> x_position] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> y_position++;
            }
            break;
        
        case MOVE_RIGHT:
            if(map -> map[char_position -> y_position][char_position -> x_position + 1] == MOVING_SPACE)
            {
                map -> map[char_position -> y_position][char_position -> x_position + 1] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> x_position++;
            }
            break;

        case MOVE_LEFT:
            if(map -> map[char_position -> y_position][char_position -> x_position - 1] == MOVING_SPACE)
            {
                map -> map[char_position -> y_position][char_position -> x_position - 1] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> x_position--;
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
    return 0;
}

void move_ghosts(GAME* map, POSITION* char_position)
{
    find_in_game_map(map, char_position, GHOST_CHAR, FIND_FIRST);

    if(map->map[char_position -> y_position][char_position -> x_position - 1]  == MOVING_SPACE)
    {
        map->map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
        map->map[char_position -> y_position][char_position -> x_position - 1] = GHOST_CHAR;
    }

    find_in_game_map(map, char_position, GHOST_CHAR, FIND_LAST);

    if(map->map[char_position -> y_position][char_position -> x_position - 1]  == MOVING_SPACE)
    {
        map->map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
        map->map[char_position -> y_position][char_position -> x_position - 1] = GHOST_CHAR;
    }
}
