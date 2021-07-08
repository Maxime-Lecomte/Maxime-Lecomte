/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** delete.c
*/

#include "my_csfml.h"
#include "struct_rpg.h"
#include "macro_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static bool manage_click(sfRenderWindow *window, perso_t *perso, int idx, \
    bool is_equiped)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);
    item_t item_tmp = {-1, -1, 0, NULL};

    if (is_equiped == true)
        item_tmp.equipable = perso->equipped_item[idx].equipable;
    if (sfIntRect_contains(&((sfIntRect){348, 335, 145, 57}), mse.x, mse.y) \
        && is_equiped == true) {
        perso->equipped_item[idx] = item_tmp;
        return true;
    }
    if (sfIntRect_contains(&((sfIntRect){348, 335, 145, 57}), mse.x, mse.y) \
        && is_equiped == false) {
        perso->items[idx] = item_tmp;
        return true;
    }
    if (sfIntRect_contains(&((sfIntRect){543, 335, 145, 57}), mse.x, mse.y))
        return true;
    return false;
}

static bool analyse_event_delete(sfRenderWindow *window, perso_t *perso, \
    int idx, bool is_equiped)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft && manage_click(window, perso, idx, is_equiped) \
            == true)
            return true;
    }
    return false;
}

void delete_item(sfRenderWindow *window, perso_t *perso, int idx, \
    bool is_equiped)
{
    sfSprite *sprite = create_sprite(FP_DELETE, NULL);
    sfSprite *bg = sfSprite_create();
    sfTexture *texture = sfTexture_create(1089, 660);

    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfSprite_setTexture(bg, texture, sfTrue);
    while (sfRenderWindow_isOpen(window)) {
        if (analyse_event_delete(window, perso, idx, is_equiped) == true)
            break;
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
    }
}