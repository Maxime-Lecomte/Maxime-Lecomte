/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-louison.kalifa
** File description:
** initialization.c
*/

#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static void init_button(button_t *button, char *filepath, int which_height, \
    int y)
{
    button->pos = (sfVector2f){150, y};
    button->rect = (sfIntRect){0, which_height * 105, 166, 105};
    button->button_unpressed = sfTexture_createFromFile(filepath, \
        &button->rect);
    button->rect.left += 166;
    button->button_pressed = sfTexture_createFromFile(filepath, &button->rect);
    button->rect = (sfIntRect){button->pos.x, button->pos.y, \
        button->rect.width, button->rect.height};
    button->sprite = sfSprite_create();
    sfSprite_setPosition(button->sprite, button->pos);
}

button_t **init_all_button(void)
{
    button_t **button = malloc(sizeof(button_t *) * 6);
    int i = 0;

    if (button == NULL)
        return NULL;
    while (i < 5) {
        button[i] = malloc(sizeof(button_t));
        if (button[i] == NULL)
            return NULL;
        i++;
    }
    for (int i = 0; i < 5; ++i)
        init_button(button[i], FP_BUTTON_MENU, i, 47 + 115 * i);
    button[i] = NULL;
    return (button);
}