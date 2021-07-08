/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** teleport.c
*/

#include "my_csfml.h"
#include <SFML/Graphics.h>

void teleport(sfRenderWindow *window, sfSprite *character, sfSprite *map, \
    sfVector2f pos)
{
    sfSprite *map_with_player = NULL;

    trans_to_black(window);
    sfSprite_setPosition(character, (sfVector2f){pos.x, pos.y});
    map_with_player = copy_bg(window, map, character, NULL);
    sfRenderWindow_clear(window, sfBlack);
    trans_to_picture(window, map_with_player);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(map_with_player));
    sfSprite_destroy(map_with_player);
}