/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** struct.h
*/

#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#ifndef STRUCT_RPG
#define STRUCT_RPG

#include "enum_rpg.h"

typedef struct button button_t;

struct button {
    sfIntRect rect;
    sfVector2f pos;
    sfSprite *sprite;
    sfTexture *button_unpressed;
    sfTexture *button_pressed;
};

typedef struct item item_t;

struct item {
    int id;
    int count;
    int equipable;
    sfSprite *sprite;
};

typedef struct stat stat_t;

struct stat {
    int level;
    int exp;
    int exp_max;
    int pv;
    int pv_max;
    int mana;
    int mana_max;
    int att;
    int att_spe;
    int def;
    int def_spe;
};

typedef struct enemy enemy_t;

struct enemy {
    int id;
    stat_t stat;
    sfSprite *sprite;
};

typedef struct dialogue dialogue_t;

struct dialogue {
    sfSprite *background;
    sfSprite *bar;
    sfSprite **head;
    char **name;
    char **dialogue;
};

typedef struct perso perso_t;

struct perso {
    char *name;
    int offset;
    int gold;
    int id_attack1;
    int id_attack2;
    stat_t stat;
    item_t *equipped_item;
    item_t *items;
    sfSprite *sprite;
    sfVector2f move;
    sfVector2f pos;
    sfIntRect box;
};

typedef struct evt evt_t;

struct evt {
    sfBool active;
    sfBool always_active;
    sfBool is_fight;
    enemy_t *enemy;
    int offset_map;
    sfVector2f pos;
    dialogue_t **dialogue;
    int offset_dialogue;
    sfSprite *sprite;
    sfBool teleport;
    int new_offset;
    sfVector2f where; 
};

typedef struct quest quest_t;

struct quest {
    evt_t evt;
    int item_id;
    int count;
};

typedef struct obj obj_t;

struct obj {
    int offset;
    evt_t *event;
    quest_t *quest;
    int idx_quest;
    perso_t *perso;
    sfSprite **map;
    sfIntRect **box;
    sfMusic *music;
    sfRenderWindow *window;
};

#endif