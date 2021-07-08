/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** base_two.c
*/

#include "palindrome.h"

int nb_to_base_ten(int number, int base)
{
    int final_nb = 0;
    int base_power = 1;
    int right_num = 0;

    while (number - 1 >= 0) {
        right_num = number % 10;
        final_nb = final_nb + (right_num * base_power);
        base_power = base_power * base;
        number = number / 10;
    }
    return final_nb;
}

char *switch_bas(int nb, int base)
{
    int i = 0;
    int max = 1;
    char *res = malloc(sizeof(char) * (my_intlen(nb) + 1));

    while (max <= nb / base)
        max *= base;
    for (i = 0; nb != 0 || max != 1; i++) {
        if (i != 0 && max != 1) {
            nb %= max;
            max /= base;
        } else if (i != 0 && max == 1) {
            res[i] = '\0';
            return (res);
        }
        res[i] = nb/max + 48;
    }
    res[i] = '\0';
    return (res);
}

int boucle_bas(palindrome_t **pal, int i, char *rev)
{
    long buffer = 0;

    while (i <= (*pal)->max) {
        buffer = my_getnbr(switch_bas((*pal)->pal, (*pal)->b));
        if (check_palin(buffer) == 0)
            return print_win(pal);
        rev = my_revstr(switch_bas((*pal)->pal, (*pal)->b));
        (*pal)->rev_pal = my_getnbr(rev);
        (*pal)->pal = (*pal)->pal + nb_to_base_ten((*pal)->rev_pal, (*pal)->b);
        if ((*pal)->pal > 2147483647)
            return no_solution();
        i++;
        (*pal)->ite++;
    }
    return no_solution();
}

int other_base(palindrome_t *pal)
{
    int i = 0;
    char *rev = NULL;

    pal->start_pal = pal->pal;
    while (i < pal->min) {
        rev = my_revstr(switch_bas(pal->pal, pal->b));
        pal->rev_pal = my_getnbr(rev);
        pal->pal = pal->pal + (nb_to_base_ten(pal->rev_pal, pal->b));
        printf("%ld ", pal->pal);
        if (pal->pal > 2147483647)
            return no_solution();
        i++;
        pal->ite++;
    }
    return boucle_bas(&pal, i, rev);
}