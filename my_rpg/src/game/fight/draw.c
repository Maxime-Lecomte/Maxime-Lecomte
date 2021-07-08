/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** draw.c
*/

#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <SFML/Graphics.h>

static void update_sprite(sfRenderWindow *window, sfSprite *button, \
    sfVector2f pos)
{
    sfVector2i mse = sfMouse_getPositionRenderWindow(window);

    sfSprite_setPosition(button, pos);
    if (sfIntRect_contains(&((sfIntRect){pos.x, pos.y, 250, 50}), mse.x, mse.y))
        sfSprite_setTextureRect(button, (sfIntRect){0, 50, 250, 50});
    else
        sfSprite_setTextureRect(button, (sfIntRect){0, 0, 250, 50});
}

static void draw_button(obj_t *obj)
{
    sfIntRect fightbutton_rect = {0, 0, 250, 50};
    sfSprite *button = create_sprite(FIGHT_BUTTON, &fightbutton_rect);
    sfVector2f pos = {119, 479};

    update_sprite(obj->window, button, pos);
    sfRenderWindow_drawSprite(obj->window, button, NULL);
    update_sprite(obj->window, button, (sfVector2f){pos.x + 275, pos.y});
    sfRenderWindow_drawSprite(obj->window, button, NULL);
    update_sprite(obj->window, button, (sfVector2f){pos.x + 600, pos.y});
    sfRenderWindow_drawSprite(obj->window, button, NULL);
    update_sprite(obj->window, button, (sfVector2f){pos.x, pos.y + 75});
    sfRenderWindow_drawSprite(obj->window, button, NULL);
    update_sprite(obj->window, button, (sfVector2f){pos.x + 275, pos.y + 75});
    sfRenderWindow_drawSprite(obj->window, button, NULL);
    update_sprite(obj->window, button, (sfVector2f){pos.x + 600, pos.y + 75});
    sfRenderWindow_drawSprite(obj->window, button, NULL);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(button));
    sfSprite_destroy(button);
}

void draw_name(obj_t *obj)
{
    char *att[5] = {"none", "water", "wind", "fire", "earth"};
    sfColor color[5] = {(sfColor){128, 128, 128, 255}, sfBlue, sfGreen, \
        sfRed, (sfColor){126, 102, 62, 255}};
    sfVector2f pos = {195, 486};
    int x1 = (obj->perso->id_attack1 == 2 || obj->perso->id_attack1 == 3 ? \
        10 : 0);
    int x2 = (obj->perso->id_attack2 == 2 || obj->perso->id_attack2 == 3 ? \
        10 : 0);

    print_text(obj->window, "attack", sfBlack, pos);
    print_text(obj->window, att[obj->perso->id_attack1], \
        color[obj->perso->id_attack1], (sfVector2f){pos.x + 280 - x1, pos.y});
    print_text(obj->window, "objects", (sfColor){128, 128, 0, 255}, \
        (sfVector2f){pos.x + 585, pos.y});
    print_text(obj->window, "protect", sfBlack, (sfVector2f){pos.x - \
        10, pos.y + 75});
    print_text(obj->window, att[obj->perso->id_attack2], \
        color[obj->perso->id_attack2], (sfVector2f){pos.x + 280 - \
        x2, pos.y + 75});
    print_text(obj->window, "escape", sfRed, \
        (sfVector2f){pos.x + 595, pos.y + 75});
}

void draw_stat(obj_t *obj)
{
    sfSprite *pv[2] = {create_sprite(FP_BAR_STAT, \
        &(sfIntRect){0, 0, 400, 25}), create_sprite(FP_BAR_STAT, \
        &(sfIntRect){0, 50, obj->perso->stat.pv * 400 / \
        obj->perso->stat.pv_max, 25})};
    sfSprite *mana[2] = {create_sprite(FP_BAR_STAT, \
        &(sfIntRect){0, 25, 400, 25}), create_sprite(FP_BAR_STAT, \
        &(sfIntRect){0, 75, obj->perso->stat.mana * 400 / \
        obj->perso->stat.mana_max, 25})};

    for (int i = 0; i < 2; ++i) {
        sfSprite_setPosition(pv[i], (sfVector2f){119, 430});
        sfSprite_setPosition(mana[i], (sfVector2f){569, 430});
        sfRenderWindow_drawSprite(obj->window, pv[i], NULL);
        sfRenderWindow_drawSprite(obj->window, mana[i], NULL);
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(pv[i]));
        sfTexture_destroy((sfTexture *)sfSprite_getTexture(mana[i]));
        sfSprite_destroy(pv[i]);
        sfSprite_destroy(mana[i]);
    }
}

void draw_all(obj_t *obj, enemy_t *enemy, sfSprite *bg, sfSprite *scene)
{
    if (enemy->stat.pv > 0)
        sfRenderWindow_drawSprite(obj->window, scene, NULL);
    else
        sfRenderWindow_drawSprite(obj->window, bg, NULL);
    draw_button(obj);
    draw_name(obj);
    draw_stat(obj);
}