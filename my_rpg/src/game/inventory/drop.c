/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** drop.c
*/

#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static void item_to_item(perso_t *perso, item_t item_tmp, int i, int idx)
{
    if (perso->items[i].id != -1) {
        item_tmp = perso->items[i];
        perso->items[i] = perso->items[idx];
        perso->items[idx] = item_tmp;
    } else {
        perso->items[i] = perso->items[idx];
        perso->items[idx] = item_tmp;
    }
}

static void equipped_item_to_item(perso_t *perso, item_t item_tmp, int i, \
    int idx)
{
    if (perso->items[i].id != -1 && perso->items[i].equipable == \
        perso->equipped_item[idx].equipable) {
        item_tmp = perso->items[i];
        perso->items[i] = perso->equipped_item[idx];
        perso->equipped_item[idx] = item_tmp;
    } else {
        item_tmp.equipable = perso->equipped_item[idx].equipable;
        perso->items[i] = perso->equipped_item[idx];
        perso->equipped_item[idx] = item_tmp;
    }
}

void which_inventory(perso_t *perso, sfVector2i mse, int idx, bool swap)
{
    item_t item_tmp = {-1, -1, 0, NULL};
    sfIntRect rect = {0, 0, 68, 68};

    for (int i = 0; i < 28; ++i) {
        rect = (sfIntRect){234 + ((i % 7) * 73), 281 + ((i / 7) * 73), 68, 68};
        if (sfIntRect_contains(&rect, mse.x, mse.y) && swap == false) {
            item_to_item(perso, item_tmp, i, idx);
            return;
        }
        if (sfIntRect_contains(&rect, mse.x, mse.y) && swap == true && \
            perso->items[i].id != -1 && perso->items[i].equipable != \
            perso->equipped_item[idx].equipable)
            return;
        else if (sfIntRect_contains(&rect, mse.x, mse.y) && swap == true) {
            equipped_item_to_item(perso, item_tmp, i, idx);
            return;
        }
    }
}

static void item_to_equipped_item(perso_t *perso, item_t item_tmp, int i, \
    int idx)
{
    if (perso->equipped_item[i].id != -1) {
        item_tmp = perso->equipped_item[i];
        perso->equipped_item[i] = perso->items[idx];
        perso->items[idx] = item_tmp;
    } else {
        perso->equipped_item[i] = perso->items[idx];
        perso->items[idx] = item_tmp;
    }
}

void which_equipment(perso_t *perso, sfVector2i mse, int idx)
{
    item_t item_tmp = {-1, -1, 0, NULL};
    sfIntRect rect = {0, 0, 68, 68};

    for (int i = 0; i < 6; ++i) {
        if (i < 2)
            rect = (sfIntRect){783, 70 + i * 109, 68, 68};
        else
            rect = (sfIntRect){783, 281 + (i - 2) * 72, 68, 68};
        if (sfIntRect_contains(&rect, mse.x, mse.y) && \
            perso->items[idx].equipable == perso->equipped_item[i].equipable) {
            item_to_equipped_item(perso, item_tmp, i, idx);
            return;
        }
    }
}