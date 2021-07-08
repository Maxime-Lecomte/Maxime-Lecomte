/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** error.c
*/

#include <stddef.h>
#include <stdbool.h>

bool is_error(int argc, char const **env)
{
    if (argc != 1)
        return (true);
    for (int i = 0; env[i] != NULL; ++i) {
        if (env[i][0] == 'D' && env[i][1] == 'I' && env[i][2] == 'S' && \
            env[i][3] == 'P' && env[i][4] == 'L' && env[i][5] == 'A' && \
            env[i][6] == 'Y' && env[i][7] == '=')
            return (false);
    }
    return (true);
}