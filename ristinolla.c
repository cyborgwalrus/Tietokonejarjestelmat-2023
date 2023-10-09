#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

int8_t tictactoe_check(int8_t *gameboard, int win_len);
int8_t gameboard_to_2d(int8_t *gameboard);

bool check_vertical(int8_t *gameboard_2d, int win_len);
bool check_horizontal(int8_t *gameboard_2d, int win_len);
bool check_top_left_to_lower_right(int8_t *gameboard_2d, int win_len);
bool check_top_right_to_lower_left(int8_t *gameboard_2d, int win_len);

int main(void)
{
    int8_t gameboard[100] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10,
                             1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    tictactoe_check(gameboard, 3);

    return 0;
}

int8_t gameboard_to_2d(int8_t *gameboard){
    int8_t gameboard_2d[10][10];
    for (int8_t i = 0; i < 10; i++)
    {
        for (int8_t j = 0; j < 10; j++){
            gameboard_2d[i][j] = gameboard[10*i+j];
        }
    }
    return &gameboard_2d;
}

bool check_vertical(int8_t *gameboard_2d, int win_len, int8_t player);
bool check_horizontal(int8_t *gameboard_2d, int win_len, int8_t player);
bool check_top_left_to_lower_right(int8_t *gameboard_2d, int win_len, int8_t player);
bool check_top_right_to_lower_left(int8_t *gameboard_2d, int win_len, int8_t player);

int8_t tictactoe_check(int8_t *gameboard, int win_len)
{
    int8_t gameboard_2d[10][10] = gameboard_to_2d(gameboard);
    return 0;
}