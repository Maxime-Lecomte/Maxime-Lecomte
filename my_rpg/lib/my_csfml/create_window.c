/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** create_window.c
*/

#include <SFML/Graphics.h>

sfRenderWindow *create_window(void)
{
    sfRenderWindow *window = sfRenderWindow_create((sfVideoMode){1089, 660, \
        32}, "Aucune Idée", sfClose, NULL);
    
    return (window);
}