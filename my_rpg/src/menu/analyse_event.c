/*
** EPITECH PROJECT, 2020
** Semestre 2
** File description:
** event.c
*/

#include "rpg.h"
#include "struct_rpg.h"
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static void click_menu(sfRenderWindow *window, button_t **button, \
    sfMusic *music)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    if (sfIntRect_contains(&button[0]->rect, mse.x, mse.y))
        in_game(window, NULL, music);
    if (sfIntRect_contains(&button[1]->rect, mse.x, mse.y))
        return;
    if (sfIntRect_contains(&button[2]->rect, mse.x, mse.y))
        in_settings(window, music);
    if (sfIntRect_contains(&button[3]->rect, mse.x, mse.y))
        in_controls(window);
    if (sfIntRect_contains(&button[4]->rect, mse.x, mse.y))
        sfRenderWindow_close(window);
}

void analyse_event(sfRenderWindow *window, button_t **button, sfMusic *music)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft)
            click_menu(window, button, music);
    }
}