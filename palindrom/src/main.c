/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** main.c
*/

#include "palindrome.h"

int main(int argc, char **argv)
{
    if (argc == 2 && my_strcmp(argv[1], "-h") == 0)
        return (usage());
    if (error(argc, argv) != 0)
        return 84;
    return (palindrome(argv));
}