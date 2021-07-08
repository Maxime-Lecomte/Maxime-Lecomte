/*
** EPITECH PROJECT, 2020
** my_putstr
** File description:
** lib
*/

#include "palindrome.h"

void my_putstr(char const *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i = i + 1;
    }
}