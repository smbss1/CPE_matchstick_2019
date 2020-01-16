/*
** EPITECH PROJECT, 2019
** handle_error
** File description:
** error check
*/

#include "debug.h"
#include "match.h"
#include "my.h"
#include <signal.h>
#include <string.h>
#include <stdio.h>

int my_exit(int status)
{
    if (status < 0)
        return (1);
    return (status);
}

int line_error(char *buffe, match_t *match)
{
    R_DEV_ASSERT(!buffe, "", emit("exit", 0, 0));
    R_DEV_ASSERT(!buffe, "", return (83));
    R_DEV_ASSERT(!*buffe, "Error no line typing\n", return (84));
    R_DEV_ASSERT(!my_str_isnum(buffe),
        "Error: invalid input (positive number expected)\n", return (84));
    R_DEV_ASSERT(my_str_contain(buffe, ' '),
        "Error: invalid input (positive number expected)\n", return (84));
    int line = my_getnbr(buffe);
    R_DEV_ASSERT(line > match->lines || line < 1,
        "Error: this line is out of range\n", return (84));
    return (0);
}

int match_error(int num_stick)
{
    R_DEV_ASSERT(num_stick < 1,
        "Error: you have to remove at least one match\n", return (84));
}