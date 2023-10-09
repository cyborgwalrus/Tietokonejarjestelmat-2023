#include <stdio.h>
#include <inttypes.h>
#include <stdbool.h>

#define RISTI 1
#define NOLLA 2
#define BOARD_HEIGHT 10
#define BOARD_WIDTH 10

int8_t tictactoe_check(int8_t* gameboard, int win_len);

bool check_horizontal(int8_t* gameboard, int win_len, int8_t player);
bool check_vertical(int8_t* gameboard, int win_len, int8_t player);
bool check_top_left_to_lower_right(int8_t* gameboard, int win_len, int8_t player);
bool check_top_right_to_lower_left(int8_t* gameboard, int win_len, int8_t player);

int main(void)
{
    int8_t gameboard[100] = {
        1,0,0,0,0,1,1,1,1,1,
        0,1,0,0,0,0,0,0,1,0,
        0,0,1,0,0,0,0,1,0,0,
        0,0,0,1,1,1,1,1,0,0,
        0,0,0,0,1,1,1,0,0,0,
        0,0,0,0,1,1,1,0,0,0,
        0,0,0,1,0,0,1,0,0,0,
        0,0,1,0,0,0,1,1,0,0,
        0,1,0,0,0,0,0,0,1,0,
        1,0,0,0,0,0,0,0,0,0,
    };


    return tictactoe_check(gameboard, 10);
}

bool check_horizontal(int8_t* gameboard, int win_len, int8_t player)
{
    for (int8_t i = 0; i < BOARD_HEIGHT; i++)
    {
        for (int8_t j = 0; j <= BOARD_WIDTH - win_len; j++)
        {
            int8_t line_length = 0;
            if (gameboard[10 * i + j] == player)
            {
                for (int8_t k = 0; k < win_len; k++)
                {
                    if (gameboard[10 * i + j + k] == player)
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

bool check_vertical(int8_t* gameboard, int win_len, int8_t player)
{
    for (int8_t i = 0; i <= BOARD_HEIGHT - win_len; i++)
    {
        for (int8_t j = 0; j <= BOARD_WIDTH; j++)
        {
            int8_t line_length = 0;
            if (gameboard[10 * i + j] == player)
            {
                for (int8_t k = 0; k < win_len; k++)
                {
                    if (gameboard[10 * (i + k) + j] == player)
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

bool check_top_left_to_lower_right(int8_t* gameboard, int win_len, int8_t player)
{
    for (int8_t i = 0; i <= BOARD_HEIGHT - win_len; i++)
    {
        for (int8_t j = 0; j <= BOARD_WIDTH - win_len; j++)
        {
            int8_t line_length = 0;
            if (gameboard[10 * i + j] == player)
            {
                for (int8_t k = 0; k < win_len; k++)
                {
                    if (gameboard[10 * (i + k) + (j + k)] == player)
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

bool check_top_right_to_lower_left(int8_t* gameboard, int win_len, int8_t player)
{
    for (int8_t i = 0; i < 10; i++)
    {
        for (int8_t j = 9; j >= 0; j--)
        {
            if (i + win_len > 10  || j + 1 - win_len < 0) break;

            int8_t line_length = 0;
            if (gameboard[10 * i + j] == player)
            {
                for (int8_t k = 0; k < win_len; k++)
                {
                    if (gameboard[10 * (i + k) + (j - k)] == player)
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

int8_t tictactoe_check(int8_t* gameboard, int win_len)
{
    int8_t risti_wins = check_horizontal(gameboard, win_len, RISTI);
    int8_t nolla_wins = check_horizontal(gameboard, win_len, NOLLA);
    risti_wins += check_vertical(gameboard, win_len, RISTI);
    nolla_wins += check_vertical(gameboard, win_len, NOLLA);
    risti_wins += check_top_left_to_lower_right(gameboard, win_len, RISTI);
    nolla_wins += check_top_left_to_lower_right(gameboard, win_len, NOLLA);
    risti_wins += check_top_right_to_lower_left(gameboard, win_len, RISTI);
    nolla_wins += check_top_right_to_lower_left(gameboard, win_len, NOLLA);




    if (risti_wins && nolla_wins) return 0;
    if (risti_wins) return 1;
    if (nolla_wins) return 2;
    return 0;
}
