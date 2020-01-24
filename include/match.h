
/*
** EPITECH PROJECT, 2019
** debug
** File description:
** Debug Function
*/

#ifndef _MATCH_
#define _MATCH_
typedef struct match
{
    int lines;
    int row;
    int col;
    int coup_max;
    char **map;
} match_t;

int my_exit(int status);
int player_loose(void);
int ai_loose(int st);
void on(char *name, void *var, void *handler, void *handler2);
char **init_map(int row, int col);
void print_map(char **map, int row);
int update(match_t *match);
void erase_stick(match_t *match, int line, int num);
int emit(char *name, void *value, void *value2);
int get_stick_all(match_t *match);
int get_number_of_stick(char **map, int line);
int erasable(match_t *match, int line, int num);
int my_str_contain(char *str, char c);
char **my_memset_array(char **ptr, int x, int r, int c);

static const char *error1 = "Error: you cannot remove more than";
static const char *pl_remove = "Player removed";

#endif