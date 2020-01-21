/*
** EPITECH PROJECT, 2019
** erasable
** File description:
** erase
*/

#include "match.h"

int erasable(match_t *match, int line, int num)
{
    if (num > match->coup_max)
        return (0);
    int count = 0;
    for (int i = 0; match->map[line][i]; i++)
        if (match->map[line][i] == '|')
            count++;
    if (num <= count)
        return (1);
    return (0);
}