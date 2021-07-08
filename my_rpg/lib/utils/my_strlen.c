/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** my_strlen.c
*/

int my_strlen(char const *str)
{
    int i = 0;

    if (!str)
        return -1;
    while (str[i] != '\0') {
        i++;
    }
    return (i);
}