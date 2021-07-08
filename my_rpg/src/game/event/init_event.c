/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** init_event.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static evt_t set_teleport(int offset, sfVector2f pos, int new_offset, \
    sfVector2f new_pos)
{
    evt_t event;

    event.active = sfTrue;
    event.always_active = sfTrue;
    event.is_fight = sfFalse;
    event.offset_map = offset;
    event.pos = pos;
    event.teleport = sfTrue;
    event.new_offset = new_offset;
    event.where = new_pos;
    event.sprite = NULL;
    return (event);
}

static void init_teleport(evt_t *event)
{
    event[0] = set_teleport(6, (sfVector2f){0 * 33, 1 * 33}, 16, \
        (sfVector2f){19.5 * 33, 11 * 33});
    event[1] = set_teleport(16, (sfVector2f){19.5 * 33, 12 * 33}, 6, \
        (sfVector2f){0 * 33, 2 * 33});
    event[2] = set_teleport(6, (sfVector2f){22 * 33, 1 * 33}, 17, \
        (sfVector2f){20 * 33, 17 * 33});
    event[3] = set_teleport(17, (sfVector2f){20 * 33, 18 * 33}, 6, \
        (sfVector2f){22 * 33, 2 * 33});
    event[4] = set_teleport(2, (sfVector2f){10 * 33, 15 * 33}, 18, \
        (sfVector2f){17 * 33, 18 * 33});
    event[5] = set_teleport(2, (sfVector2f){11 * 33, 15 * 33}, 18, \
        (sfVector2f){17 * 33, 18 * 33});
    event[6] = set_teleport(18, (sfVector2f){17 * 33, 19 * 33}, 2, \
        (sfVector2f){10.5 * 33, 16 * 33});
    event[7] = set_teleport(10, (sfVector2f){19 * 33, 5 * 33}, 19, \
        (sfVector2f){15.5 * 33, 16 * 33});
    event[8] = set_teleport(19, (sfVector2f){15 * 33, 17 * 33}, 10, \
        (sfVector2f){19 * 33, 6 * 33});
}

static void init_quest(evt_t *event)
{
    event[9].active = sfTrue;
    event[9].always_active = sfFalse;
    event[9].is_fight = sfFalse;
    event[9].offset_map = 10;
    event[9].pos = (sfVector2f){19 * 33, 6 * 33};
    event[9].sprite = create_sprite(SPRITESHEET_FARMER, \
        &(sfIntRect){33, 0, 33, 33});
    sfSprite_setPosition(event[9].sprite, event[9].pos);
    event[9].dialogue = set_dialogue_farmer();
    event[9].offset_dialogue = 0;
    event[10].active = sfTrue;
    event[10].always_active = sfFalse;
    event[10].is_fight = sfTrue;
    event[10].enemy = set_enemy(SLIME, FP_SLIME);
    event[10].offset_map = 10;
    event[10].pos = (sfVector2f){14 * 33, 5 * 33};
    event[10].sprite = create_sprite(FP_SLIME, \
        &(sfIntRect){390, 70, 264, 264});
}

evt_t *init_event(void)
{
    evt_t *event = malloc(sizeof(evt_t) * 12);

    init_teleport(event);
    init_quest(event);
    sfSprite_setScale(event[10].sprite, (sfVector2f){0.125, 0.125});
    sfSprite_setPosition(event[10].sprite, event[10].pos);
    event[11].pos = (sfVector2f){-1, -1};
    return (event);
}