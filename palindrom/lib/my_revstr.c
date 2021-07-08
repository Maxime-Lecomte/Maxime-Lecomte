/*
** EPITECH PROJECT, 2020
** my_revstr
** File description:
** task02
*/

#include "palindrome.h"

char *my_revstr(char *str)
{
    int i = my_strlen(str);
    int comp = 0;

    while (comp < i) {
        my_swap(&str[comp], &str[i - 1]);
        comp++;
        i--;
    }
    return (str);
}