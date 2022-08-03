/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#include <stdio.h>

#define ALPHABET_SIZE 26
#define SIDE_WALL     '|'
#define BLANK_SPACE   ' '

void scan_game_map();

void count_map_rows(FILE* file_ptr);

int check_if_row_repeat();