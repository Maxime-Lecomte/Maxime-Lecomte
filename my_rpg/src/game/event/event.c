/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** event.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

void draw_event(obj_t *obj)
{
    for (int i = 0; obj->event[i].pos.x != -1; ++i) {
        if (obj->event[i].offset_map == obj->offset && obj->event[i].active \
            == true && obj->event[i].sprite != NULL)
            sfRenderWindow_drawSprite(obj->window, obj->event[i].sprite, NULL);
    }
}

void check_event(obj_t *obj)
{
    for (int i = 0; obj->event[i].pos.x != -1; ++i) {
        if (obj->event[i].offset_map == obj->offset && obj->event[i].active \
            == true && obj->event[i].always_active == true && \
            obj->event[i].pos.x == obj->perso->pos.x && obj->event[i].pos.y \
            == obj->perso->pos.y && obj->event[i].teleport == true) {
            obj->offset = obj->event[i].new_offset;
            teleport(obj->window, obj->perso->sprite, \
                obj->map[obj->event[i].new_offset], obj->event[i].where);
            break;
        }
    }
}