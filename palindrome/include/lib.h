/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** lib.h
*/

#ifndef LIB_H
#define LIB_H

#include <stdarg.h>

long my_getnbr(char const *str);
int my_put_nbr(int nbr);
void my_putchar(char c);
void my_putstr(char const *str);
int my_strcmp(char const *s1, char const *s2);
int my_strisnum(char *str);
void my_swap(char *a, char *b);
char *my_revstr(char *str);
int my_strlen(char const *str);

//my_printf//
void my_printf(char *str, ...);
void display(int comp, char const *str, va_list ap);
void printf_d(va_list ap);
void printf_s(va_list ap);
void printf_c(va_list ap);
void printf_i(va_list ap);
void binari_translate(va_list ap);
void octal_translate(va_list ap);
void hexa_min_translate(va_list ap);
void hexa_maj_translate(va_list ap);

#endif