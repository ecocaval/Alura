/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include "pacman_game.h"

void main()
{
    scan_game_map();
}

void scan_game_map()
{
    char map_analyser[ALPHABET_SIZE];
    
    unsigned int rows_analysed = 0;
    unsigned int game_total_rows = 0;

    FILE* f_game_map;

    f_game_map = fopen("maps/game_map.txt", "r+");

    if(f_game_map == NULL)
    {
        printf("\nGame map file could not be opened!\n");
        exit(1);
    }
    else
    {
        while (map_analyser[rows_analysed] != BLANK_SPACE)
        {
            fscanf(f_game_map, "%s", &map_analyser);
            rows_analysed++;
        }

        game_total_rows = rows_analysed;
        
    }
    fclose(f_game_map);
}