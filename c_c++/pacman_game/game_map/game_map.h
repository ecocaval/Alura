/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_COLUMNS   100

#define SIDE_WALL     '|'

#define PACMAN_CHAR   '@'
#define GHOST_CHAR    'F'

#define MOVING_SPACE  '.'

struct game
{
    char** map;
    unsigned int total_rows;
    unsigned int total_columns;
};

typedef struct game GAME;

void scan_game_map(GAME* map);

void count_map_rows(FILE* map_ptr, GAME* map, unsigned int *row_analysed, 
                    char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

int check_if_row_repeat(GAME* map, char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

void set_game_map(GAME* map);     

void allocate_game_map(GAME* map);

void open_game_map_file(GAME* map);

void update_game_map(GAME* map);

void free_game_map(GAME* map);