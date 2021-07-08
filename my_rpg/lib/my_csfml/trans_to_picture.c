/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** trans_to_picture.c
*/

#include <SFML/Graphics.h>

void trans_to_picture(sfRenderWindow *window, sfSprite *sprite)
{
    sfSprite *bg = sfSprite_create();
    sfTexture *texture = sfTexture_create(1089, 660);

    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfSprite_setTexture(bg, texture, sfTrue);
    for (int i = 255; i > 0; i = i - 2) {
        sfSprite_setColor(bg, (sfColor){255, 255, 255, i});
        sfSprite_setColor(sprite, (sfColor){255, 255, 255, 255 - i});
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_drawSprite(window, sprite, NULL);
        sfRenderWindow_display(window);
        sfSleep((sfTime){10000});
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(bg);
}