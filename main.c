/*
** EPITECH PROJECT, 2019
** main
** File description:
** Main Function
*/

#include "my.h"
#include "get_next_line.h"
#include "debug.h"
#include "match.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

const int LINE = 4;
const int ROW = LINE + 2;
const int COL = LINE + LINE + 1;

void on(char *name, void *var, void *handler, void *handler2);

int my_str_contain(char *str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (1);
    return (0);
}

void my_memset(void *ptr, int x, int n)
{
    unsigned char *temp = ptr;
    for (int i = 0; i < n; i++)
        *temp++ = x;
    return ptr;
}

int erasable(char **map, int line, int num)
{
    int count = 0;
    for (int i = 0; map[line][i]; i++)
        if (map[line][i] == '|')
            count++;
    if (num <= count)
        return (1);
    return (0);
}

void erase_stick(char **map, int line, int num)
{
    int col = COL - 2;
    for (int i = COL - 2; map[line][i] != '|' && map[line][i]; i--, col--);
    for (int i = COL - 2; i > col - num && i > 0; i--) {
        map[line][i] = ' ';
    }
}

int main(int ac, char **av)
{
    srandom(time(NULL));
    char **map = init_map(ROW, COL);
    print_map(map, ROW);
    update(map);
    free_2d_array(map);
    return (0);
}