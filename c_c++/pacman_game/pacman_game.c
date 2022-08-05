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

char** game_map;
char** last_round_game_map;

void main()
{
    char user_command;

    unsigned int game_total_rows, game_total_columns = 0;

    scan_game_map(&game_total_rows, &game_total_columns);
    // printf("%d %d\n", game_total_rows, game_total_columns);

    set_game_map(game_total_rows, game_total_columns);  

    do
    {
        user_command = getch();
        
        move_pacman(user_command, game_total_rows, game_total_columns);

        update_game_map(game_total_rows);
    } 
    while(1);
    //while (!game_is_over());

    free_game_map(game_total_rows);
}

void scan_game_map(unsigned int* game_total_rows , unsigned int* game_total_columns)
{
    char map_analyser[MAX_COLUMNS];
    char past_map_analyser[MAX_COLUMNS];

    unsigned int rows_analysed = 1;

    FILE* f_game_map;

    f_game_map = fopen("maps/game_map.txt", "r");

    if(f_game_map == NULL)
    {
        printf("\nGame map file could not be opened!\n");
        exit(1);
    }
    else
    {
        fscanf(f_game_map, "%s\n", map_analyser);
        *game_total_columns = strlen(map_analyser);

        count_map_rows(f_game_map, &rows_analysed, 
                       *game_total_columns, 
                       map_analyser, past_map_analyser);
        *game_total_rows = rows_analysed;
    }
    fclose(f_game_map);
}

void count_map_rows(FILE* map_ptr, unsigned int *row_analysed, unsigned int game_total_columns,
                                   char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS])
{
    while (map_analyser[0] == SIDE_WALL)
    {
        (*row_analysed)++;

        for(unsigned int i = 0; i < game_total_columns; i++)
        {
            past_map_analyser[i] = map_analyser[i];
        }

        fscanf(map_ptr, "%s\n", map_analyser);

        if(check_if_row_repeat(game_total_columns, map_analyser, past_map_analyser)) 
        {
            (*row_analysed)--;
            break;
        }
    }
}

int check_if_row_repeat(unsigned int game_total_columns, char map_analyser[MAX_COLUMNS], 
                                                         char past_map_analyser[MAX_COLUMNS])
{
    unsigned int right_words_counter = 0;

    for(unsigned int i = 0; i < game_total_columns; i++)
    {
        if(past_map_analyser[i] == map_analyser[i]) right_words_counter++;   
    }

    if(game_total_columns == right_words_counter)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void set_game_map(unsigned int game_total_rows, unsigned int game_total_columns)
{
    allocate_game_map(game_total_rows, game_total_columns);

    open_game_map_file(game_total_rows);
}

void allocate_game_map(unsigned int game_total_rows, unsigned int game_total_columns)
{
    game_map = malloc(sizeof(char*) * game_total_rows);

    for(int i = 0; i < game_total_rows; i++)
    {
        game_map[i] = malloc(sizeof(char) * (game_total_columns + 1)); // + 1 because of string's \0
    }
}

void open_game_map_file(unsigned int game_total_rows)
{
    FILE* f_game_map;
    f_game_map = fopen("maps/game_map.txt", "r");

    if(f_game_map == NULL)
    {
        printf("\nGame map file could not be opened!\n");
        exit(1);
    }
    else
    {
        for(int i = 0; i < game_total_rows; i++)
        {
            fscanf(f_game_map, "%s", game_map[i]);
            printf("%s\n", game_map[i]);
        }
    }
    fclose(f_game_map);
}

void move_pacman(char direction, unsigned int game_total_rows, unsigned int game_total_columns)
{
    unsigned int pacman_y_position = 0;
    unsigned int pacman_x_position = 0;
    
    find_pacman(game_total_rows, game_total_columns,
                &pacman_y_position, &pacman_x_position);

    set_move_direction(direction, &pacman_y_position, &pacman_x_position);
}

void find_pacman(unsigned int game_total_rows, unsigned int game_total_columns,
                 unsigned int* pacman_y_position, unsigned int* pacman_x_position)
{
    for(int i = 0; i < game_total_rows; i++)
    {
        for(int j = 0; j < game_total_columns; j++)
        {
            if(game_map[i][j] == PACMAN_CHAR)
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
        if(game_map[*pacman_y_position - 1][*pacman_x_position] == MOVING_SPACE)
        {
            printf("\nYou moved up!\n");
            game_map[*pacman_y_position - 1][*pacman_x_position] = PACMAN_CHAR;
            game_map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_y_position--;
        }
        break;
    
    case MOVE_DOWN:
        if(game_map[*pacman_y_position + 1][*pacman_x_position] == MOVING_SPACE)
        {
            printf("\nYou moved down!\n");
            game_map[*pacman_y_position + 1][*pacman_x_position] = PACMAN_CHAR;
            game_map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_y_position++;
        }
        break;
    
    case MOVE_RIGHT:
        if(game_map[*pacman_y_position][*pacman_x_position + 1] == MOVING_SPACE)
        {
            printf("\nYou moved right!\n");
            game_map[*pacman_y_position][*pacman_x_position + 1] = PACMAN_CHAR;
            game_map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_x_position++;
        }
        break;

    case MOVE_LEFT:
        if(game_map[*pacman_y_position][*pacman_x_position - 1] == MOVING_SPACE)
        {
            printf("\nYou moved left!\n");
            game_map[*pacman_y_position][*pacman_x_position - 1] = PACMAN_CHAR;
            game_map[*pacman_y_position][*pacman_x_position] = MOVING_SPACE;
            pacman_x_position--;
        }
        break;
    
    default:
        printf("\nYour move is not valid please press (w/a/s/d)!\n");
        break;
    }
}

void update_game_map(unsigned int game_total_rows)
{
    for(int i = 0; i < game_total_rows; i++)
    {
        printf("%s\n", game_map[i]);
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

void free_game_map(unsigned int game_total_rows)
{
    for(int i = 0; i < game_total_rows; i++)
    {
        free(game_map[i]);
    }
    free(game_map);
}

