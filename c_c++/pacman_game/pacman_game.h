/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>

#define ALPHABET_SIZE 26
#define SIDE_WALL     '|'
#define BLANK_SPACE   ' '

void scan_game_map(unsigned int* game_total_rows_aux, unsigned int* game_total_columns_aux);

void count_map_rows(FILE* map_ptr, unsigned int *row_analysed_aux, unsigned int game_total_columns_aux, 
                    char map_analyser_aux[ALPHABET_SIZE], char past_map_analyser_aux[ALPHABET_SIZE]);

int check_if_row_repeat(unsigned int game_total_columns_aux, char map_analyser_aux[ALPHABET_SIZE], 
                        char past_map_analyser_aux[ALPHABET_SIZE]);