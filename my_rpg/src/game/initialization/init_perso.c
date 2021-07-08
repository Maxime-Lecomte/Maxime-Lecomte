/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** init_perso.c
*/

#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static stat_t set_stat_perso(void)
{
    stat_t stat;

    stat.level = 1;
    stat.exp = 0;
    stat.exp_max = 100;
    stat.pv = 100;
    stat.pv_max = 100;
    stat.mana = 100;
    stat.mana_max = 100;
    stat.att = 10;
    stat.att_spe = 10;
    stat.def = 10;
    stat.def_spe = 10;
    return (stat);
}

static perso_t *init_item(perso_t *perso)
{
    perso->items = malloc(sizeof(item_t) * 28);
    perso->equipped_item = malloc(sizeof(item_t) * 6);
    if (perso->equipped_item == NULL || perso->items == NULL) {
        free(perso);
        return NULL;
    }
    for (int i = 0; i < 6; ++i) {
        perso->equipped_item[i].id = -1;
        perso->equipped_item[i].count = -1;
        perso->equipped_item[i].equipable = i + 1;
        perso->equipped_item[i].sprite = NULL;
    }
    for (int i = 0; i < 28; ++i) {
        perso->items[i].id = -1;
        perso->items[i].count = -1;
        perso->items[i].equipable = 0;
        perso->items[i].sprite = NULL;
    }
    return (perso);
}

perso_t *init_perso(void)
{
    perso_t *perso = malloc(sizeof(perso_t));

    perso->name = "Empty";
    perso->offset = 10;
    perso->gold = 50621;
    perso->id_attack1 = 1;
    perso->id_attack2 = 2;
    perso->stat = set_stat_perso();
    perso = init_item(perso);
    if (perso == NULL)
        return NULL;
    perso->sprite = create_sprite(SPRITESHEET, NULL);
    perso->move = (sfVector2f){0, 0};
    perso->pos = (sfVector2f){14.5 * 33, 17 * 33};
    perso->box = (sfIntRect){perso->pos.x, perso->pos.y, 33, 33};
    sfSprite_setTextureRect(perso->sprite, (sfIntRect){perso->offset % 3 * \
        33, perso->offset / 3 * 33, 33, 33});
    sfSprite_setPosition(perso->sprite, perso->pos);
    return (perso);
}