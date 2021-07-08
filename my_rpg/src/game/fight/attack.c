/*
** EPITECH PROJECT, 2020
** TEST
** File description:
** attack.c
*/

#include "utils.h"
#include "my_csfml.h"
#include "struct_rpg.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SFML/Graphics.h>

static bool event(sfRenderWindow *window)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace)
            return true;
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft)
            return true;
    }
    return false;
}

static void attack_enemy(obj_t *obj, enemy_t *enemy)
{
    int damage = 0;
    char *str = NULL;

    if (rand() % 2 == 0)
        damage = 0.80 * enemy->stat.att * enemy->id + (1 + rand() % \
            (int)(0.20 * enemy->stat.att * enemy->id));
    else
        damage = 0.80 * enemy->stat.att_spe * enemy->id + (1 + rand() % \
            (int)(0.20 * enemy->stat.att_spe * enemy->id));
    str = malloc(sizeof(char) * (my_intlen(damage) + 19));
    memset(str, '\0', my_intlen(damage) + 19);
    print_message(obj->window, my_strcat(my_strcat(my_strcat(str, \
        "You took "), my_itoa(damage)), " damages !"), sfRed, \
        (sfVector2f){355, 510});
    obj->perso->stat.pv -= damage;
    sfRenderWindow_display(obj->window);
    while (sfRenderWindow_isOpen(obj->window) && event(obj->window) \
        == false);
    free(str);
}

static int count_damage(obj_t *obj, int idx)
{
    int damage = 0;

    if (idx == 1) {
        obj->perso->stat.mana -= 10 * obj->perso->id_attack1;
        damage = 0.80 * obj->perso->stat.att_spe * obj->perso->id_attack1 + \
            (1 + rand() % (int)(0.20 * obj->perso->stat.att_spe * \
            obj->perso->id_attack1));
    } else if (idx == 2) {
        obj->perso->stat.mana -= 10 * obj->perso->id_attack2;
        damage = 0.80 * obj->perso->stat.att_spe * obj->perso->id_attack2 + \
            (1 + rand() % (int)(0.20 * obj->perso->stat.att_spe * \
            obj->perso->id_attack2));
    } else
        damage = 0.80 * obj->perso->stat.att + (1 + rand() % (int)(0.20 * \
            obj->perso->stat.att));
    return (damage);
}

void attack(obj_t *obj, enemy_t *enemy, int idx)
{
    int damage = count_damage(obj, idx);
    char *str = malloc(sizeof(char) * (my_intlen(damage) + 18));

    memset(str, '\0', my_intlen(damage) + 18);
    print_message(obj->window, my_strcat(my_strcat(my_strcat(str, "You did "), \
        my_itoa(damage)), " damages !"), sfGreen, (sfVector2f){355, 510});
    sfRenderWindow_display(obj->window);
    enemy->stat.pv -= damage;
    while (sfRenderWindow_isOpen(obj->window) && event(obj->window) \
        == false);
    if (enemy->stat.pv > 0)
        attack_enemy(obj, enemy);
    free(str);
}

void protect(sfRenderWindow *window)
{
    print_message(window, "Vous  vous  protegez  ce  tour.", \
        (sfColor){128, 128, 128, 255}, (sfVector2f){300, 510});
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window) && event(window) == false);
    print_message(window, \
        "L'ennemi  n'a  pas  reussi  a  vous  faire  de  degats.", \
        (sfColor){128, 128, 128, 255}, (sfVector2f){150, 510});
    sfRenderWindow_display(window);
    while (sfRenderWindow_isOpen(window) && event(window) == false);
}