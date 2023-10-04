#include <stdio.h>
#include <inttypes.h>

int8_t tictactoe_check(int8_t *gameboard, int win_len);

int main(void)
{
    int8_t gameboard[100] = {1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10,
    1,2,3,4,5,6,7,8,9,10};
    tictactoe_check(gameboard, 3);
    return 0;
}

int8_t tictactoe_check(int8_t *gameboard, int win_len)
{
    int8_t gameboard_2d[10][10] = gameboard;
    printf("%i\n", gameboard_2d[0][1]);
    return 0;
}