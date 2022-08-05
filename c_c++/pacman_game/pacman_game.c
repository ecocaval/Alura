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
PACMAN pacman_1;

void main()
{
    scan_game_map(&game_1);
    // printf("%d %d\n", game_total_rows, game_total_columns);

    set_game_map(&game_1);  

    do
    {
        get_user_command(&pacman_1);
        update_game_map(&game_1); 
    } 
    while(1);
    //while (!game_is_over());

    free_game_map(&game_1);
}

void get_user_command(PACMAN* pacman)
{
    char user_command;

    user_command = getch();
        
    move_pacman(user_command, &game_1, &pacman_1);
}

void move_pacman(char direction, GAME* map, PACMAN* pacman)
{
    pacman->x_position = 0;
    pacman->y_position = 0;
    
    find_in_game_map(map, pacman, PACMAN_CHAR);

    set_move_direction(direction, pacman);
}

void find_in_game_map(GAME* map, PACMAN* pacman, char finding_char)
{
    for(int i = 0; i < map->total_rows; i++)
    {
        for(int j = 0; j < map->total_columns; j++)
        {
            if(map->map[i][j] == finding_char)
            {
                pacman->y_position = i;
                pacman->x_position = j;
            }
        }
    }
    printf("\nX position %d ---- Y position %d\n\n", pacman->x_position + 1, pacman->y_position + 1);
}

void set_move_direction(char direction, PACMAN* pacman)
{
    unsigned int direction_aux;
    unsigned int i = 0;

    switch (direction)
    {
    case MOVE_UP:
        if(game_1.map[pacman->y_position - 1][pacman->x_position] == MOVING_SPACE)
        {
            printf("\nYou moved up!\n");
            game_1.map[pacman->y_position - 1][pacman->x_position] = PACMAN_CHAR;
            game_1.map[pacman->y_position][pacman->x_position] = MOVING_SPACE;
            pacman->y_position--;
        }
        break;
    
    case MOVE_DOWN:
        if(game_1.map[pacman->y_position + 1][pacman->x_position] == MOVING_SPACE)
        {
            printf("\nYou moved down!\n");
            game_1.map[pacman->y_position + 1][pacman->x_position] = PACMAN_CHAR;
            game_1.map[pacman->y_position][pacman->x_position] = MOVING_SPACE;
            pacman->y_position++;
        }
        break;
    
    case MOVE_RIGHT:
        if(game_1.map[pacman->y_position][pacman->x_position + 1] == MOVING_SPACE)
        {
            printf("\nYou moved right!\n");
            game_1.map[pacman->y_position][pacman->x_position + 1] = PACMAN_CHAR;
            game_1.map[pacman->y_position][pacman->x_position] = MOVING_SPACE;
            pacman->x_position++;
        }
        break;

    case MOVE_LEFT:
        if(game_1.map[pacman->y_position][pacman->x_position - 1] == MOVING_SPACE)
        {
            printf("\nYou moved left!\n");
            game_1.map[pacman->y_position][pacman->x_position - 1] = PACMAN_CHAR;
            game_1.map[pacman->y_position][pacman->x_position] = MOVING_SPACE;
            pacman->x_position--;
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
