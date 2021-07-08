/*
** EPITECH PROJECT, 2020
** B-PSU-100-BDX-1-1-myprintf-maxime.lecomte
** File description:
** my_printf.c
*/

#include "palindrome.h"

void display(int comp, char const *str, va_list ap)
{
    int i = 0;
    char ref[] = "dsciboxX";
    void (*fctn[])(va_list) = {&printf_d,
                                &printf_s,
                                &printf_c,
                                &printf_i,
                                &binari_translate,
                                &octal_translate,
                                &hexa_min_translate,
                                &hexa_maj_translate};
    while (ref[i] != '\0') {
        if (ref[i] == str[comp]) {
            fctn[i](ap);
        }
        i++;
    }
}

void my_printf(char *str, ...)
{
    va_list ap;
    int comp = 0;

    va_start(ap, str);
    while (str[comp] != '\0') {
        if ((str[comp] == '%') && (str[comp + 1] != ' ')) {
            comp = comp + 1;
            display(comp, str, ap);
            comp = comp + 1;
        } else if ((str[comp] == '\\') && (str[comp + 1] != 'n')) {
            my_putchar('\n');
            comp = comp + 2;
        } else {
            my_putchar(str[comp]);
            comp++;
        }
    }
    va_end(ap);
}