/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** dialogue2.c
*/

#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdlib.h>
#include <SFML/Graphics.h>

static void assign_to_dialog(char **name, char **dialog, dialogue_t **dialogue)
{
    dialogue[0]->bar = create_sprite(BAR, &(sfIntRect){0, 0, 945, 148});
    dialogue[0]->head = malloc(sizeof(sfSprite *) * 5);
    dialogue[0]->head[0] = create_sprite(FACE_PEOPLE, \
        &(sfIntRect){192, 96, 96, 96});
    dialogue[0]->head[1] = create_sprite(FACE, &(sfIntRect){0, 0, 96, 96});
    dialogue[0]->head[2] = create_sprite(FACE_PEOPLE, \
        &(sfIntRect){192, 96, 96, 96});
    dialogue[0]->head[3] = create_sprite(FACE_PEOPLE, \
        &(sfIntRect){192, 96, 96, 96});
    dialogue[0]->head[4] = create_sprite(FACE, &(sfIntRect){0, 0, 96, 96});
    dialogue[0]->name = name;
    dialogue[0]->dialogue = dialog;
    dialogue[0]->background = sfSprite_create();
}

static void set_begining_dialogue(char **name, char **dialog, \
    dialogue_t **dialogue)
{
    name[0] = "   Farmer";
    name[1] = "   Me";
    name[2] = "   Farmer";
    name[3] = "   Farmer";
    name[4] = "   Me";
    name[5] = NULL;
    dialog[0] = "Hey traveler, you are new to the area,\ncould you help me ?";
    dialog[1] = "Of course, what's your problem ?";
    dialog[2] = "As you can see a slime doesn't\nwant to leave my garden and "
        "prevents\nme from harvesting my vegetables...";
    dialog[3] = "I would like you to get rid of it\nplease...";
    dialog[4] = "Don't worry I got you !";
    dialog[5] = NULL;
    assign_to_dialog(name, dialog, dialogue);
}

static void set_thanks_dialogue(dialogue_t **dialogue)
{
    dialogue[1]->bar = create_sprite(BAR, &(sfIntRect){0, 0, 945, 148});
    dialogue[1]->head = malloc(sizeof(sfSprite *));
    dialogue[1]->head[0] = create_sprite(FACE_PEOPLE, \
        &(sfIntRect){192, 96, 96, 96});
    dialogue[1]->name = malloc(sizeof(char *) * 2);
    dialogue[1]->name[0] = "Farmer";
    dialogue[1]->name[1] = NULL;
    dialogue[1]->dialogue = malloc(sizeof(char *) * 2);
    dialogue[1]->dialogue[0] = "Thank you very much !";
    dialogue[1]->dialogue[1] = NULL;
    dialogue[1]->background = sfSprite_create();
}

dialogue_t **set_dialogue_farmer(void)
{
    dialogue_t **dialogue = malloc(sizeof(dialogue_t*) * 3);
    char **name = malloc(sizeof(char *) * 6);
    char **dialog = malloc(sizeof(char *) * 6);

    dialogue[0] = malloc(sizeof(dialogue_t));
    dialogue[1] = malloc(sizeof(dialogue_t));
    set_begining_dialogue(name, dialog, dialogue);
    set_thanks_dialogue(dialogue);
    dialogue[2] = NULL;
    return (dialogue);
}