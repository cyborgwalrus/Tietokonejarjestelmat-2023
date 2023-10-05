#include <stdio.h>
#include <inttypes.h>
#define RISTI 1
#define NOLLA 2


int8_t tictactoe_check(int8_t *gameboard, int win_len);
int8_t count_wins(int8_t *gameboard, int win_len, int8_t player);

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

int8_t tictactoe_check(int8_t *gameboard, int win_len)
{
    int8_t gameboard_2d[10][10];
    for (int8_t i = 0; i < 10; i++)
    {
        for (int8_t j = 0; j < 10; j++)
        {
            gameboard_2d[i][j] = gameboard[10 * i + j];
        }
    }

    int8_t risti_wins = count_wins(gameboard_2d, win_len, RISTI);
    int8_t nolla_wins = count_wins(gameboard_2d, win_len, NOLLA);

    return 0;
}

int8_t count_wins(int8_t *gameboard_2d, int win_len, int8_t player){
    for (int8_t i = 0; i < 10; i++)
    {
        for (int8_t j = 0; j < 10; j++)
        {
            switch(gameboard_2d[i][j]){
                case player:
                    check_win_horizontally(int8_t *gameboard_2d, player);
                    break;
                default:
                    break;
            }
        }
    }
}