/*
** EPITECH PROJECT, 2020
** put number
** File description:
** put_nubr
*/

#include "palindrome.h"

int my_put_nbr(int nbr)
{
    int nombre = nbr;

    if (nbr < 0) {
        nbr = -(nbr);
        my_putchar('-');
    }
    if ((nombre <= 9) && (nombre >= 0)) {
        my_putchar((nombre) + 48);
    } else {
        my_put_nbr(nombre / 10);
        my_putchar((nombre % 10) + 48);
    }
    return (0);
}