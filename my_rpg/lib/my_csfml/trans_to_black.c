/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** trans_to_black.c
*/

#include <SFML/Graphics.h>

void trans_to_black(sfRenderWindow *window)
{
    sfSprite *bg = sfSprite_create();
    sfTexture *texture = sfTexture_create(1089, 660);

    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfSprite_setTexture(bg, texture, sfTrue);
    for (int i = 255; i > 0; i = i - 2) {
        sfSprite_setColor(bg, (sfColor){i, i, i, 255});
        sfRenderWindow_drawSprite(window, bg, NULL);
        sfRenderWindow_display(window);
        sfSleep((sfTime){10000});
    }
    sfTexture_destroy(texture);
    sfSprite_destroy(bg);
}