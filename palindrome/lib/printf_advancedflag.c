/*
** EPITECH PROJECT, 2020
** B-PSU-100-BDX-1-1-myprintf-maxime.lecomte
** File description:
** advancedflag.c
*/

#include "palindrome.h"

void binari_translate(va_list ap)
{
    char tab[32];
    int i = 0;
    int nbr = va_arg(ap, int);

    while (nbr > 0) {
        tab[i] = nbr % 2;
        nbr = nbr / 2;
        i++;
    }
    tab[i] = '\0';
    i--;
    while (i >= 0) {
        my_put_nbr(tab[i]);
        i--;
    }
}

void octal_translate(va_list ap)
{
    char tab[11];
    int i = 0;
    int nbr = va_arg(ap, int);

    while (nbr > 0) {
        tab[i] = nbr % 8;
        nbr = nbr / 8;
        i++;
    }
    tab[i] = '\0';
    i--;
    while (i >= 0) {
        my_put_nbr(tab[i]);
        i--;
    }
}

void hexa_min_translate(va_list ap)
{
    char tab[8];
    int i = 0;
    int nbr = va_arg(ap, int);

    while (nbr > 0) {
        tab[i] = ((nbr % 16) + 48);
        if (tab[i] > '9')
            tab[i] = tab[i] + 39;
        nbr = nbr / 16;
        i++;
    }
    tab[i] = '\0';
    i--;
    while (i >= 0) {
        my_putchar(tab[i]);
        i--;
    }
}

void hexa_maj_translate(va_list ap)
{
    char tab[8];
    int i = 0;
    int nbr = va_arg(ap, int);

    while (nbr > 0) {
        tab[i] = ((nbr % 16) + 48);
        if (tab[i] > '9')
            tab[i] = tab[i] + 7;
        nbr = nbr / 16;
        i++;
    }
    tab[i] = '\0';
    i--;
    while (i >= 0) {
        my_putchar(tab[i]);
        i--;
    }
}