/*
** EPITECH PROJECT, 2019
** fill_array_whitespace
** File description:
** fill array
*/

static inline int get_col(char **array)
{
    int i = 0;
    for (i = 0; array[0][i]; i++);
    return (i);
}

static inline int get_row(char **array)
{
    int i = 0;
    for (i = 0; array[i]; i++);
    return (i);
}

void fill_array_whitespace(char **array, int _x, int _y)
{
    int row = get_row(array);
    int col = get_col(array);

    for (int i = _x; i < row - 1; i++)
        for (int j = _y; j < col - 1; j++)
            array[i][j] = ' ';
}