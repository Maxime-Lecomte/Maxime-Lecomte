/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** my_strcat.c
*/

#include <stdlib.h>

static int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return 0;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}

char *my_strcat(char const *first, char const *second)
{
    int i = 0;
    int total_len = my_strlen(first) + my_strlen(second);
    char *both = malloc(sizeof(char) * total_len + 1);

    if (both == NULL)
        return NULL;
    while (first[i] != '\0') {
        both[i] = first[i];
        i++;
    }
    for (int j = 0; second[j] != '\0'; j++) {
        both[i] = second[j];
        i++;
    }
    both[total_len] = '\0';
    return both;
}