/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** status.c
*/

#include "utils.h"
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

static void draw_stats(obj_t *obj)
{
    stat_t stat = obj->perso->stat;

    print_text(obj->window, my_itoa(stat.level), sfWhite, \
        (sfVector2f){775, 40});
    print_text(obj->window, my_itoa(stat.pv), sfWhite, \
        (sfVector2f){775, 130});
    print_text(obj->window, my_itoa(stat.mana), sfWhite, \
        (sfVector2f){775, 220});
    print_text(obj->window, my_itoa(stat.att), sfWhite, \
        (sfVector2f){775, 310});
    print_text(obj->window, my_itoa(stat.att_spe), sfWhite, \
        (sfVector2f){775, 400});
    print_text(obj->window, my_itoa(stat.def), sfWhite, \
        (sfVector2f){775, 490});
    print_text(obj->window, my_itoa(stat.def_spe), sfWhite, \
        (sfVector2f){775, 580});
}

void in_status(obj_t *obj)
{
    sfSprite *perso = create_sprite(BIG_FACE, NULL);
    sfSprite *bg = create_sprite(FP_STATUS, NULL);

    sfSleep((sfTime){100000});
    sfSprite_setPosition(perso, (sfVector2f){166, 213});
    while (sfRenderWindow_isOpen(obj->window) && \
        sfKeyboard_isKeyPressed(STATUS) == sfFalse) {
        close_window(obj->window);
        sfRenderWindow_drawSprite(obj->window, bg, NULL);
        sfRenderWindow_drawSprite(obj->window, perso, NULL);
        draw_stats(obj);
        sfRenderWindow_display(obj->window);
    }
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(bg));
    sfSprite_destroy(bg);
}