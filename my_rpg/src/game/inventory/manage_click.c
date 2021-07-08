/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** manage_click.c
*/

#include "rpg.h"
#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static void inventory(sfRenderWindow *window, perso_t *perso, sfSprite *bg)
{
    int i = 0;
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    for (i = 0; i < 28; ++i) {
        if (perso->items[i].id != -1 && sfIntRect_contains(\
            &((sfIntRect){sfSprite_getPosition(perso->items[i].sprite).x, \
            sfSprite_getPosition(perso->items[i].sprite).y, 68, 68}), mse.x, \
            mse.y)) {
            while_click_pressed(window, perso, bg, i);
            break;
        }
    }
    if (i == 28)
        return;
    mse = sfMouse_getPositionRenderWindow(window);
    if (mse.x > 234 && mse.x < 733 && mse.y > 281 && mse.y < 564)
        which_inventory(perso, mse, i, false);
    if (mse.x > 783 && mse.x < 851 && mse.y > 70 && mse.y < 564)
        which_equipment(perso, mse, i);
    if (mse.x < 207 || mse.x > 908 || mse.y < 21 || mse.y > 638)
        delete_item(window, perso, i, false);
}

static void equipment(sfRenderWindow *window, perso_t *perso, sfSprite *bg)
{
    int i = 0;
    sfVector2f pos = {0, 0};
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    for (i = 0; i < 6; ++i) {
        if (perso->equipped_item[i].id != -1)
            pos = sfSprite_getPosition(perso->equipped_item[i].sprite);
        if (perso->equipped_item[i].id != -1 && sfIntRect_contains(\
            &((sfIntRect){pos.x, pos.y, 68, 68}), mse.x, mse.y)) {
            while_click_pressed(window, perso, bg, i);
            break;
        }
    }
    if (i == 6)
        return;
    mse = sfMouse_getPositionRenderWindow(window);
    if (mse.x > 234 && mse.x < 733 && mse.y > 281 && mse.y < 564)
        which_inventory(perso, mse, i, true);
    if (mse.x < 207 || mse.x > 908 || mse.y < 21 || mse.y > 638)
        delete_item(window, perso, i, true);
}

void manage_click(sfRenderWindow *window, perso_t *perso, sfSprite *bg)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    if (mse.x < 780)
        inventory(window, perso, bg);
    else
        equipment(window, perso, bg);
}