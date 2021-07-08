/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** game.c
*/

#include "rpg.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>

/****************************PROVISOIRE****************************/
static void set_armor(obj_t *obj)
{
    obj->perso->equipped_item[2].id = IRON_HELMET;
    obj->perso->equipped_item[2].count = 1;
    obj->perso->equipped_item[2].equipable = 3;
    obj->perso->equipped_item[2].sprite = create_sprite(FP_HELMET, NULL);
    obj->perso->equipped_item[3].id = IRON_CHESTPLATE;
    obj->perso->equipped_item[3].count = 1;
    obj->perso->equipped_item[3].equipable = 4;
    obj->perso->equipped_item[3].sprite = create_sprite(FP_CHESTPLATE, NULL);
    obj->perso->equipped_item[4].id = IRON_PANTS;
    obj->perso->equipped_item[4].count = 1;
    obj->perso->equipped_item[4].equipable = 5;
    obj->perso->equipped_item[4].sprite = create_sprite(FP_LEGS, NULL);
    obj->perso->equipped_item[5].id = IRON_BOOTS;
    obj->perso->equipped_item[5].count = 1;
    obj->perso->equipped_item[5].equipable = 6;
    obj->perso->equipped_item[5].sprite = create_sprite(FP_BOOTS, NULL);
}

static void set_item(obj_t *obj)
{
    obj->perso->items[0].id = BREAD;
    obj->perso->items[0].count = 1;
    obj->perso->items[0].equipable = 0;
    obj->perso->items[0].sprite = create_sprite(FP_BREAD, NULL);
    obj->perso->equipped_item[0].id = MAGIC_SWORD;
    obj->perso->equipped_item[0].count = 1;
    obj->perso->equipped_item[0].equipable = 1;
    obj->perso->equipped_item[0].sprite = create_sprite(FP_SWORD, NULL);
    obj->perso->equipped_item[1].id = WOOD_SHIELD;
    obj->perso->equipped_item[1].count = 1;
    obj->perso->equipped_item[1].equipable = 2;
    obj->perso->equipped_item[1].sprite = create_sprite(FP_SHIELD, NULL);
    set_armor(obj);
}

void in_game(sfRenderWindow *window, char *filepath, sfMusic *music)
{
    char *seed = malloc(sizeof(char));
    obj_t *obj = init_game_data(window, filepath, music);

    set_item(obj);
    srand((unsigned int long)seed);
    sfRenderWindow_setFramerateLimit(obj->window, 120);
    while (sfRenderWindow_isOpen(obj->window)) {
        check_event(obj);
        sfRenderWindow_drawSprite(obj->window, obj->map[obj->offset], NULL);
        draw_event(obj);
        sfRenderWindow_drawSprite(obj->window, obj->perso->sprite, NULL);
        sfRenderWindow_display(obj->window);
        analyse_event_game(obj);
    }
    free(seed);
    free_obj(obj);
}