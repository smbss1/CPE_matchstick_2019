/*
** EPITECH PROJECT, 2019
** init_map
** File description:
** init the board
*/

#include "my.h"
#include "match.h"

char **init_map(int row, int col)
{
    char **map = mem_alloc_2d_array(row, col);

    my_memset_array(map, '*', row, col);
    for (int i = row - 2, k = 0; i > 0; i--, k++) {
        for (int j = col - 2; j > 0; j--)
            map[i][j] = '|';
        for (int j = 1; j < k + 1; j++)
            map[i][j] = ' ';
        for (int j = col - 2; j > col - 2 - k; j--)
            map[i][j] = ' ';
    }
    return (map);
}