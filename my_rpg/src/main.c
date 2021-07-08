/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** main.c
*/

#include "rpg.h"

int main(int argc, char const **argv, char const **env)
{
    if (is_help(argc, argv) == true)
        return 0;
    if (is_error(argc, env) == true)
        return 84;
    return (in_menu());
}