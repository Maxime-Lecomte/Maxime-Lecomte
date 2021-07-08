/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** drag.c
*/

#include "my_csfml.h"
#include "utils.h"
#include "struct_rpg.h"
#include <SFML/Graphics.h>

static void draw_items(sfRenderWindow *window, perso_t *perso, sfVector2i \
    swap_and_i, int idx)
{
    if (swap_and_i.x == 0 && perso->items[swap_and_i.y].id != -1 && \
        swap_and_i.y != idx)
        sfSprite_setPosition(perso->items[swap_and_i.y].sprite, \
            (sfVector2f){234 + ((swap_and_i.y % 7) * 72), 281 + \
            ((swap_and_i.y / 7) * 72)});
    else if (swap_and_i.x == 1 && perso->items[swap_and_i.y].id != -1)
        sfSprite_setPosition(perso->items[swap_and_i.y].sprite, \
            (sfVector2f){234 + ((swap_and_i.y % 7) * 72), 281 + \
            ((swap_and_i.y / 7) * 72)});
    if (perso->items[swap_and_i.y].id != -1)
        sfRenderWindow_drawSprite(window, perso->items[swap_and_i.y].sprite, \
            NULL);
}

static void draw_equipped_items(sfRenderWindow *window, perso_t *perso, \
    sfVector2i swap_and_i, int idx)
{
    if (swap_and_i.x == 1 && perso->equipped_item[swap_and_i.y].id != -1 && \
        swap_and_i.y != idx) {
        if (swap_and_i.y < 2)
            sfSprite_setPosition(perso->equipped_item[swap_and_i.y].sprite, \
                (sfVector2f){783, 70 + swap_and_i.y * 109});
        else
            sfSprite_setPosition(perso->equipped_item[swap_and_i.y].sprite, \
                (sfVector2f){783, 281 + (swap_and_i.y - 2) * 72});
        sfRenderWindow_drawSprite(window, \
            perso->equipped_item[swap_and_i.y].sprite, NULL);
    } else if (swap_and_i.x == 0 && perso->equipped_item[swap_and_i.y].id \
        != -1) {
        if (swap_and_i.y < 2)
            sfSprite_setPosition(perso->equipped_item[swap_and_i.y].sprite, \
                (sfVector2f){783, 70 + swap_and_i.y * 109});
        else
            sfSprite_setPosition(perso->equipped_item[swap_and_i.y].sprite, \
                (sfVector2f){783, 281 + (swap_and_i.y - 2) * 72});
        sfRenderWindow_drawSprite(window, \
            perso->equipped_item[swap_and_i.y].sprite, NULL);
    }
}

static void draw_all_items(sfRenderWindow *window, perso_t *perso, int swap, \
    int idx)
{
    for (int i = 0; i < 28; ++i)
        draw_items(window, perso, (sfVector2i){swap, i}, idx);
    for (int i = 0; i < 6; ++i)
        draw_equipped_items(window, perso, (sfVector2i){swap, i}, idx);
}

void while_click_pressed(sfRenderWindow *window, perso_t *perso, sfSprite *bg, \
    int idx)
{
    sfVector2f pos = {0, 0};
    int swap = (sfMouse_getPositionRenderWindow(window).x > 780 ? 1 : 0);

    while (sfMouse_isButtonPressed(sfMouseLeft)) {
        pos = (sfVector2f){sfMouse_getPositionRenderWindow(window).x - 34, \
            sfMouse_getPositionRenderWindow(window).y - 34};
        sfRenderWindow_drawSprite(window, bg, NULL);
        print_text(window, my_itoa(perso->gold), (sfColor){128, \
            128, 0, 255}, (sfVector2f){370, 205});
        draw_all_items(window, perso, swap, idx);
        if (swap == 0) {
            sfSprite_setPosition(perso->items[idx].sprite, pos);
            sfRenderWindow_drawSprite(window, perso->items[idx].sprite, NULL);
        } else {
            sfSprite_setPosition(perso->equipped_item[idx].sprite, pos);
            sfRenderWindow_drawSprite(window, \
                perso->equipped_item[idx].sprite, NULL);
        }
        sfRenderWindow_display(window);
    }
}