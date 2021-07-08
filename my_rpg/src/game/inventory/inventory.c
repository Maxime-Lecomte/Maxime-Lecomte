/*
** EPITECH PROJECT, 2020
** Tek1
** File description:
** inventory.c
*/

#include "rpg.h"
#include "utils.h"
#include "my_csfml.h"
#include "macro_rpg.h"
#include "struct_rpg.h"
#include <stdbool.h>
#include <SFML/Graphics.h>

static bool analyse_event_inventory(sfRenderWindow *window, perso_t *perso, \
    sfSprite *bg)
{
    sfEvent event;

    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed) {
            sfRenderWindow_close(window);
            return (false);
        }
        if (event.type == sfEvtMouseButtonPressed && event.mouseButton.button \
            == sfMouseLeft) {
            manage_click(window, perso, bg);
        }
    }
    if (sfKeyboard_isKeyPressed(INVENTORY) == sfTrue)
        return (true);
    return (false);
}

static void draw_items(obj_t *obj)
{
    for (int i = 0; i < 28; ++i) {
        if (obj->perso->items[i].id != -1) {
            sfSprite_setPosition(obj->perso->items[i].sprite, \
                (sfVector2f){234 + ((i % 7) * 72), 281 + ((i / 7) * 72)});
            sfRenderWindow_drawSprite(obj->window, \
                obj->perso->items[i].sprite, NULL);
        }
    }
}

static void draw_equipped_items(obj_t *obj, int i)
{
    if (obj->perso->equipped_item[i].id != -1) {
        if (i < 2)
            sfSprite_setPosition(obj->perso->equipped_item[i].sprite, \
                (sfVector2f){783, 70 + i * 109});
        else
            sfSprite_setPosition(obj->perso->equipped_item[i].sprite, \
                (sfVector2f){783, 281 + (i - 2) * 72});
        sfRenderWindow_drawSprite(obj->window, \
            obj->perso->equipped_item[i].sprite, NULL);
    }
}

static void end_inventory(obj_t *obj, sfSprite *bg, sfSprite *inventory)
{
    if (sfRenderWindow_isOpen(obj->window)) {
        sfRenderWindow_drawSprite(obj->window, obj->map[obj->offset], NULL);
        sfRenderWindow_drawSprite(obj->window, obj->perso->sprite, NULL);
        sfRenderWindow_display(obj->window);
    }
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(bg));
    sfTexture_destroy((sfTexture *)sfSprite_getTexture(inventory));
    sfSprite_destroy(bg);
    sfSprite_destroy(inventory);
}

void in_inventory(obj_t *obj)
{
    sfSprite *bg = NULL;
    sfSprite *inventory = create_sprite(FP_INVENTORY, NULL);

    sfSleep((sfTime){100000});
    bg = copy_bg(obj->window, obj->map[obj->offset], obj->perso->sprite, \
        inventory);
    for (int i = 0; sfRenderWindow_isOpen(obj->window); ++i) {
        sfRenderWindow_drawSprite(obj->window, bg, NULL);
        print_text(obj->window, my_itoa(obj->perso->gold), (sfColor){128, \
            128, 0, 255}, (sfVector2f){370, 205});
        draw_items(obj);
        for (int i = 0; i < 6; ++i)
            draw_equipped_items(obj, i);
        sfRenderWindow_display(obj->window);
        if (analyse_event_inventory(obj->window, obj->perso, bg) == true) {
            end_inventory(obj, bg, inventory);
            return;
        }
    }
    end_inventory(obj, bg, inventory);
}