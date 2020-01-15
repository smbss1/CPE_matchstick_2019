/*
** EPITECH PROJECT, 2019
** ia_file
** File description:
** all func for the ia
*/

#include <stdlib.h>
#include "match.h"
#include "debug.h"

extern int LINE;
extern int ROW;

int get_number_of_stick(char **map, int line)
{
    int count = 0;
    for (int i = 0; map[line][i]; i++)
        if (map[line][i] == '|')
            count++;
    return (count);
}

void ia_play(char **map)
{
    int line = (rand() % (LINE - 1 + 1)) + 1;
    int num_max = get_number_of_stick(map, line);
    if (num_max  == 0) {
        ia_play(map);
        return;
    }
    int num = (rand() % (num_max - 1 + 1)) + 1;
    R_DEV_ASSERT(!erasable(map, line, num), "", ia_play(map));
    erase_stick(map, line, num);
    my_printf("AI's turn...\n");
    my_printf("AI's removed %d match(es) from line %d\n", num, line);
    print_map(map, ROW);
}