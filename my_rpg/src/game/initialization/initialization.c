/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** initialization.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static obj_t *init_obj(sfRenderWindow *window, sfMusic *music)
{
    obj_t *obj = malloc(sizeof(obj_t));

    obj->offset = 13;
    obj->event = init_event();
    obj->map = init_map();
    obj->box = init_block();
    obj->box[NB_MAP + NB_INSIDE] = NULL;
    obj->perso = init_perso();
    obj->music = music;
    obj->window = window;
    return (obj);
}

obj_t *init_game_data(sfRenderWindow *window, char *filepath, sfMusic *music)
{
    (void)filepath;
    obj_t *obj = init_obj(window, music);

    return (obj);
}