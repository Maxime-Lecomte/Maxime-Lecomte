/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** print_map.c
*/

#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <SFML/Graphics.h>

static void close_window(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
    }
}

void print_map(obj_t *obj)
{
    sfSprite *perso = create_sprite(FP_REDBLOCK, NULL);
    sfSprite *map = create_sprite(FP_MAP, NULL);

    sfSleep((sfTime){100000});
    sfSprite_setPosition(perso, (sfVector2f){((obj->offset % 4) * 33 + \
        obj->perso->pos.x / 33) * 8.25, ((obj->offset / 4) * 20 + \
        obj->perso->pos.y / 33) * 8.25});
    while (sfRenderWindow_isOpen(obj->window) && \
        sfKeyboard_isKeyPressed(MAP) == sfFalse) {
        close_window(obj->window);
        sfRenderWindow_drawSprite(obj->window, map, NULL);
        sfRenderWindow_drawSprite(obj->window, perso, NULL);
        sfRenderWindow_display(obj->window);
    }
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(map));
    sfSprite_destroy(map);
}