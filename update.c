/*
** EPITECH PROJECT, 2019
** update
** File description:
** update func
*/

#include "debug.h"
#include "match.h"
#include "get_next_line.h"
#include <stdlib.h>

int get_stick_all(match_t *match)
{
    int count = 0;
    for (int i = 0; i < match->row; i++)
        for (int j = 0; j < match->col; j++)
            if (match->map[i][j] == '|')
                count++;
    return (count);
}

int player_turn(match_t *match, char *buffe)
{
    my_printf("Line: ");
    buffe = get_next_line(0);
    if (line_error(buffe, match) == 84)
        return (player_turn(match, buffe));
    else if (line_error(buffe, match) == 83)
        return (83);
    int line = my_getnbr(buffe);
    my_putstr("Matches: ");
    char *matches = get_next_line(0);
    int num_stick = my_getnbr(matches);
    if (match_error(match->map, matches, line, num_stick) == 84)
        return (player_turn(match, buffe));
    if (!erasable(match, line, num_stick)) {
        my_printf("%s %d matches per turn\n", error1, match->coup_max);
        return (player_turn(match, buffe));
    }
    erase_stick(match, line, num_stick);
    my_printf("%s %d match(es) from line %d\n", pl_remove, num_stick, line);
}

int update(match_t *match)
{
    int run = -1;
    char *buffe = NULL;
    on("exit", &run, my_exit, NULL);
    on("player_loose", &run, player_loose, NULL);
    on("ai_loose", &run, ai_loose, NULL);
    while (run == -1) {
        my_printf("Your turn:\n");
        if (player_turn(match, buffe) == 83)
            continue;
        if (get_stick_all(match) == 0) {
            print_map(match->map, match->row);
            emit("player_loose", 0, 0);
            continue;
        }
        print_map(match->map, match->row);
        ia_play(match);
    }
    return (run);
}