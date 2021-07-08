/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-louison.kalifa
** File description:
** toolbar.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static button_t **init_button_settings(void)
{
    button_t **button = malloc(sizeof(button_t *) * 4);

    for (int i = 0; i < 4; ++i)
        button[i] = malloc(sizeof(button_t));
    create_button(button[0], FP_BUTTON_SETTINGS, \
        (sfIntRect){0, 50, 150, 50}, (sfVector2f){315, 235});
    create_button(button[1], FP_BUTTON_SETTINGS, \
        (sfIntRect){0, 150, 150, 150}, (sfVector2f){647, 185});
    create_button(button[2], FP_BUTTON_SETTINGS, \
        (sfIntRect){0, 300, 366, 150}, (sfVector2f){45, 526});
    button[3] = NULL;
    return (button);
}

static bool manage_click_settings(sfRenderWindow *window, button_t **button, \
    sfMusic *music)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    if (sfIntRect_contains(&button[0]->rect, mse.x, mse.y))
        decrease_volume(music);
    if (sfIntRect_contains(&button[1]->rect, mse.x, mse.y))
        increase_volume(music);
    if (sfIntRect_contains(&button[2]->rect, mse.x, mse.y))
        return 1;
    return 0;
}

static bool analyse_event_settings(sfRenderWindow *window, button_t **button, \
    sfMusic *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft)
            return (manage_click_settings(window, button, music));
    }
    return false;
}

static void highlight_button_settings(sfRenderWindow *window, button_t \
    **button)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; button[i] != NULL; ++i) {
        sfSprite_setTexture(button[i]->sprite, button[i]->button_unpressed, \
            sfTrue);
        if (sfIntRect_contains(&button[i]->rect, mse.x, mse.y))
            sfSprite_setTexture(button[i]->sprite, button[i]->button_pressed, \
                sfTrue);
    }
}

void in_settings(sfRenderWindow *window, sfMusic *music)
{
    button_t **button = init_button_settings();
    sfSprite *bg = create_sprite(FP_SETTINGS, NULL);

    while (sfRenderWindow_isOpen(window)) {
        if (analyse_event_settings(window, button, music) == true)
            return;
        highlight_button_settings(window, button);
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, button[0]->sprite, NULL);
        sfRenderWindow_drawSprite(window, button[1]->sprite, NULL);
        sfRenderWindow_drawSprite(window, button[2]->sprite, NULL);
        sfRenderWindow_display(window);
    }
}