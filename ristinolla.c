#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define RISTI 1
#define NOLLA 2
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 10

int8_t tictactoe_check(int8_t* gameboard, int win_len);
void initialize_2d_gameboard(int8_t* gameboard, int8_t gameboard_2d[10][10]);

bool check_vertical(int8_t gameboard_2d[10][10], int win_len, int8_t player);
bool check_horizontal(int8_t gameboard_2d[10][10], int win_len, int8_t player);
bool check_top_left_to_lower_right(int8_t gameboard_2d[10][10], int win_len, int8_t player);
bool check_top_right_to_lower_left(int8_t gameboard_2d[10][10], int win_len, int8_t player);

int main(void)
{
    int8_t gameboard[100] = {
        0,0,0,0,0,1,1,1,1,1,
        0,1,0,0,0,0,0,0,0,0,
        0,0,1,0,0,0,0,0,0,0,
        0,0,0,1,1,1,1,1,0,0,
        0,0,0,0,1,0,1,0,0,0,
        0,0,0,0,0,1,1,0,0,0,
        0,0,0,0,0,0,1,0,0,0,
        0,0,0,0,0,0,1,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
        0,0,0,0,0,0,0,0,0,0,
    };


    return tictactoe_check(gameboard, 5);
}

void initialize_2d_gameboard(int8_t* gameboard, int8_t gameboard_2d[10][10])
{
    for (int8_t i = 0; i < 10; i++)
    {
        for (int8_t j = 0; j < 10; j++)
        {
            gameboard_2d[i][j] = gameboard[10 * i + j];
        }
    }
}

bool check_horizontal(int8_t gameboard_2d[10][10], int win_len, int8_t player)
{
    for (int8_t i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int8_t j = 0; j < BOARD_WIDTH - win_len; j++)
        {
            int8_t line_length = 0;
            if (gameboard_2d[j][i] == player)
            {
                for (int8_t k = 0; k < win_len; k++)
                {
                    if (gameboard_2d[j + k][i] == player)
                        line_length++;
                }
            }
            if (line_length >= win_len)
            {
                return true;
            }
        }
    }
    return false;
}
bool check_vertical(int8_t gameboard_2d[10][10], int win_len, int8_t player);
bool check_top_left_to_lower_right(int8_t gameboard_2d[10][10], int win_len, int8_t player);
bool check_top_right_to_lower_left(int8_t gameboard_2d[10][10], int win_len, int8_t player);

int8_t tictactoe_check(int8_t* gameboard, int win_len)
{
    int8_t gameboard_2d[10][10] = { 0 };
    initialize_2d_gameboard(gameboard, gameboard_2d);
    bool risti_wins = check_horizontal(gameboard_2d, win_len, RISTI);
    bool nolla_wins = check_horizontal(gameboard_2d, win_len, NOLLA);

    if (risti_wins && nolla_wins) return 0;
    if (risti_wins) return 1;
    if (nolla_wins) return 2;
    return 0;
}
