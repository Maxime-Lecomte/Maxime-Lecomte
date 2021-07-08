/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** free.c
*/

#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static void free_items(obj_t *obj)
{
    for (int i = 0; i < 6; ++i) {
        if (obj->perso->equipped_item[i].sprite != NULL) {
            sfTexture_destroy((sfTexture *)sfSprite_getTexture(\
                obj->perso->equipped_item[i].sprite));
            sfSprite_destroy(obj->perso->equipped_item[i].sprite);
        }
    }
    if (obj->perso->equipped_item != NULL)
        free(obj->perso->equipped_item);
    for (int i = 0; i < 28; ++i) {
        if (obj->perso->items[i].sprite != NULL) {
            sfTexture_destroy((sfTexture *)sfSprite_getTexture(\
                obj->perso->items[i].sprite));
            sfSprite_destroy(obj->perso->items[i].sprite);
        }
    }
    if (obj->perso->items != NULL)
        free(obj->perso->items);
}

static void free_perso(obj_t *obj)
{
    free_items(obj);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(obj->perso->sprite));
    sfSprite_destroy(obj->perso->sprite);
    if (obj->perso != NULL)
        free(obj->perso);
}

void free_obj(obj_t *obj)
{
    for (int i = 0; obj->box[i] != NULL; ++i)
        free(obj->box[i]);
    if (obj->box != NULL)
        free(obj->box);
    for (int i = 0; obj->event[i].pos.x != -1; ++i) {
        if (obj->event[i].sprite != NULL) {
            sfTexture_destroy((sfTexture *)sfSprite_getTexture(\
                obj->event[i].sprite));
            sfSprite_destroy(obj->event[i].sprite);
        }
    }
    if (obj->event != NULL)
        free(obj->event);
    for (int i = 0; obj->map[i] != NULL; ++i) {
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(obj->map[i]));
        sfSprite_destroy(obj->map[i]);
    }
    if (obj->map != NULL)
        free(obj->map);
    free_perso(obj);
}