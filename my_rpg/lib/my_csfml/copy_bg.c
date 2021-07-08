/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** copy_bg.c
*/

#include <SFML/Graphics.h>

sfSprite *copy_bg(sfRenderWindow *window, sfSprite *sprite1, \
    sfSprite *sprite2, sfSprite *sprite3)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_create(1089, 660);

    if (sprite1 != NULL)
        sfRenderWindow_drawSprite(window, sprite1, NULL);
    if (sprite2 != NULL)
        sfRenderWindow_drawSprite(window, sprite2, NULL);
    if (sprite3 != NULL)
        sfRenderWindow_drawSprite(window, sprite3, NULL);
    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfSprite_setTexture(sprite, texture, sfTrue);
    return (sprite);
}