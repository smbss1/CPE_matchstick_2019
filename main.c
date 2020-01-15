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

void erase_stick(match_t *match, int line, int num)
{
    int col = match->col - 2;
    for (int i = match->col - 2;
        match->map[line][i] != '|' && match->map[line][i];
        i--, col--);
    for (int i = match->col - 2; i > col - num && i > 0; i--)
        match->map[line][i] = ' ';
}

int main(int ac, char **av)
{
    srandom(time(NULL));
    match_t match = {0};
    match.lines = 4;
    match.row = match.lines + 2;
    match.col = match.lines + match.lines + 1;
    match.map = init_map(match.row, match.col);
    print_map(match.map, match.row);
    int up = update(&match);
    if (up > 0) {
        free_2d_array(match.map);
        return (up);
    }
    return (0);
}