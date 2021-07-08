/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** dialogue.c
*/

#include "macro_rpg.h"
#include "struct_rpg.h"
#include <malloc.h>
#include <SFML/Graphics.h>

static void dialog_go(sfRenderWindow *window, dialogue_t *dialogue, \
    sfText **text, int swap)
{
    int move = 20;
    int head = 1;

    if (swap == 1)
        move = -20;
    while (swap == 1 && dialogue->name[head] != NULL)
        ++head;
    --head;
    while (sfSprite_getPosition(dialogue->bar).x != swap * -1100) {
        sfRenderWindow_drawSprite(window, dialogue->background, NULL);
        sfSprite_move(dialogue->bar, (sfVector2f){move, 0});
        sfSprite_move(dialogue->head[head], (sfVector2f){move, 0});
        sfText_move(text[0], (sfVector2f){move, 0});
        sfText_move(text[1], (sfVector2f){move, 0});
        sfRenderWindow_drawSprite(window, dialogue->bar, NULL);
        sfRenderWindow_drawSprite(window, dialogue->head[head], NULL);
        sfRenderWindow_drawText(window, text[0], NULL);
        sfRenderWindow_drawText(window, text[1], NULL);
        sfRenderWindow_display(window);
    }
}

static void set_all(sfRenderWindow *window, dialogue_t *dialogue, \
    sfText **text)
{
    sfTexture *texture = sfTexture_create(1200, 675);

    text[0] = sfText_create();
    text[1] = sfText_create();
    sfTexture_updateFromRenderWindow(texture, window, 0, 0);
    sfSprite_setTexture(dialogue->background, texture, sfTrue);
    sfSprite_setPosition(dialogue->background, (sfVector2f){0, -15});
    sfText_setFont(text[0], sfFont_createFromFile(FONT));
    sfText_setString(text[0], dialogue->name[0]);
    sfText_setScale(text[0], (sfVector2f){0.75, 0.75});
    sfText_setColor(text[0], sfBlack);
    sfText_setFont(text[1], sfFont_createFromFile(FONT));
    sfText_setString(text[1], dialogue->dialogue[0]);
    sfText_setScale(text[1], (sfVector2f){0.75, 0.75});
    sfText_setColor(text[1], sfWhite);
    sfText_setPosition(text[0], (sfVector2f){-1100, 500});
    sfText_setPosition(text[1], (sfVector2f){-900, 560});
    sfSprite_setPosition(dialogue->bar, (sfVector2f){-1100, 500});
    sfSprite_setPosition(dialogue->head[0], (sfVector2f){-1038, 541});
}

static void analyse_event(sfRenderWindow *window, sfEvent event, int *i)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            *i = 7;
            sfRenderWindow_close(window);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            *i += 1;
    }
}

void do_dialogue(sfRenderWindow *window, dialogue_t *dialogue)
{
    int i = 0;
    sfEvent event;
    sfText **text = malloc(sizeof(sfText *) * 2);

    set_all(window, dialogue, text);
    dialog_go(window, dialogue, text, 0);
    while (dialogue->name[i] != NULL) {
        sfRenderWindow_drawSprite(window, dialogue->bar, NULL);
        sfSprite_setPosition(dialogue->head[i], (sfVector2f){62, 541});
        sfRenderWindow_drawSprite(window, dialogue->head[i], NULL);
        sfText_setString(text[0], dialogue->name[i]);
        sfText_setString(text[1], dialogue->dialogue[i]);
        sfRenderWindow_drawText(window, text[0], NULL);
        sfRenderWindow_drawText(window, text[1], NULL);
        sfRenderWindow_display(window);
        analyse_event(window, event, &i);
    }
    dialog_go(window, dialogue, text, 1);
    sfText_destroy(text[0]);
    sfText_destroy(text[1]);
    free(text);
}