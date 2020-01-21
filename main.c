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

char **init_map(int row, int col);

void print_map(char **map, int row);

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

void erase_stick(match_t *match, int line, int num)
{
    int col = match->col - 2;
    for (int i = match->col - 2;
        match->map[line][i] != '|' && match->map[line][i];
        i--, col--);
    for (int i = match->col - 2; i > col - num && i > 0; i--)
        match->map[line][i] = ' ';
}

void free_2d_array_match(match_t *match)
{
    for (int i = 0; i < match->row; i++)
        free(match->map[i]);
    free(match->map);
}

int main(int ac, char **av)
{
    if (ac != 3)
        return (84);
    srandom(time(NULL));
    match_t match = {0};
    match.lines = my_getnbr(av[1]);
    match.coup_max = my_getnbr(av[2]);
    match.row = match.lines + 2;
    match.col = match.lines + match.lines + 1;
    match.map = init_map(match.row, match.col);
    print_map(match.map, match.row);
    int up = update(&match);
    if (up > 0) {
        free_2d_array_match(&match);
        return (up);
    }
    return (0);
}