/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-myrpg-louison.kalifa
** File description:
** control.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static void highlight_button(sfRenderWindow *window, button_t *button)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    sfSprite_setTexture(button->sprite, button->button_unpressed, sfTrue);
    if (sfIntRect_contains(&button->rect, mse.x, mse.y))
        sfSprite_setTexture(button->sprite, button->button_pressed, sfTrue);
}

static bool analyse_event_controls(sfRenderWindow *window)
{
    sfEvent event;
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft && mse.x > 15 && mse.x < 150 && mse.y > 15 && \
            mse.y < 150)
            return true;
        if (event.type == sfEvtClosed)
            return true;
    }
    return false;
}

void in_controls(sfRenderWindow *window)
{
    button_t *button_close = malloc(sizeof(button_t));
    sfSprite *bg = create_sprite(FP_CONTROLS, NULL);

    create_button(button_close, FP_BUTTON_CLOSE, (sfIntRect){0, 0, 100, 100}, \
        (sfVector2f){0, 0});
    while (sfRenderWindow_isOpen(window)) {
        if (analyse_event_controls(window) == true)
            return;
        sfRenderWindow_drawSprite(window, bg, NULL);
        highlight_button(window, button_close);
        sfRenderWindow_drawSprite(window, button_close->sprite, NULL);
        sfRenderWindow_display(window);
    }
}