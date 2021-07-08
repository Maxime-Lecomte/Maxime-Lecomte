/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** analyse_event.c
*/

#include "rpg.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static bool manage_click_pause(obj_t *obj, sfSprite **button)
{
    int i = 0;
    sfVector2f pos = {0, 0};
    sfIntRect rect = {0, 0, 237, 50};
    sfVector2i mse = sfMouse_getPositionRenderWindow(obj->window);

    for (i = 0; button[i] != NULL; ++i) {
        pos = sfSprite_getPosition(button[i]);
        rect = (sfIntRect){pos.x, pos.y, rect.width, rect.height};
        if (sfIntRect_contains(&rect, mse.x, mse.y))
            break;
    }
    if (i == 0 || i == 6)
        return (true);
    if (i == 1)
        in_settings(obj->window, obj->music);
    if (i == 2)
        in_controls(obj->window);
    if (i == 5)
        sfRenderWindow_close(obj->window);
    return (false);
}

bool analyse_event_pause(obj_t *obj, sfSprite **button)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(obj->window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(obj->window);
            return (false);
        }
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft && manage_click_pause(obj, button) == true) {
            return (true);
        }
    }
    if (sfKeyboard_isKeyPressed(PAUSE) == sfTrue)
        return (true);
    return (false);
}