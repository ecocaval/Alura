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

struct pacman_position
{
    unsigned int x_position;
    unsigned int y_position;
};

typedef struct pacman_position PACMAN;

void get_user_command(PACMAN* pacman);

void move_pacman(char direction, GAME* map, PACMAN* pacman);

void find_in_game_map(GAME* map, PACMAN* pacman, char finding_char);

void set_move_direction(char direction, PACMAN* pacman);

int game_is_over();