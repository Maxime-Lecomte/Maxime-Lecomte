/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** my_itoa.c
*/

#include <stdlib.h>

static int my_intlen(int nb)
{
    int i = 1;

    while (nb / 10 != 0 && nb - 1 > 0) {
        nb /= 10;
        i = i + 1;
    }
    return (i);
}

char *my_itoa(int nbr)
{
    int len = my_intlen(nbr);
    char *str = malloc(sizeof(char) * len + 1);
    int i = 1;

    if (!str)
        return NULL;
    while (i <= len){
        str[len - i] = ((nbr % 10) + 48);
        nbr = nbr /10;
        i++;
    }
    str[len] = '\0';
    return (str);
}