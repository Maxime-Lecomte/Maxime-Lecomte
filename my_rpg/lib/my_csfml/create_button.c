/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** create_button.c
*/

#include "struct_rpg.h"
#include <SFML/Graphics.h>

void create_button(button_t *button, char *filepath, sfIntRect rect, \
    sfVector2f pos)
{
    button->pos = (sfVector2f){pos.x, pos.y};
    button->rect = rect;
    button->button_unpressed = sfTexture_createFromFile(filepath, \
        &button->rect);
    button->rect.left += rect.width;
    button->button_pressed = sfTexture_createFromFile(filepath, &button->rect);
    button->rect = (sfIntRect){button->pos.x, button->pos.y, \
        button->rect.width, button->rect.height};
    button->sprite = sfSprite_create();
    sfSprite_setTexture(button->sprite, button->button_unpressed, sfTrue);
    sfSprite_setPosition(button->sprite, button->pos);
}