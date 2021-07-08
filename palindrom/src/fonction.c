/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** fonction.c
*/

#include "palindrome.h"

int my_intlen(int nb)
{
    int len = 0;

    while (nb - 1 >= 0) {
        nb /= 10;
        ++len;
    }
    return len;
}

char *int_to_str(long nb)
{
    int len = my_intlen(nb);
    char *str = malloc(sizeof(char) * (len + 1));

    for (int i = len - 1; i >= 0; --i) {
        str[i] = nb % 10 + '0';
        nb /= 10;
    }
    str[len] = '\0';
    return str;
}

int no_solution(void)
{
    my_printf("no solution\n");
    return 0;
}

int check_palin(int nb)
{
    int i = 0;
    char *str = int_to_str(nb);
    int len = (my_intlen(nb) - 1);

    while (i < len) {
        if (str[i] == str[len]) {
            i++;
            len--;
        } else
            return -1;
    }
    return 0;
}