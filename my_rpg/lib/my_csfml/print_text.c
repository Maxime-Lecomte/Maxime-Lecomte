/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** print_text.c
*/

#include "macro_rpg.h"
#include <SFML/Graphics.h>

void print_text(sfRenderWindow *window, char *string, sfColor color, \
    sfVector2f pos)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(FONT2);

    sfText_setFont(text, font);
    sfText_setString(text, string);
    sfText_setPosition(text, pos);
    sfText_setColor(text, color);
    sfRenderWindow_drawText(window, text, NULL);
    sfText_destroy(text);
    sfFont_destroy(font);
}