/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** download_map.c
*/

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>

static char *file_in_str(char const *filepath)
{
    char *str = NULL;
    int ret = open(filepath, O_RDONLY);
    struct stat *stats = malloc(sizeof(struct stat));

    if (ret == -1 || stats == NULL) {
        if (stats != NULL)
            free(stats);
        return NULL;
    }
    stat(filepath, stats);
    str = malloc(sizeof(char) * (stats->st_size + 1));
    if (str == NULL) {
        free(stats);
        return NULL;
    }
    read(ret, str, stats->st_size);
    str[stats->st_size] = '\0';
    free(stats);
    return (str);
}

static int count_rows(char *str)
{
    int i = 0;
    int rows = 0;

    if (str == NULL)
        return 0;
    while (str[i] != '\0') {
        if (str[i] == '\n')
            ++rows;
        ++i;
    }
    return (rows);
}

static int count_line(char *str, int i)
{
    int len = 0;

    while (str[i + len] != '\n' && str[i + len] != '\0')
        ++len;
    return (len);
}

static char *fill_line(char *line, char *str, int *i)
{
    int j = *i;

    line = malloc(sizeof(char) * (count_line(str, *i) + 1));
    if (line == NULL)
        return NULL;
    for (j = *i; str[*i] != '\n' && str[*i] != '\0'; *i = *i + 1)
        line[*i - j] = str[*i];
    line[*i - j] = '\0';
    return (line);
}

char **download_map(char const *filepath)
{
    int line = 0;
    char *str = file_in_str(filepath);
    int rows = count_rows(str);
    char **map = NULL;

    if (str == NULL || rows == 0)
        return NULL;
    map = malloc(sizeof(char *) * (rows + 1));
    if (map == NULL)
        return NULL;
    for (int i = 0; line < rows; ++i) {
        map[line] = fill_line(map[line], str, &i);
        if (map[line] == NULL)
            return NULL;
        ++line;
    }
    map[line] = NULL;
    free(str);
    return (map);
}