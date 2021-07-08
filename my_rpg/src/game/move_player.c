/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** move_player.c
*/

#include "rpg.h"
#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static void player_map_change(obj_t *obj)
{
    if (obj->perso->box.left < 0 && obj->offset % 4 != 0) {
        obj->perso->box.left += 1089;
        --obj->offset;
    }
    if (obj->perso->box.left + obj->perso->box.width > 1089 && \
        obj->offset % 4 != 3) {
        obj->perso->box.left -= 1089;
        ++obj->offset;
    }
    if (obj->perso->box.top < 0 && obj->offset >= 4) {
        obj->perso->box.top += 660;
        obj->offset -= 4;
    }
    if (obj->perso->box.top + obj->perso->box.height > 660 && \
        obj->offset <= 11) {
        obj->perso->box.top -= 660;
        obj->offset += 4;
    }
}

static bool is_wall(obj_t *obj, int offset, int *i)
{
    if ((obj->perso->pos.x + obj->perso->box.left + obj->perso->move.x < 0 || \
        obj->perso->pos.y + obj->perso->box.top + obj->perso->move.y < 0|| \
        obj->perso->pos.x + obj->perso->box.width + obj->perso->move.x > 1089 \
        || obj->perso->pos.y + obj->perso->box.height + obj->perso->move.y > \
        660) && obj->offset == offset)
        return (true);
    if (sfIntRect_intersects(&obj->perso->box, &obj->box[obj->offset][*i], \
        NULL) == sfTrue) {
        if (obj->perso->move.x == 1 || obj->perso->move.x == -1 || \
            obj->perso->move.y == 1 || obj->perso->move.y == -1) {
            obj->perso->move.x /= 2;
            obj->perso->move.y /= 2;
            obj->perso->box = (sfIntRect){obj->perso->pos.x + \
                obj->perso->move.x * 33, obj->perso->pos.y + \
                obj->perso->move.y * 33, 33, 33};
            *i = -1;
        } else
            return ((obj->offset = offset) % 1 + 1);
    }
    return (false);
}

static void animation_move(obj_t *obj, int offset)
{
    for (int i = 0; i < 3; ++i) {
        if (i == 0)
            obj->perso->offset -= 1;
        if (i == 1)
            obj->perso->offset += 2;
        if (i == 2)
            obj->perso->offset -= 1;
        sfSprite_move(obj->perso->sprite, (sfVector2f){obj->perso->move.x * \
            11, obj->perso->move.y * 11});
        sfSprite_setTextureRect(obj->perso->sprite, (sfIntRect){\
            obj->perso->offset % 3 * 33, obj->perso->offset / 3 * 33, 33, 33});
        sfRenderWindow_drawSprite(obj->window, obj->map[offset], NULL);
        if (obj->offset == offset)
            draw_event(obj);
        sfRenderWindow_drawSprite(obj->window, obj->perso->sprite, NULL);
        sfRenderWindow_display(obj->window);
        sfSleep((sfTime){50000});
    }
}

static void check_map_change(int *offset, perso_t *perso)
{
    if (*offset % 4 != 0 && perso->pos.x < 0) {
        *offset -= 1;
        perso->pos = (sfVector2f){perso->pos.x + 1089, perso->pos.y};
        sfSprite_setPosition(perso->sprite, perso->pos);
    }
    if (*offset % 4 != 3 && perso->pos.x > 1089 - 33) {
        *offset += 1;
        perso->pos = (sfVector2f){perso->pos.x - 1089, perso->pos.y};
        sfSprite_setPosition(perso->sprite, perso->pos);
    }
    if (*offset >= 4 && perso->pos.y < 0) {
        *offset -= 4;
        perso->pos = (sfVector2f){perso->pos.x, perso->pos.y + 660};
        sfSprite_setPosition(perso->sprite, perso->pos);
    }
    if (*offset <= 11 && perso->pos.y > 660 - 33) {
        *offset += 4;
        perso->pos = (sfVector2f){perso->pos.x, perso->pos.y - 660};
        sfSprite_setPosition(perso->sprite, perso->pos);
    }
}

void move_sprite(obj_t *obj)
{
    int offset = obj->offset;

    sfSprite_setTextureRect(obj->perso->sprite, (sfIntRect){obj->perso->offset \
        % 3 * 33, obj->perso->offset / 3 * 33, 33, 33});
    obj->perso->pos = sfSprite_getPosition(obj->perso->sprite);
    obj->perso->box = (sfIntRect){obj->perso->pos.x + obj->perso->move.x * 33, \
        obj->perso->pos.y + obj->perso->move.y * 33, 33, 33};
    player_map_change(obj);
    for (int i = 0; obj->box[obj->offset][i].left != -1; ++i) {
        if (is_wall(obj, offset, &i) == true)
            return;
    }
    animation_move(obj, offset);
    sfSprite_setPosition(obj->perso->sprite, (sfVector2f){obj->perso->pos.x + \
        obj->perso->move.x * 33, obj->perso->pos.y + obj->perso->move.y * 33});
    obj->perso->pos = sfSprite_getPosition(obj->perso->sprite);
    sfSprite_setTextureRect(obj->perso->sprite, (sfIntRect){obj->perso->offset \
        % 3 * 33, obj->perso->offset / 3 * 33, 33, 33});
    obj->offset = offset;
    obj->perso->move = (sfVector2f){0, 0};
    check_map_change(&obj->offset, obj->perso);
}