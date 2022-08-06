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
GAME original_map_copy;
POSITION pacman;
POSITION ghost;

void main()
{
    unsigned int game_is_over = 0;
    unsigned int got_pill = 0;

    char user_command;
    char previous_user_command;

    scan_game_map(&game_1);
    scan_game_map(&original_map_copy);
    // printf("%d %d\n", game_total_rows, game_total_columns);

    set_game_map(&game_1);  
    copy_original_map(&game_1, &original_map_copy);

    do
    {
        get_user_command(&game_1, &original_map_copy,&pacman, &user_command, previous_user_command);
        move_ghost(&game_1, &ghost, FIND_FIRST);
        move_ghost(&game_1, &ghost, FIND_LAST);
        update_game_map(&game_1); 

        previous_user_command = user_command;
    } 
    while(!game_is_over);

    free_game_map(&game_1);
    free_game_map(&original_map_copy);
}

void get_user_command(GAME* map, GAME* original_map_copy, POSITION* char_position, char* user_command, char previous_user_command)
{
    *user_command = getch();
        
    move_pacman(map, original_map_copy, char_position, *user_command, previous_user_command);
}

void move_pacman(GAME* map, GAME* original_map_copy, POSITION* char_position, char direction, char previous_user_command)
{
    char_position -> x_position = 0;
    char_position -> y_position = 0;
    
    find_in_game_map(map, char_position, PACMAN_CHAR, FIND_FIRST);

    set_move_direction(map, original_map_copy, char_position, direction, previous_user_command);
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

void set_move_direction(GAME* map, GAME* original_map_copy, POSITION* char_position, char direction, char previous_user_command)
{
    switch (direction)
    {
        case MOVE_UP:
            if(map -> map[char_position -> y_position - 1][char_position -> x_position] == MOVING_SPACE ||
               map -> map[char_position -> y_position - 1][char_position -> x_position] == PILL_CHAR)
            {
                map -> map[char_position -> y_position - 1][char_position -> x_position] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> y_position--;
            }
            break;
        
        case MOVE_DOWN:
            if(map -> map[char_position -> y_position + 1][char_position -> x_position] == MOVING_SPACE ||
               map -> map[char_position -> y_position + 1][char_position -> x_position] == PILL_CHAR)
            {
                map -> map[char_position -> y_position + 1][char_position -> x_position] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> y_position++;
            }
            break;
        
        case MOVE_RIGHT:
            if(map -> map[char_position -> y_position][char_position -> x_position + 1] == MOVING_SPACE ||
               map -> map[char_position -> y_position][char_position -> x_position + 1] == PILL_CHAR)
            {
                map -> map[char_position -> y_position][char_position -> x_position + 1] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> x_position++;
            }
            break;

        case MOVE_LEFT:
            if(map -> map[char_position -> y_position][char_position -> x_position - 1] == MOVING_SPACE ||
               map -> map[char_position -> y_position][char_position -> x_position - 1] == PILL_CHAR)
            {
                map -> map[char_position -> y_position][char_position -> x_position - 1] = PACMAN_CHAR;
                map -> map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                char_position -> x_position--;
            }
            break;

        case EXPLODE_PILL:
            switch (previous_user_command)
            {
            case MOVE_UP:
                for(unsigned int i = 1; i < EXPLOSION_RANGE; i++)
                {
                    if(map -> map[char_position -> y_position - i][char_position -> x_position] == GHOST_CHAR)
                    {
                        map -> map[char_position -> y_position - i][char_position -> x_position] = MOVING_SPACE;
                        break;
                    }
                }
                break;
            
            case MOVE_DOWN:
                for(unsigned int i = 1; i < EXPLOSION_RANGE; i++)
                {
                    if(map -> map[char_position -> y_position + i][char_position -> x_position] == GHOST_CHAR)
                    {
                        map -> map[char_position -> y_position + i][char_position -> x_position] = MOVING_SPACE;
                        break;
                    }
                }
                break;
            
            case MOVE_RIGHT:
                for(unsigned int i = 1; i < EXPLOSION_RANGE; i++)
                {
                    if(map -> map[char_position -> y_position][char_position -> x_position + i] == GHOST_CHAR)
                    {
                        map -> map[char_position -> y_position][char_position -> x_position + i] = MOVING_SPACE;
                        break;
                    }
                }
                break;
            
            case MOVE_LEFT:
                for(unsigned int i = 1; i < EXPLOSION_RANGE; i++)
                {
                    if(map -> map[char_position -> y_position][char_position -> x_position - i] == GHOST_CHAR)
                    {
                        map -> map[char_position -> y_position][char_position -> x_position - i] = MOVING_SPACE;
                        break;
                    }
                }
                break;
            }
            break;

        case EXIT_BUTTON:
            exit(1);    
        
        default:
            printf("\nYour move is not valid please press (w/a/s/d)!\n");
            break;
    }
}

void define_random_direction(unsigned int* direction_selector, char define_ghost)
{
    if(define_ghost == FIND_FIRST)
    {
        *direction_selector = generate_random_number() % NUMBER_OF_DIRECTIONS;
    }
    else
    {
        *direction_selector = 7 * generate_random_number() % NUMBER_OF_DIRECTIONS;
    }
}

void move_ghost(GAME* map, POSITION* char_position, char define_ghost)
{
    unsigned int direction_selector;
    unsigned int next_position_is_valid = 0;
    unsigned int number_of_random_tries = 0;

    define_random_direction(&direction_selector, define_ghost);

    switch (direction_selector)
    {
        case RANDOM_UP:
            find_in_game_map(map, char_position, GHOST_CHAR, define_ghost);
            while(!next_position_is_valid && number_of_random_tries < MAX_NUMBER_OF_RANDOM_TRIES)
            {
                if(map->map[char_position -> y_position - 1][char_position -> x_position]  == MOVING_SPACE)
                {
                    map->map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                    map->map[char_position -> y_position - 1][char_position -> x_position] = GHOST_CHAR;
                    next_position_is_valid++;
                }
                number_of_random_tries++;
            }
            break;
        
        case RANDOM_DOWN:
            find_in_game_map(map, char_position, GHOST_CHAR, define_ghost);
            while(!next_position_is_valid && number_of_random_tries < MAX_NUMBER_OF_RANDOM_TRIES)
            {
                if(map->map[char_position -> y_position + 1][char_position -> x_position]  == MOVING_SPACE)
                {
                    map->map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                    map->map[char_position -> y_position + 1][char_position -> x_position] = GHOST_CHAR;
                    next_position_is_valid++;
                }
                number_of_random_tries++;
            }
            break;
            
        case RANDOM_RIGHT:
            find_in_game_map(map, char_position, GHOST_CHAR, define_ghost);
            while(!next_position_is_valid && number_of_random_tries < MAX_NUMBER_OF_RANDOM_TRIES)
            {
                if(map->map[char_position -> y_position][char_position -> x_position + 1]  == MOVING_SPACE)
                {
                    map->map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                    map->map[char_position -> y_position][char_position -> x_position + 1] = GHOST_CHAR;
                    next_position_is_valid++;
                }
                number_of_random_tries++;
            }
            break;
            
        case RANDOM_LEFT:
            find_in_game_map(map, char_position, GHOST_CHAR, define_ghost);
            while(!next_position_is_valid && number_of_random_tries < MAX_NUMBER_OF_RANDOM_TRIES)
            {
                if(map->map[char_position -> y_position][char_position -> x_position - 1]  == MOVING_SPACE)
                {
                    map->map[char_position -> y_position][char_position -> x_position] = MOVING_SPACE;
                    map->map[char_position -> y_position][char_position -> x_position - 1] = GHOST_CHAR;
                    next_position_is_valid++;
                }
                number_of_random_tries++;
            }
            break;
    }
}

int generate_random_number()
{
    srand(time(0));
    return rand();
}