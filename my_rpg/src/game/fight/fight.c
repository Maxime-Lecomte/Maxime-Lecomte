/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** fight.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static void free_fight_obj(sfSprite *bg, sfSprite *save_bg, sfSprite *scene, \
    enemy_t *enemy)
{
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(enemy->sprite));
    sfSprite_destroy(enemy->sprite);
    free(enemy);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(bg));
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(save_bg));
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(scene));
    sfSprite_destroy(bg);
    sfSprite_destroy(save_bg);
    sfSprite_destroy(scene);
}

static sfSprite *init_scene(obj_t *obj, enemy_t *enemy, sfSprite *bg)
{
    sfSprite *scene = NULL;

    sfRenderWindow_drawSprite(obj->window, bg, NULL);
    draw_name(obj);
    draw_stat(obj);
    scene = copy_bg(obj->window, enemy->sprite, NULL, NULL);
    return (scene);
}

static void fight_loop(obj_t *obj, enemy_t *enemy)
{
    sfSprite *bg = create_sprite(BG_SNOW, NULL);
    sfSprite *save_bg = copy_bg(obj->window, NULL, NULL, NULL);
    sfSprite *scene = init_scene(obj, enemy, bg);

    sfRenderWindow_drawSprite(obj->window, save_bg, NULL);
    trans_to_picture(obj->window, scene);
    while (sfRenderWindow_isOpen(obj->window)) {
        if (analyse_event_fight(obj, enemy, bg, scene) == true)
            break;
        draw_all(obj, enemy, bg, scene);
        sfRenderWindow_display(obj->window);
    }
    if (obj->perso->stat.pv > 0)
        obj->perso->stat.pv = obj->perso->stat.pv_max;
    obj->perso->stat.mana = obj->perso->stat.mana_max;
    if (sfRenderWindow_isOpen(obj->window))
        trans_to_black(obj->window);
    free_fight_obj(bg, save_bg, scene, enemy);
}

void in_fight(obj_t *obj, enemy_t *enemy)
{
    sfSprite *bg = copy_bg(obj->window, NULL, NULL, NULL);

    trans_to_black(obj->window);
    fight_loop(obj, enemy);
    trans_to_picture(obj->window, bg);
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(bg));
    sfSprite_destroy(bg);
}