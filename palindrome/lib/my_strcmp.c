/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** my_strcmp.c
*/

#include "palindrome.h"

int my_strcmp(char const *s1, char const *s2)
{
    int i = 0;

    while (s1[i] != '\0' && s2[i] != '\0') {
        if (s1[i] == s2[i]) {
            i += 1;
        }
        if (s1[i] > s2[i]) {
            return (1);
        }
        if (s1[i] < s2[i]) {
            return (-1);
        }
    }
    return (0);
}