
/*
** EPITECH PROJECT, 2019
** debug
** File description:
** Debug Function
*/

#ifndef _DEBUG_
#define _DEBUG_
#define R_DEV_ASSERT(cond, fmt, ret) \
        if (cond) debug(fmt); \
        if (cond) ret;
#endif