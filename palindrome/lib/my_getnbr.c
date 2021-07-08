/*
** EPITECH PROJECT, 2020
** B-CPE-200-BDX-2-1-matchstick-maxime.lecomte
** File description:
** my_getnbr.c
*/

#include "palindrome.h"

long my_getnbr(char const *str)
{
    long nb = 0;
    long i = 0;
    long val = 1;

    if (str == NULL)
        return -1;
    while (str[i] != '\0') {
        if ((str[i] >= '0' && str[i] <= '9') || str[i] == '\0') {
            nb = nb * 10 + (str[i] - 48);
            i += 1;
        } else
            return -1;
    }
    return (nb * val);
}
