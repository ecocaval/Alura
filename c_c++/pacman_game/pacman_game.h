/**
 * @brief pacman_game -- created in 03/08/2022 (Brazil) by Érico
*/

#define MOVE_UP       'w'
#define MOVE_DOWN     's'
#define MOVE_LEFT     'a'
#define MOVE_RIGHT    'd'
#define BLANK_SPACE   ' '
#define EXIT_BUTTON   'y'

void get_user_command();

void move_pacman(char direction);

void find_pacman(unsigned int* pacman_y_position, unsigned int* pacman_x_position);

void set_move_direction(char direction, unsigned int* pacman_y_position, unsigned int* pacman_x_position);

int game_is_over();