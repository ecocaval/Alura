/**
 * @brief game_map -- created in 04/08/2022 (Brazil) by Érico
*/

#include <stdio.h>

#define MAX_COLUMNS   100

#define SIDE_WALL     '|'
#define PACMAN_CHAR   '@'
#define MOVE_UP       'w'
#define MOVE_DOWN     's'
#define MOVE_LEFT     'a'
#define MOVE_RIGHT    'd'
#define MOVING_SPACE  '.'
#define BLANK_SPACE   ' '
#define EXIT_BUTTON   'y'

struct game_map
{
    char** map;
    unsigned int total_rows;
    unsigned int total_columns;
};

typedef struct game_map GAME;

void scan_game_map(GAME* game_map);

void count_map_rows(FILE* map_ptr, GAME* game_map, unsigned int *row_analysed, 
                    char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

int check_if_row_repeat(char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

void set_game_map(GAME* game_map)

void allocate_game_map(GAME* game_map)

void open_game_map_file(GAME* game_map)

void update_game_map(GAME* game_map)

void free_game_map(GAME* game_map)