/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>

#define MAX_COLUMNS   100
#define SIDE_WALL     '|'
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
