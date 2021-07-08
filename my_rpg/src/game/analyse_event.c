/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** analyse_event.c
*/

#include "rpg.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <SFML/Graphics.h>

static void key_move(obj_t *obj, sfEvent event)
{
    if (sfKeyboard_isKeyPressed(UP) == sfTrue) {
        obj->perso->move = (sfVector2f){0, -0.5};
        obj->perso->offset = 10;
    }
    if (sfKeyboard_isKeyPressed(LEFT) == sfTrue) {
        obj->perso->move = (sfVector2f){-0.5, 0};
        obj->perso->offset = 4;
    }
    if (sfKeyboard_isKeyPressed(DOWN) == sfTrue) {
        obj->perso->move = (sfVector2f){0, 0.5};
        obj->perso->offset = 1;
    }
    if (sfKeyboard_isKeyPressed(RIGHT) == sfTrue) {
        obj->perso->move = (sfVector2f){0.5, 0};
        obj->perso->offset = 7;
    }
    if (event.key.shift == sfTrue) {
        obj->perso->move.x *= 2;
        obj->perso->move.y *= 2;
    }
}

static void key_management(sfEvent event, obj_t *obj)
{
    key_move(obj, event);
    if (obj->perso->move.x != 0 || obj->perso->move.y != 0)
        move_sprite(obj);
    if (sfKeyboard_isKeyPressed(INTERACT) == sfTrue)
        interact(obj);
    if (sfKeyboard_isKeyPressed(STATUS) == sfTrue) {
        in_status(obj);
        sfSleep((sfTime){500000});
    }
    if (sfKeyboard_isKeyPressed(MAP) == sfTrue) {
        print_map(obj);
        sfSleep((sfTime){500000});
    }
    if (sfKeyboard_isKeyPressed(PAUSE) == sfTrue) {
        pause_menu(obj);
        sfSleep((sfTime){500000});
    }
    if (sfKeyboard_isKeyPressed(INVENTORY) == sfTrue) {
        in_inventory(obj);
        sfSleep((sfTime){500000});
    }
}

void analyse_event_game(obj_t *obj)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(obj->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->window);
        if (event.type == sfEvtKeyPressed)
            key_management(event, obj);
    }
}