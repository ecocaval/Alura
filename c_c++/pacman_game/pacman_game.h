/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
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

void scan_game_map(unsigned int* game_total_rows , unsigned int* game_total_columns);

void count_map_rows(FILE* map_ptr, unsigned int *row_analysed, unsigned int game_total_columns,
                                   char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

int check_if_row_repeat(unsigned int game_total_columns, char map_analyser[MAX_COLUMNS], 
                        char past_map_analyser[MAX_COLUMNS]);

void set_game_map(unsigned int game_total_rows, unsigned int game_total_columns);                        

void allocate_game_map(unsigned int game_total_rows, unsigned int game_total_columns);

void open_game_map_file(unsigned int game_total_rows);

void move_pacman(char direction, unsigned int game_total_rows, unsigned int game_total_columns);

void find_pacman(unsigned int game_total_rows, unsigned int game_total_columns,
                 unsigned int* pacman_x_position, unsigned int* pacman_y_position);

void set_move_direction(char direction, unsigned int* pacman_x_position, unsigned int* pacman_y_position);

int game_is_over();

void free_game_map(unsigned int game_total_rows);
