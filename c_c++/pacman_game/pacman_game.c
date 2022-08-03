/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include "pacman_game.h"

char map_analyser[ALPHABET_SIZE];
char past_map_analyser[ALPHABET_SIZE];

unsigned int rows_analysed = 1;
unsigned int game_total_rows = 0;
unsigned int game_total_columns = 0;

void main()
{
    scan_game_map();
}

void scan_game_map()
{
    FILE* f_game_map;

    f_game_map = fopen("maps/game_map.txt", "r+");

    if(f_game_map == NULL)
    {
        printf("\nGame map file could not be opened!\n");
        exit(1);
    }
    else
    {
        fseek(f_game_map, 0, SEEK_SET);
        fscanf(f_game_map, "%s\n", map_analyser);

        game_total_columns = strlen(map_analyser);

        printf("\n%s ", map_analyser);
        printf("Analizing row: %d\n", rows_analysed);

        count_map_rows(f_game_map);

        game_total_rows = rows_analysed;

        printf("\nMap total number of rows: %d", game_total_rows);
        printf("\nMap total number of columns: %d\n", game_total_columns);
    }
    fclose(f_game_map);
}

void count_map_rows(FILE* map_ptr)
{
    while (map_analyser[0] == SIDE_WALL)
    {
        rows_analysed++;

        for(int columns_counter = 0; columns_counter < game_total_columns; columns_counter++)
        {
            past_map_analyser[columns_counter] = map_analyser[columns_counter];
        }

        fscanf(map_ptr, "%s\n", map_analyser);

        if(check_if_row_repeat()) 
        {
            rows_analysed--;
            break;
        }

        printf("%s ", map_analyser);
        printf("Analizing row: %d\n", rows_analysed);
    }
}

int check_if_row_repeat()
{
    int right_words_counter = 0;

    for(int columns_counter = 0; columns_counter < game_total_columns; columns_counter++)
    {
        if(past_map_analyser[columns_counter] == map_analyser[columns_counter]) right_words_counter++;   
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
