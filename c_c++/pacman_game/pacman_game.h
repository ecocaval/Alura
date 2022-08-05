/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#define MOVE_UP       'w'
#define MOVE_DOWN     's'
#define MOVE_LEFT     'a'
#define MOVE_RIGHT    'd'
#define BLANK_SPACE   ' '
#define EXIT_BUTTON   'y'

#define FIND_FIRST    'F'
#define FIND_LAST     'L'

#define RANDOM_UP      0
#define RANDOM_DOWN    1
#define RANDOM_LEFT    2
#define RANDOM_RIGHT   3

#define NUMBER_OF_DIRECTIONS 4

#define MAX_NUMBER_OF_RANDOM_TRIES 50

#include "game_map/game_map.h"

struct char_position
{
    unsigned int x_position;
    unsigned int y_position;
};

typedef struct char_position POSITION;

void get_user_command(GAME* map, POSITION* char_position);

void move_pacman(GAME* map, POSITION* char_position, char direction);

void find_in_game_map(GAME* map, POSITION* char_position, 
                      char finding_char, char position_to_find);

void set_move_direction(GAME* map, POSITION* char_position, char direction);

int game_is_over();

void define_random_direction(unsigned int* direction_selector, char define_ghost);

void move_ghost(GAME* map, POSITION* char_position, char define_ghost);

int generate_random_number();