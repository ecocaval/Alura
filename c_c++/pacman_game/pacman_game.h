/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

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

struct game
{
    char** map;
    unsigned int total_rows;
    unsigned int total_columns;
};

void scan_game_map();

void count_map_rows(FILE* map_ptr, unsigned int *row_analysed, 
                    char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

int check_if_row_repeat(char map_analyser[MAX_COLUMNS], char past_map_analyser[MAX_COLUMNS]);

void set_game_map();     

void allocate_game_map();

void open_game_map_file();

void move_pacman(char direction);

void find_pacman(unsigned int* pacman_y_position, unsigned int* pacman_x_position);

void set_move_direction(char direction, unsigned int* pacman_y_position, unsigned int* pacman_x_position);

void update_game_map();

int game_is_over();

void free_game_map();
