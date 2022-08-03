/**
 * @brief
    hangman_game.h -- created in 30/07/2022 (brazil)
*/

#define SECRET_WORD_MAX_SIZE 46 /*
                                    biggest brazilian word has 46 letters according to
                                    the brazilian dictionary, the word is:
                                    pneumoultramicroscopicossilicovulcanoconiótico
                                */

#define BLANK_SPACE ' '
#define UNDERLINE_SPACE '_'

#define ALPHABET_SIZE 26

void print_mark();

void game_header();

void generate_secret_word();

int generate_random_number();

void get_user_guess();

int check_repeated_guess();

void compare_guess_secret_word();

int check_if_hanged();

void check_stop_condition();

void add_word_to_list();

void draw_hangman();
