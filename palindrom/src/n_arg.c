/*
** EPITECH PROJECT, 2020
** palindrome
** File description:
** n_arg.c
*/

#include "palindrome.h"

void fil_struct(char **argv, palindrome_t **palin)
{
    (*palin)->min = 0;
    (*palin)->b = 10;
    (*palin)->max = 100;
    (*palin)->ite = 0;
    for (int i = 1; argv[i] != NULL; i++) {
        if (my_strcmp(argv[i], "-n") == 0)
            (*palin)->pal = (my_getnbr(argv[i + 1]));
        if (my_strcmp(argv[i], "-p") == 0)
            (*palin)->pal = my_getnbr(argv[i + 1]);
        if (my_strcmp(argv[i], "-b") == 0)
            (*palin)->b = my_getnbr(argv[i + 1]);
        if (my_strcmp(argv[i], "-imin") == 0)
            (*palin)->min = my_getnbr(argv[i + 1]);
        if (my_strcmp(argv[i], "-imax") == 0)
            (*palin)->max = my_getnbr(argv[i + 1]);
    }
}

int print_win(palindrome_t **pal)
{
    my_printf("%d leads to %d in ", (*pal)->start_pal, (*pal)->pal);
    my_printf("%d iteration(s) in base %d\n", (*pal)->ite, (*pal)->b);
    return 0;
}

int boucle(palindrome_t *palin, int i)
{
    while (i <= palin->max) {
        if (check_palin(palin->pal) == 0)
            return print_win(&palin);
        palin->rev_pal = my_getnbr(my_revstr(int_to_str(palin->pal)));
        palin->pal = palin->pal + palin->rev_pal;
        palin->ite += 1;
        if (palin->pal > 2147483647)
            return no_solution();
        i++;
    }
    return no_solution();
}

int n_arg(char **argv)
{
    palindrome_t *palin = malloc(sizeof(palindrome_t));
    int i = 0;

    fil_struct(argv, &palin);
    palin->start_pal = palin->pal;
    if (palin->b == 7 && \
        check_palin(my_getnbr(switch_bas(palin->pal, palin->b))) != 0)
        return invalid_arg();
    if (palin->min > palin->max)
        return invalid_arg();
    if (palin->b != 10)
        return other_base(palin);
    while (i < palin->min) {
        palin->rev_pal = my_getnbr(my_revstr(int_to_str(palin->pal)));
        palin->pal = palin->pal + palin->rev_pal;
        if (palin->pal > 2147483647)
            return no_solution();
        palin->ite += 1;
        i += 1;
    }
    return boucle(palin, i);
}