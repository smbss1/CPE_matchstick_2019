/*
** EPITECH PROJECT, 2019
** print_map
** File description:
** print map
*/

#include "my.h"

void print_map(char **map, int row)
{
    for (int i = 0; i < row; i++) {
        my_printf("%s\n", map[i]);
    }
    my_putstr("\n");
}