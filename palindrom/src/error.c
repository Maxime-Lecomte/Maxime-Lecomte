/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** error.c
*/

#include "palindrome.h"

static int check_value(int value)
{
    if (value < 0) {
        return 84;
    }
    return 0;
}

int invalid_arg(void)
{
    my_printf("invalid argument\n");
    return 84;
}

int usage(void)
{
    my_printf("USAGE\n      ./palindrome -n number -p palindrome [-b base] ");
    my_printf("[-imin i] [-imax i]\n\nDESCRIPTION\n      -n n      integer ");
    my_printf("to be transformed (>= 0)\n      -p pal    palindromic number");
    my_printf("to be obtained (incompatible with the -noption) (>=0)\n");
    my_printf("                if defined, all fitting values of n will be ");
    my_printf("output\n");
    my_printf("      -b base   base in which the procedure will be executed");
    my_printf(" (1<b<=10) [def: 10]\n");
    my_printf("      -imin i   minimum number of iterations, included (>=0) ");
    my_printf("[def: 0]\n");
    my_printf("      -imax i   maximum number of iterations, included (>=0) ");
    my_printf("[def: 100]\n");
    return 0;
}

int check_word(char **argv, int i)
{
    int check = 0;

    if (my_strcmp(argv[i], "-b") != 0 || my_getnbr(argv[i + 1]) > 10 || \
        my_getnbr(argv[i + 1]) <= 1)
        check += 1;
    if ((my_strcmp(argv[i], "-imax") != 0))
        check += 1;
    if (my_strcmp(argv[i], "-imin") != 0)
        check += 1;
    if ((my_strcmp(argv[i], "-n") == 0) && (i == 1))
        check += 0;
    else
        check += 1;
    if (((my_strcmp(argv[i], "-p") == 0) && (i == 1)) && \
        check_palin(my_getnbr(argv[i + 1])) == 0)
        check += 0;
    else
        check += 1;
    if (check > 4)
        return invalid_arg();
    return 0;
}

int error(int argc, char **argv)
{
    int buf = 2;
    int i = 1;

    while (buf <= argc) {
        if (argv[i] == NULL)
            return 84;
        if (check_word(argv, i) != 0)
            return 84;
        i++;
        if (argv[i] == NULL)
            return invalid_arg();
        if (check_value(my_getnbr(argv[i])) != 0)
            return invalid_arg();
        i++;
        buf += 2;
    }
    return 0;
}