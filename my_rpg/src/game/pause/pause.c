/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** pause.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "struct_rpg.h"
#include "macro_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static void end_pause(obj_t *obj, sfSprite *bg, sfSprite *pause, sfSprite \
    **button)
{
    if (sfRenderWindow_isOpen(obj->window)) {
        sfRenderWindow_drawSprite(obj->window, obj->map[obj->offset], NULL);
        sfRenderWindow_drawSprite(obj->window, obj->perso->sprite, NULL);
        sfRenderWindow_display(obj->window);
    }
    for (int i = 0; button[i] != NULL; ++i) {
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(button[i]));
        sfSprite_destroy(button[i]);
    }
    free(button);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(bg));
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(pause));
    sfSprite_destroy(bg);
    sfSprite_destroy(pause);
}

static sfSprite **set_button(void)
{
    sfVector2f pos = {426, 143};
    sfIntRect rect = {0, 0, 237, 50};
    sfSprite **button = malloc(sizeof(sfSprite *) * 8);

    for (int i = 0; i < 6; ++i) {
        button[i] = create_sprite(FP_BUTTON, &rect);
        sfSprite_setPosition(button[i], pos);
        pos.y += 58;
        rect.top += 50;
    }
    rect = (sfIntRect){0, 300, 45, 45};
    button[6] = create_sprite(FP_BUTTON, &rect);
    sfSprite_setPosition(button[6], (sfVector2f){697, 51});
    button[7] = NULL;
    return (button);
}

static void mse_position(obj_t *obj, sfSprite **button)
{
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 237, 50};
    sfVector2i mse = sfMouse_getPositionRenderWindow(obj->window);

    for (int i = 0; i < 6; ++i) {
        pos = sfSprite_getPosition(button[i]);
        rect = (sfIntRect){pos.x, pos.y, rect.width, rect.height};
        if (sfIntRect_contains(&rect, mse.x, mse.y))
            sfRenderWindow_drawSprite(obj->window, button[i], NULL);
    }
}

void pause_menu(obj_t *obj)
{
    sfSprite *bg = NULL;
    sfSprite *pause = create_sprite(FP_PAUSE, NULL);
    sfSprite **button = set_button();

    sfSleep((sfTime){100000});
    bg = copy_bg(obj->window, obj->map[obj->offset], obj->perso->sprite, \
        pause);
    while (sfRenderWindow_isOpen(obj->window)) {
        sfRenderWindow_drawSprite(obj->window, bg, NULL);
        mse_position(obj, button);
        sfRenderWindow_display(obj->window);
        if (analyse_event_pause(obj, button) == true) {
            end_pause(obj, bg, pause, button);
            return;
        }
    }
    end_pause(obj, bg, pause, button);
}