/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** init_box.c
*/

#include "utils.h"
#include "rpg.h"
#include "macro_rpg.h"
#include <stdlib.h>
#include <string.h>
#include <SFML/Graphics.h>

static int count_x(char **map)
{
    int x = 0;
    int y = 0;
    int count = 0;

    while (map[y] != NULL) {
        if (map[y][x] == 'X')
            ++count;
        if (map[y][x] == '\0') {
            ++y;
            x = 0;
        } else
            ++x;
    }
    return (count);
}

static sfIntRect *add_block(sfIntRect *block, char **map)
{
    int x = 0;
    int y = 0;
    int j = 0;

    block = malloc(sizeof(sfIntRect) * (count_x(map) + 1));
    while (map[y] != NULL) {
        if (map[y][x] == 'X') {
            block[j] = (sfIntRect){x * 33, y * 33, 33, 33};
            ++j;
        }
        if (map[y][x] == '\0') {
            ++y;
            x = 0;
        } else
            ++x;
    }
    block[j] = (sfIntRect){-1, -1, -1, -1};
    return (block);
}

sfIntRect **init_block(void)
{
    sfIntRect **block = malloc(sizeof(sfIntRect *) * (NB_MAP + NB_INSIDE + 1));
    char **map = NULL;
    char *filepath = NULL;

    for (int i = 0; i < NB_MAP; ++i) {
        filepath = malloc(sizeof(char) * (my_intlen(i + 1) + 29));
        memset(filepath, '\0', my_intlen(i + 1) + 29);
        map = download_map(my_strcat(my_strcat(my_strcat(filepath, \
            "res/map/data/outside/map"), my_itoa(i + 1)), ".txt"));
        block[i] = add_block(block[i], map);
        free(filepath);
    }
    for (int i = NB_MAP; i < NB_MAP + NB_INSIDE; ++i) {
        filepath = malloc(sizeof(char) * (my_intlen(i + 1) + 28));
        memset(filepath, '\0', my_intlen(i + 1) + 28);
        map = download_map(my_strcat(my_strcat(my_strcat(filepath, \
            "res/map/data/inside/map"), my_itoa(i + 1)), ".txt"));
        block[i] = add_block(block[i], map);
        free(filepath);
    }
    return (block);
}