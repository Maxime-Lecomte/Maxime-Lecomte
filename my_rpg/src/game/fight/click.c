/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** click.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static bool which_action(obj_t *obj, enemy_t *enemy, int idx)
{
    if (idx == 0)
        attack(obj, enemy, 0);
    if (idx == 1 && obj->perso->stat.mana >= 10 * obj->perso->id_attack1)
        attack(obj, enemy, 1);
    if (idx == 2)
        return false;
    if (idx == 3)
        protect(obj->window);
    if (idx == 4 && obj->perso->stat.mana >= 10 * obj->perso->id_attack2)
        attack(obj, enemy, 2);
    if (idx == 5)
        return true;
    return false;
}

static bool is_action(obj_t *obj, enemy_t *enemy)
{
    sfIntRect rect[6] = {{119, 479, 250, 50}, {119 + 275, 479, 250, 50}, \
        {119 + 600, 479, 250, 50}, {119, 479 + 75, 250, 50}, {119 + 275, \
        479 + 75, 250, 50}, {119 + 600, 479 + 75, 250, 50}};
    sfVector2i mse = sfMouse_getPositionRenderWindow(obj->window);

    for (int i = 0; i < 6; ++i) {
        if (sfIntRect_contains(&rect[i], mse.x, mse.y))
            return (which_action(obj, enemy, i));
    }
    return false;
}

static bool check_win_or_lose(obj_t *obj, enemy_t *enemy)
{
    if (obj->perso->stat.pv < 0) {
        print_message(obj->window, "YOU DIED !", sfRed, \
            (sfVector2f){450, 510});
        sfRenderWindow_display(obj->window);
        sfSleep((sfTime){2000000});
        return true;
    } else if (enemy->stat.pv < 0) {
        print_message(obj->window, "YOU WIN !", sfGreen, \
            (sfVector2f){450, 510});
        sfRenderWindow_display(obj->window);
        sfSleep((sfTime){2000000});
        return true;
    }
    return false;
}

bool analyse_event_fight(obj_t *obj, enemy_t *enemy, sfSprite *bg, sfSprite \
    *scene)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(obj->window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(obj->window);
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft && is_action(obj, enemy) == true)
            return true;
    }
    draw_all(obj, enemy, bg, scene);
    return (check_win_or_lose(obj, enemy));
}