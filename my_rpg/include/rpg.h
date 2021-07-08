/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** rpg.h
*/

#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Audio.h>
#include <SFML/Graphics.h>

#ifndef RPG
#define RPG

/*******************************HELP FUNCTION*********************************/
bool is_help(int argc, char const **argv);

/******************************ERROR FUNCTION*********************************/
bool is_error(int argc, char const **env);

/*********************************DIALOGUE************************************/
dialogue_t **set_dialogue_farmer(void);
void do_dialogue(sfRenderWindow *window, dialogue_t *dialogue);

/****************************INITIALIZATION GAME******************************/
evt_t *init_event(void);
perso_t *init_perso(void);
sfSprite **init_map(void);
sfSprite **init_inside(void);
sfIntRect **init_block(void);
char **download_map(char const *filepath);
obj_t *init_game_data(sfRenderWindow *window, char *filepath, sfMusic *music);

/*******************************INVENTORY*************************************/
void delete_item(sfRenderWindow *window, perso_t *perso, int idx, \
    bool is_equiped);
void which_equipment(perso_t *perso, sfVector2i mse, int idx);
void which_inventory(perso_t *perso, sfVector2i mse, int idx, bool swap);
void while_click_pressed(sfRenderWindow *window, perso_t *perso, \
    sfSprite *bg, int idx);
void manage_click(sfRenderWindow *window, perso_t *perso, sfSprite *bg);
void in_inventory(obj_t *obj);

/********************************EVENTS***************************************/
void move_sprite(obj_t *obj);
void teleport(sfRenderWindow *window, sfSprite *character, sfSprite *map, \
    sfVector2f pos);
void check_event(obj_t *obj);
void interact(obj_t *obj);

/*********************************FIGHT***************************************/
enemy_t *set_enemy(int id, char *filepath);
void attack(obj_t *obj, enemy_t *enemy, int idx);
void protect(sfRenderWindow *window);

/**********************************DRAW***************************************/
void draw_all(obj_t *obj, enemy_t *enemy, sfSprite *bg, sfSprite *scene);
void draw_menu(sfRenderWindow *window, sfSprite *bg, button_t **button);
void draw_event(obj_t *obj);
void draw_name(obj_t *obj);
void draw_stat(obj_t *obj);

/*******************************ANALYSE EVENT*********************************/
bool analyse_event_fight(obj_t *obj, enemy_t *enemy, sfSprite *bg, sfSprite \
    *scene);
bool analyse_event_pause(obj_t *obj, sfSprite **button);
void analyse_event_game(obj_t *obj);

/**********************************SCENES*************************************/
void in_game(sfRenderWindow *window, char *filepath, sfMusic *music);
void in_settings(sfRenderWindow *window, sfMusic *music);
void in_fight(obj_t *obj, enemy_t *enemy);
void in_controls(sfRenderWindow *window);
void in_status(obj_t *obj);
void pause_menu(obj_t *obj);
void print_map(obj_t *obj);
int in_menu(void);

/*******************************INITIALIZATION********************************/
button_t **init_all_button(void);
void analyse_event(sfRenderWindow *window, button_t **button, sfMusic *music);

/***********************************MUSIC*************************************/
sfMusic *open_music(char const *filename);
void close_music(sfMusic *music);
void increase_volume(sfMusic *music);
void decrease_volume(sfMusic *music);
void play_music(sfMusic *music, float volume);

/***********************************FREE**************************************/
void free_obj(obj_t *obj);


#endif