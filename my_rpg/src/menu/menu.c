/*
** EPITECH PROJECT, 2020
** B-MUL-200-BDX-2-1-mydefender-louison.kalifa
** File description:
** start_game.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

static void free_all(sfRenderWindow *window, button_t **button, sfSprite *bg)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(bg));
    sfSprite_destroy(bg);
    for (int i = 0; button[i] != NULL; ++i) {
        sfTexture_destroy(button[i]->button_unpressed);
        sfTexture_destroy(button[i]->button_pressed);
        sfSprite_destroy(button[i]->sprite);
        free(button[i]);
    }
    free(button);
    sfRenderWindow_destroy(window);
}

static void highlight_button(sfRenderWindow *window, button_t **button)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    for (int i = 0; i < 5; ++i) {
        sfSprite_setTexture(button[i]->sprite, button[i]->button_unpressed, \
            sfTrue);
        if (sfIntRect_contains(&button[i]->rect, mse.x, mse.y))
            sfSprite_setTexture(button[i]->sprite, button[i]->button_pressed, \
                sfTrue);
    }
}

int in_menu(void)
{
    sfRenderWindow *window = create_window();
    button_t **button = init_all_button();
    sfSprite *bg = create_sprite(FP_MENU, NULL);
    sfMusic *music = open_music(FP_MUSIC);

    play_music(music, 5);
    while (sfRenderWindow_isOpen(window)) {
        analyse_event(window, button, music);
        highlight_button(window, button);
        draw_menu(window, bg, button);
        sfRenderWindow_display(window);
    }
    close_music(music);
    free_all(window, button, bg);
    return 0;
}