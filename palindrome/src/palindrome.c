/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** palindrome.c
*/

#include "palindrome.h"

int palindrome(char **argv)
{
    if (my_strcmp(argv[1], "-n") == 0)
        return n_arg(argv);
    if (my_strcmp(argv[1], "-p") == 0)
        return p_arg(argv);
    return 0;
}