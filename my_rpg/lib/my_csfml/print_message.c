/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** print_message.c
*/

#include "my_csfml.h" 
#include "macro_rpg.h"
#include <SFML/Graphics.h>

void print_message(sfRenderWindow *window, char *string, sfColor color, \
    sfVector2f pos)
{
    sfSprite *text_box = create_sprite(FP_TEXTBOX, NULL);

    sfSprite_setPosition(text_box, (sfVector2f){0, 395});
    sfRenderWindow_drawSprite(window, text_box, NULL);
    print_text(window, string, color, pos);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(text_box));
    sfSprite_destroy(text_box);
}