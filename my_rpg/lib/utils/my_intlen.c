/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** my_intlen.c
*/

int my_intlen(int nb)
{
    int i = 1;

    while (nb / 10 != 0 && nb - 1 > 0) {
        nb /= 10;
        i = i + 1;
    }
    return (i);
}