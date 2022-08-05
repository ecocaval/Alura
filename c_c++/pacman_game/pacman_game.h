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

void move_ghosts(GAME* map, POSITION* char_position);