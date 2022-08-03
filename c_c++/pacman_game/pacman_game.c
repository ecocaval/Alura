/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include "pacman_game.h"

int game_total_columns;

char map_analyser[ALPHABET_SIZE];
char past_map_analyser[ALPHABET_SIZE];

unsigned int rows_analysed = 1;
unsigned int game_total_rows = 0;

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

        printf("%s ", map_analyser);
        printf("Analizing row: %d\n", rows_analysed);

        while (map_analyser[0] == SIDE_WALL)
        {
            rows_analysed++;

            for(int i = 0; i < strlen(map_analyser); i++)
            {
                past_map_analyser[i] = map_analyser[i];
            }

            fscanf(f_game_map, "%s\n", map_analyser);

            if(check_if_row_repeat()) 
            {
                rows_analysed--;
                break;
            }

            printf("%s ", map_analyser);
            printf("Analizing row: %d\n", rows_analysed);
        }

        game_total_rows = rows_analysed;

        printf("\nMap total number of rows: %d", game_total_rows);
        printf("\nMap total number of columns: %d\n", strlen(map_analyser));
        
    }
    fclose(f_game_map);
}

int check_if_row_repeat()
{
    int right_words_counter = 0;

    for(int i = 0; i < strlen(map_analyser); i++)
    {
        if(past_map_analyser[i] == map_analyser[i]) right_words_counter++;   
    }

    if(strlen(map_analyser) == right_words_counter)
    {
        return 1;
    }
    else 
    {
        return 0;
    }
}
