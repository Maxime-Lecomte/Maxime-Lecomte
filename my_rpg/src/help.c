/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** help.c
*/

#include <unistd.h>
#include <stdbool.h>

static bool my_strcmp(char const *str1, char const *str2)
{
    int i = 0;

    while (str1[i] == str2[i] && str1[i] != '\0')
        ++i;
    if (str1[i] == '\0')
        return (true);
    else
        return (false);
}

bool is_help(int argc, char const **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h")) {
        write(1, "USAGE:\n    ./my_rpg\nDESCRIPTION:\n"
        "    It's a roll play game.\n", 60);
        return (true);
    }
    return (false);
}