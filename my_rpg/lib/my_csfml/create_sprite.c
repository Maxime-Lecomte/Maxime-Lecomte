/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** create_sprite.c
*/

#include <SFML/Graphics.h>

sfSprite *create_sprite(char *filepath, sfIntRect *rect)
{
    sfSprite *sprite = sfSprite_create();
    sfTexture *texture = sfTexture_createFromFile(filepath, NULL);

    sfSprite_setTexture(sprite, texture, sfFalse);
    if (rect != NULL)
        sfSprite_setTextureRect(sprite, *rect);
    return (sprite);
}