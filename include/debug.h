
/*
** EPITECH PROJECT, 2019
** debug
** File description:
** Debug Function
*/

#ifndef _DEBUG_
#define _DEBUG_
int assert(int condition, const char *message);
#define R_DEV_ASSERT(cond, fmt, ret) assert(cond, fmt);\
                                        if (cond) ret;
#endif