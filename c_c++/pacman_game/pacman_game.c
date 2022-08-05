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

void main()
{
    scan_game_map(&game_1);
    // printf("%d %d\n", game_total_rows, game_total_columns);

    set_game_map(&game_1);  

    do
    {
        get_user_command(&pacman);
        update_game_map(&game_1); 
    } 
    while(1);
    //while (!game_is_over());

    free_game_map(&game_1);
}

void get_user_command(POSITION* char_position)
{
    char user_command;

    user_command = getch();
        
    move_pacman(user_command, &game_1, char_position);
}

void move_pacman(char direction, GAME* map, POSITION* char_position)
{
    char_position->x_position = 0;
    char_position->y_position = 0;
    
    find_in_game_map(map, char_position, PACMAN_CHAR);

    set_move_direction(direction, char_position);
}

void find_in_game_map(GAME* map, POSITION* char_position, char finding_char)
{
    for(int i = 0; i < map->total_rows; i++)
    {
        for(int j = 0; j < map->total_columns; j++)
        {
            if(map->map[i][j] == finding_char)
            {
                char_position->y_position = i;
                char_position->x_position = j;
            }
        }
    }
}

void set_move_direction(char direction, POSITION* char_position)
{
    switch (direction)
    {
        case MOVE_UP:
            if(game_1.map[char_position->y_position - 1][char_position->x_position] == MOVING_SPACE)
            {
                game_1.map[char_position->y_position - 1][char_position->x_position] = PACMAN_CHAR;
                game_1.map[char_position->y_position][char_position->x_position] = MOVING_SPACE;
                char_position->y_position--;
            }
            break;
        
        case MOVE_DOWN:
            if(game_1.map[char_position->y_position + 1][char_position->x_position] == MOVING_SPACE)
            {
                game_1.map[char_position->y_position + 1][char_position->x_position] = PACMAN_CHAR;
                game_1.map[char_position->y_position][char_position->x_position] = MOVING_SPACE;
                char_position->y_position++;
            }
            break;
        
        case MOVE_RIGHT:
            if(game_1.map[char_position->y_position][char_position->x_position + 1] == MOVING_SPACE)
            {
                game_1.map[char_position->y_position][char_position->x_position + 1] = PACMAN_CHAR;
                game_1.map[char_position->y_position][char_position->x_position] = MOVING_SPACE;
                char_position->x_position++;
            }
            break;

        case MOVE_LEFT:
            if(game_1.map[char_position->y_position][char_position->x_position - 1] == MOVING_SPACE)
            {
                game_1.map[char_position->y_position][char_position->x_position - 1] = PACMAN_CHAR;
                game_1.map[char_position->y_position][char_position->x_position] = MOVING_SPACE;
                char_position->x_position--;
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
