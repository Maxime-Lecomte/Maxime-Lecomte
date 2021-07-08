/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** init_map.c
*/

#include "utils.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>

sfSprite **init_map(void)
{
    int i = 0;
    char *filepath = NULL;
    sfSprite **map = malloc(sizeof(sfSprite *) * (NB_MAP + NB_INSIDE + 1));

    for (i = 0; i < NB_MAP; ++i) {
        filepath = malloc(sizeof(char) * (my_intlen(i + 1) + 31));
        memset(filepath, '\0', my_intlen(i + 1) + 31);
        map[i] = create_sprite(my_strcat(my_strcat(my_strcat(filepath, \
            "res/map/images/outside/map"), my_itoa(i + 1)), ".png"), NULL);
        free(filepath);
    }
    for (i = NB_MAP; i < NB_MAP + NB_INSIDE; ++i) {
        filepath = malloc(sizeof(char) * (my_intlen(i + 1) + 30));
        memset(filepath, '\0', my_intlen(i + 1) + 30);
        map[i] = create_sprite(my_strcat(my_strcat(my_strcat(filepath, \
            "res/map/images/inside/map"), my_itoa(i + 1)), ".png"), NULL);
        free(filepath);
    }
    map[i] = NULL;
    return (map);
}