/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** palindrome.h
*/

#ifndef PAL_H
#define PAL_H

#include "lib.h"
#include "struct.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>

int palindrome(char **argv);
int error(int argc, char **argv);
int usage(void);
int n_arg(char **argv);
int p_arg(char **argv);
char *int_to_str(long nb);
int my_intlen(int nb);
int p_arg(char **argv);
void fil_struct(char **argv, palindrome_t **palin);
int check_palin(int nb);
int no_solution(void);
int print_win(palindrome_t **pal);
int invalid_arg(void);
int other_base(palindrome_t *pal);
char *switch_bas(int nb, int base);

#endif