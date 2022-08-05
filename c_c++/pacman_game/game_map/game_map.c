/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "conio.h"
#include <time.h>

#include "game_map.h"

void scan_game_map(GAME* map)
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
        map->total_columns = strlen(map_analyser);

        count_map_rows(f_game_map, map, &rows_analysed,  
                       map_analyser, past_map_analyser);
        map->total_rows = rows_analysed;
    }
    fclose(f_game_map);
}

void count_map_rows(FILE* map_ptr, GAME* map, unsigned int *row_analysed, 
                    char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS])
{
    while (map_analyser[0] == SIDE_WALL)
    {
        (*row_analysed)++;

        for(unsigned int i = 0; i < map->total_columns; i++) 
        {
            past_map_analyser[i] = map_analyser[i];
        }

        fscanf(map_ptr, "%s\n", map_analyser);

        if(check_if_row_repeat(map, map_analyser, past_map_analyser)) 
        {
            (*row_analysed)--;
            break;
        }
    }
}

int check_if_row_repeat(GAME* map, char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS])
{
    unsigned int right_words_counter = 0;

    for(unsigned int i = 0; i < map->total_columns; i++)
    {
        if(past_map_analyser[i] == map_analyser[i]) right_words_counter++;   
    }

    if(map->total_columns == right_words_counter)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}

void set_game_map(GAME* map)
{
    allocate_game_map(map);

    open_game_map_file(map);
}

void allocate_game_map(GAME* map)
{
    map->map = malloc(sizeof(char*) * map->total_rows);

    for(unsigned int i = 0; i < map->total_rows; i++)
    {
        map->map[i] = malloc(sizeof(char) * (map->total_columns + 1)); // + 1 because of string's \0
    }
}

void open_game_map_file(GAME* map)
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
        for(unsigned int i = 0; i < map->total_rows; i++)
        {
            fscanf(f_game_map, "%s", map->map[i]);
            printf("%s\n", map->map[i]);
        }
    }
    fclose(f_game_map);
}

void update_game_map(GAME* map )
{
    for(unsigned int i = 0; i < map->total_rows; i++)
    {
        printf("%s\n", map->map[i]);
    }
}

void free_game_map(GAME* map)
{
    for(unsigned int i = 0; i < map->total_rows; i++)
    {
        free(map->map[i]);
    }
    free(map->map);
}
