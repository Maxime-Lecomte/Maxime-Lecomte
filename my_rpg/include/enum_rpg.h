/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** enum_rpg.h
*/

#ifndef ENUM_RPG
#define ENUM_RPG

typedef enum items_id items_e;

enum items_id {
    BREAD,
    PIZZA,
    POTIONS,
    SUPER_POTIONS,
    HYPER_POTIONS,
    MANA_BOTTLE_S,
    MANA_BOTTLE_M,
    MANA_BOTTLE_L,
    MANA_BOTTLE_XL,
    SLIME_BALL,
    EYE,
    HONEY,
    CLAW,
    FUR,
    LEATHER,
    FUR_HELMET,
    FUR_CHESTPLATE,
    FUR_PANTS,
    FUR_BOOTS,
    LEATHER_HELMET,
    LEATHER_CHESTPLATE,
    LEATHER_PANTS,
    LEATHER_BOOTS,
    IRON_HELMET,
    IRON_CHESTPLATE,
    IRON_PANTS,
    IRON_BOOTS,
    STEEL_HELMET,
    STEEL_CHESTPLATE,
    STEEL_PANTS,
    STEEL_BOOTS,
    MAGIC_HELMET,
    MAGIC_CHESTPLATE,
    MAGIC_PANTS,
    MAGIC_BOOTS,
    WOOD_SWORD,
    WOOD_SHIELD,
    STONE_SWORD,
    STONE_SHIELD,
    IRON_SWORD,
    IRON_SHIELD,
    STEEL_SWORD,
    STEEL_SHIELD,
    MAGIC_SWORD,
    MAGIC_SHIELD,
};

typedef enum enemy_id enemy_e;

enum enemy_id {
    SLIME = 1,
    BEE = 2,
    SPIDER = 3,
    WOLF = 5,
    KNIGHT = 7,
    LANCER = 8,
    PRIEST = 10,
    DAEMON = 12,
};

typedef enum attack_id attck_e;

enum attack_id {
    WATERBALL,
    WIND_BLADE,
    FIREBALL,
    EARTHQUAKE,
};

#endif