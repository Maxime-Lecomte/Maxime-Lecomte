/*
** EPITECH PROJECT, 2020
** my_swap
** File description:
** lib
*/

void my_swap(char *a, char *b)
{
    char c;

    c = *a;
    *a = *b;
    *b = c;
}