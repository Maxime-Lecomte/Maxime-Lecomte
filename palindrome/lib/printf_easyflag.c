/*
** EPITECH PROJECT, 2020
** B-PSU-100-BDX-1-1-myprintf-maxime.lecomte
** File description:
** easyflag.c
*/

#include "palindrome.h"

void printf_d(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}

void printf_s(va_list ap)
{
    my_putstr(va_arg(ap, char *));
}

void printf_c(va_list ap)
{
    my_putchar(va_arg(ap, int));
}

void printf_i(va_list ap)
{
    my_put_nbr(va_arg(ap, int));
}