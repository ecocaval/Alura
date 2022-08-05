/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#define MOVE_UP       'w'
#define MOVE_DOWN     's'
#define MOVE_LEFT     'a'
#define MOVE_RIGHT    'd'
#define BLANK_SPACE   ' '
#define EXIT_BUTTON   'y'

#include "game_map/game_map.h"

struct char_position
{
    unsigned int x_position;
    unsigned int y_position;
};

typedef struct char_position POSITION;

void get_user_command(POSITION* char_position);

void move_pacman(char direction, GAME* map, POSITION* char_position);

void find_in_game_map(GAME* map, POSITION* char_position, char finding_char);

void set_move_direction(char direction, POSITION* char_position);

int game_is_over();