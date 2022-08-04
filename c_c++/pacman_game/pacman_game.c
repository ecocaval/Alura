/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "pacman_game.h"

void main()
{
    unsigned int game_total_rows = 0;
    unsigned int game_total_columns = 0;

    scan_game_map(&game_total_rows, &game_total_columns);

    char map[game_total_rows][game_total_columns];
    printf("%d %d", game_total_rows, game_total_columns);
}

void scan_game_map(unsigned int* game_total_rows_aux , unsigned int* game_total_columns_aux)
{
    char map_analyser[MAX_COLUMNS];
    char past_map_analyser[MAX_COLUMNS];

    unsigned int rows_analysed = 1;

    FILE* f_game_map;

    f_game_map = fopen("maps/game_map.txt", "r+");

    if(f_game_map == NULL)
    {
        printf("\nGame map file could not be opened!\n");
        exit(1);
    }
    else
    {
        fscanf(f_game_map, "%s\n", map_analyser);

        *game_total_columns_aux = strlen(map_analyser);

        count_map_rows(f_game_map, &rows_analysed, *game_total_columns_aux, 
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
