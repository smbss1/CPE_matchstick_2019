/*
** EPITECH PROJECT, 2019
** debug
** File description:
** debug_assert
*/

#include "unistd.h"
#include "my.h"

void debug(char *format)
{
    write(1, format, my_strlen(format));
}

int assert(int condition, const char *message)
{
    if (condition) {
        my_printf("%s", message);
        return (1);
    }
    return (0);
}