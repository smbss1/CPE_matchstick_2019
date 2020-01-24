/*
** EPITECH PROJECT, 2019
** ia_file
** File description:
** all func for the ia
*/

#include <stdlib.h>
#include "match.h"
#include "debug.h"
#include "my.h"

int get_number_of_stick(char **map, int line)
{
    int count = 0;
    for (int i = 0; map[line][i]; i++)
        if (map[line][i] == '|')
            count++;
    return (count);
}

void ia_play(match_t *match)
{
    int line = (rand() % (match->lines - 1 + 1)) + 1;
    int num = (rand() % (match->coup_max - 1 + 1)) + 1;
    if (!erasable(match, line, num)) {
        ia_play(match);
        return;
    }
    if (get_stick_all(match) % 3 == 0)
        num = 1;
    erase_stick(match, line, num);
    my_printf("AI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", num, line);
    print_map(match->map, match->row);
    if (get_stick_all(match) == 0)
        emit("ai_loose", 0, 0);
}