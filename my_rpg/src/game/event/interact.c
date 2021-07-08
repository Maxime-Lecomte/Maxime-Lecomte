/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** interact.c
*/

#include "rpg.h"
#include "struct_rpg.h"
#include <SFML/Graphics.h>

static evt_t do_event(obj_t *obj, evt_t evt, int offset)
{
    if (offset == 0)
        return (evt);
    if (evt.is_fight == sfTrue) {
        in_fight(obj, evt.enemy);
        evt.active = sfFalse;
        obj->event[9].offset_dialogue += 1;
    } else {
        sfSprite_setTextureRect(evt.sprite, (sfIntRect){offset % 3 * 33, \
            offset / 3 * 33, 33, 33});
        sfRenderWindow_drawSprite(obj->window, obj->map[obj->offset], NULL);
        draw_event(obj);
        sfRenderWindow_drawSprite(obj->window, obj->perso->sprite, NULL);
        do_dialogue(obj->window, evt.dialogue[evt.offset_dialogue]);
    }
    return (evt);
}

void interact(obj_t *obj)
{
    int offset = 0;

    for (int i = 0; obj->event[i].pos.x != -1; ++i) {
        if (obj->event[i].active == sfTrue && obj->event[i].always_active == \
            sfFalse && obj->event[i].offset_map == obj->offset) {
            offset = (obj->perso->offset == 1 && obj->perso->pos.x == \
                obj->event[i].pos.x && obj->perso->pos.y == \
                obj->event[i].pos.y - 33 ? 10 : offset);
            offset = (obj->perso->offset == 4 && obj->perso->pos.x == \
                obj->event[i].pos.x + 33 && obj->perso->pos.y == \
                obj->event[i].pos.y ? 7 : offset);
            offset = (obj->perso->offset == 7 && obj->perso->pos.x == \
                obj->event[i].pos.x - 33 && obj->perso->pos.y == \
                obj->event[i].pos.y ? 4 : offset);
            offset = (obj->perso->offset == 10 && obj->perso->pos.x == \
                obj->event[i].pos.x && obj->perso->pos.y == \
                obj->event[i].pos.y + 33 ? 1 : offset);
            obj->event[i] = do_event(obj, obj->event[i], offset);
            offset = 0;
        }
    }
}