/*
** EPITECH PROJECT, 2019
** update
** File description:
** update func
*/
#include "debug.h"
#include <stdlib.h>

int my_exit(int status);

extern int ROW;

void update(char **map)
{
    int run = 1;
    char *buffe = NULL;
    on("exit", &run, my_exit, NULL);
    while (run) {
        my_printf("You turn:\nLine: ");
        buffe = get_next_line(0);
        R_DEV_ASSERT((line_error(buffe) == 84), "", continue);
        int line = my_getnbr(buffe);
        my_putstr("Matches: ");
        int num_stick = my_getnbr(get_next_line(0));
        if (match_error(num_stick) == 84)
            continue;
        R_DEV_ASSERT(!erasable(map, line, num_stick),
            "Error number\n", continue);
        erase_stick(map, line, num_stick);
        my_printf("Player removed %d match(es) from line %d\n",
                    num_stick, line);
        print_map(map, ROW);
        ia_play(map);
    }
}