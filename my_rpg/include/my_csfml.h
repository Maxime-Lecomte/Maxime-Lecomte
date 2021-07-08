/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** my_csfml.h
*/

#include "struct_rpg.h"
#include <SFML/Graphics.h>

#ifndef MY_CSFML
#define MY_CSFML

sfSprite *copy_bg(sfRenderWindow *window, sfSprite *sprite1, \
    sfSprite *sprite2, sfSprite *sprite3);
sfSprite *create_sprite(char *filepath, sfIntRect *rect);
sfRenderWindow *create_window(void);
void trans_to_black(sfRenderWindow *window);
void trans_to_picture(sfRenderWindow *window, sfSprite *sprite);
void print_text(sfRenderWindow *window, char *string, sfColor color, \
    sfVector2f pos);
void print_message(sfRenderWindow *window, char *string, sfColor color, \
    sfVector2f pos);
void create_button(button_t *button, char *filepath, sfIntRect rect, \
    sfVector2f pos);

#endif