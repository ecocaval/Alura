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

void scan_game_map(unsigned int* game_total_rows_aux, unsigned int* game_total_columns_aux);

void count_map_rows(FILE* map_ptr, unsigned int *row_analysed_aux, unsigned int game_total_columns_aux, 
                    char map_analyser_aux[MAX_COLUMNS], char past_map_analyser_aux[MAX_COLUMNS]);

int check_if_row_repeat(unsigned int game_total_columns_aux, char map_analyser_aux[MAX_COLUMNS], 
                        char past_map_analyser_aux[MAX_COLUMNS]);

void set_game_map(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux);

void free_game_map(unsigned int game_total_rows_aux);

void allocate_game_map(unsigned int game_total_rows_aux, unsigned int  game_total_columns_aux);

void open_game_map_file(unsigned int game_total_rows_aux);

int game_is_over();

void move_pacman(char direction, unsigned int game_total_rows_aux, unsigned int game_total_columns_aux);

void find_pacman(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux,
                 unsigned int* pacman_x_position_aux, unsigned int* pacman_y_position_aux);

void copy_round_map(unsigned int game_total_rows_aux, unsigned int game_total_columns_aux);

