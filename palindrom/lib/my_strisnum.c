/*
** EPITECH PROJECT, 2020
** B-CPE-200-BDX-2-1-matchstick-maxime.lecomte
** File description:
** lib.c
*/

#include "palindrome.h"

int my_strisnum(char *str)
{
    for (int i = 0; str[i] != '\0' && str[i] != '\n'; ++i) {
        if ((str[i] < '0') || (str[i] > '9'))
            return 84;
    }
    return 0;
}