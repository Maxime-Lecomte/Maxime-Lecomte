/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** draw.c
*/

#include "struct_rpg.h"
#include <SFML/Graphics.h>

void draw_menu(sfRenderWindow *window, sfSprite *bg, button_t **button)
{
    sfRenderWindow_drawSprite(window, bg, NULL);
    for (int i = 0; i < 5; i++)
        sfRenderWindow_drawSprite(window, button[i]->sprite, NULL);
}