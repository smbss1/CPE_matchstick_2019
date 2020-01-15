/*
** EPITECH PROJECT, 2019
** update
** File description:
** update func
*/
#include "debug.h"
#include "match.h"
#include <stdlib.h>

int my_exit(int status);

int player_loose();

int ai_loose(int st);

int get_stick_all(char **map)
{
    int count = 0;
    for (int i = 0; map[i]; i++)
        for (int j = 0; map[i][j]; j++)
            if (map[i][j] == '|')
                count++;
    return (count);
}

int player_turn(match_t *match, char *buffe)
{
    my_printf("You turn:\nLine: ");
    buffe = get_next_line(0);
    if (line_error(buffe, match) == 84)
        return (84);
    int line = my_getnbr(buffe);
    my_putstr("Matches: ");
    int num_stick = my_getnbr(get_next_line(0));
    if (match_error(num_stick) == 84)
        return (84);
    R_DEV_ASSERT(!erasable(match->map, line, num_stick),
        "Error number\n", return (84));
    erase_stick(match, line, num_stick);
    my_printf("Player removed %d match(es) from line %d\n",
                num_stick, line);
    return (0);
}

int update(match_t *match)
{
    int run = 0;
    char *buffe = NULL;
    on("exit", &run, my_exit, NULL);
    on("player_loose", &run, player_loose, NULL);
    on("ai_loose", &run, ai_loose, NULL);
    while (run == 0) {
        if (player_turn(match, buffe) == 84)
            continue;
        if (get_stick_all(match->map) == 0) {
            print_map(match->map, match->row);
            emit("player_loose", 0, 0);
            continue;
        }
        print_map(match->map, match->row);
        ia_play(match);
    }
    return (run);
}