/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** p_arg.c
*/

#include "palindrome.h"

int obj(int i, palindrome_t **pal)
{
    while (i <= (*pal)->max) {
        if ((*pal)->buf_pal == (*pal)->pal)
            return print_win(pal);
        (*pal)->rev_pal = my_getnbr(my_revstr(int_to_str((*pal)->buf_pal)));
        if (((*pal)->buf_pal + (*pal)->rev_pal) > 0)
            (*pal)->buf_pal = (*pal)->buf_pal + (*pal)->rev_pal;
        else
            return 84;
        (*pal)->ite += 1;
        i++;
    }
    return 84;
}

int way(palindrome_t **pal)
{
    int i = 0;

    (*pal)->ite = 0;
    while (i < (*pal)->min) {
        (*pal)->rev_pal = my_getnbr(my_revstr(int_to_str((*pal)->buf_pal)));
        (*pal)->buf_pal = (*pal)->buf_pal + (*pal)->rev_pal;
        (*pal)->ite += 1;
        i += 1;
    }
    if (obj(i, pal) == 84)
        (*pal)->echec += 1;
    return (*pal)->echec;
}

int p_arg(char **argv)
{
    palindrome_t *pal = malloc(sizeof(palindrome_t));
    pal->start_pal = 1;

    fil_struct(argv, &pal);
    if (pal->b == 7 && \
        check_palin(my_getnbr(switch_bas(pal->pal, pal->b))) != 0)
        return invalid_arg();
    if (pal->min > pal->max)
        return invalid_arg();
    while (pal->start_pal <= pal->pal) {
        pal->buf_pal = pal->start_pal;
        if (way(&pal) == pal->pal)
            my_printf("no solution\n");
        pal->start_pal += 1;
    }
    return 0;
}