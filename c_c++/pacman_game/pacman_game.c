/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
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

    do
    {
        set_game_map(game_total_rows, game_total_columns);  
        
        scanf(" %c", &user_command); 

        move_pacman(user_command, game_total_rows, game_total_columns);
    } 
    while (!game_is_over());
}

void move_pacman(char direction, unsigned int game_total_rows_aux, unsigned int game_total_columns_aux)
{
    unsigned int pacman_x_position, pacman_y_position = 0;
    
    find_pacman(game_total_rows_aux, game_total_columns_aux,
                &pacman_x_position, &pacman_y_position);

    copy_round_map(game_total_rows_aux, game_total_columns_aux);                

    switch (direction)
    {
    case(MOVE_UP):
        game_map[pacman_x_position][pacman_y_position + 1] = game_map[pacman_x_position][pacman_y_position];
        game_map[pacman_x_position][pacman_y_position] = MOVING_SPACE;
        break;
    
    case(MOVE_DOWN):
        game_map[pacman_x_position][pacman_y_position - 1] = game_map[pacman_x_position][pacman_y_position];
        game_map[pacman_x_position][pacman_y_position] = MOVING_SPACE;
        break;

    case(MOVE_RIGHT):
        game_map[pacman_x_position + 1][pacman_y_position] = game_map[pacman_x_position][pacman_y_position];
        game_map[pacman_x_position][pacman_y_position] = MOVING_SPACE;
        break;
    
    case(MOVE_LEFT):
        game_map[pacman_x_position - 1][pacman_y_position] = game_map[pacman_x_position][pacman_y_position];
        game_map[pacman_x_position][pacman_y_position] = MOVING_SPACE;
        break;
    }
}

void copy_round_map(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux)
{
    for(unsigned int i = 0; i < game_total_rows_aux; i++)
    {
        for(unsigned int j = 0; j < game_total_columns_aux; j++)
        {
            last_round_game_map[i][j] = game_map[i][j];
        }
    }
}



void find_pacman(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux,
                 unsigned int* pacman_x_position_aux, unsigned int* pacman_y_position_aux)
{
    for(int i = 0; i < game_total_rows_aux; i++)
    {
        for(int j = 0; j < game_total_columns_aux; j++)
        {
            if(game_map[i][j] == PACMAN_CHAR)
            {
                *pacman_x_position_aux = i;
                *pacman_y_position_aux = j;
            }
        }
    }
    printf("\nX position %d ---- Y position %d\n\n", *pacman_x_position_aux, *pacman_y_position_aux);
}

int game_is_over()
{
    if(1) // game is over condition 
    {

        return 1;
    }   
    else
    {

        return 0;
    }
}

void scan_game_map(unsigned int* game_total_rows_aux , unsigned int* game_total_columns_aux)
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
        *game_total_columns_aux = strlen(map_analyser);

        count_map_rows(f_game_map, &rows_analysed, 
                       *game_total_columns_aux, 
                       map_analyser, past_map_analyser);
        *game_total_rows_aux = rows_analysed;
    }
    fclose(f_game_map);
}

void count_map_rows(FILE* map_ptr, unsigned int *row_analysed_aux, unsigned int game_total_columns_aux,
                                   char map_analyser_aux[MAX_COLUMNS], char past_map_analyser_aux[MAX_COLUMNS])
{
    while (map_analyser_aux[0] == SIDE_WALL)
    {
        (*row_analysed_aux)++;

        for(unsigned int i = 0; i < game_total_columns_aux; i++)
        {
            past_map_analyser_aux[i] = map_analyser_aux[i];
        }

        fscanf(map_ptr, "%s\n", map_analyser_aux);

        if(check_if_row_repeat(game_total_columns_aux, map_analyser_aux, past_map_analyser_aux)) 
        {
            (*row_analysed_aux)--;
            break;
        }
    }
}

int check_if_row_repeat(unsigned int game_total_columns_aux, char map_analyser_aux[MAX_COLUMNS], 
                                                             char past_map_analyser_aux[MAX_COLUMNS])
{
    unsigned int right_words_counter = 0;

    for(unsigned int i = 0; i < game_total_columns_aux; i++)
    {
        if(past_map_analyser_aux[i] == map_analyser_aux[i]) right_words_counter++;   
    }

    if(game_total_columns_aux == right_words_counter)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void set_game_map(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux)
{
    allocate_game_map(game_total_rows_aux, game_total_columns_aux);

    open_game_map_file(game_total_rows_aux);

    free_game_map(game_total_rows_aux);
}

void free_game_map(unsigned int game_total_rows_aux)
{
    for(int i = 0; i < game_total_rows_aux; i++)
    {
        free(game_map[i]);
    }
    free(game_map);
}

void allocate_game_map(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux)
{
    game_map = malloc(sizeof(char*) * game_total_rows_aux);

    for(int i = 0; i < game_total_rows_aux; i++)
    {
        game_map[i] = malloc(sizeof(char) * (game_total_columns_aux + 1)); // + 1 because of string's \0
    }
}

void open_game_map_file(unsigned int game_total_rows_aux)
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
        for(int i = 0; i < game_total_rows_aux; i++)
        {
            fscanf(f_game_map, "%s", game_map[i]);
            printf("%s\n", game_map[i]);
        }
    }
    fclose(f_game_map);
}