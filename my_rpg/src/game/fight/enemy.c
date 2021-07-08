/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** enemy.c
*/

#include "my_csfml.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static stat_t set_stat_enemy(int id)
{
    stat_t stat;

    stat.pv = 100 * id;
    stat.pv_max = 100 * id;
    stat.mana = 100 * id;
    stat.mana_max = 100 * id;
    stat.att = 10 * id;
    stat.att_spe = 10 * id;
    stat.def = 10 * id;
    stat.def_spe = 10 * id;
    return (stat);
}

enemy_t *set_enemy(int id, char *filepath)
{
    enemy_t *enemy = malloc(sizeof(enemy_t));

    enemy->id = id;
    enemy->sprite = create_sprite(filepath, NULL);
    enemy->stat = set_stat_enemy(id);
    return (enemy);
}