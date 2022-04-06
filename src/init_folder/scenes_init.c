/*
** EPITECH PROJECT, 2022
** defender
** File description:
** scenes init
*/

#include <stdlib.h>
#include "my.h"

int game_scene_init(utils_t *utils)
{
    utils->scenes[GAME]->menu_status = true;
    utils->scenes[GAME]->ennemies = malloc(sizeof(ennemy_list_t));
    utils->scenes[GAME]->towers = malloc(sizeof(tower_list_t));
    utils->scenes[GAME]->towers->type = -1;
    utils->scenes[GAME]->towers->next = NULL;
    utils->scenes[GAME]->towers->prev = NULL;
    utils->scenes[GAME]->base_health = 5;
    utils->scenes[GAME]->gameobjects = malloc(sizeof(gameobject_t));
    utils->scenes[GAME]->base = malloc(sizeof(base_t));
    utils->scenes[GAME]->base->ennemy_refresh = sfClock_create();
    utils->scenes[GAME]->base->max_ennemy = 5;
    utils->scenes[GAME]->base->win = true;
    utils->scenes[GAME]->base->ennemies_in = 0;
    if (menu_create(utils->scenes[GAME]->gameobjects) != 0 || \
    game_menu_buttons(utils->scenes[GAME]) != 0)
        return 84;
    utils->scenes[GAME]->clic_type = 0;
    return 0;
}

int pause_scene_init(utils_t *utils)
{
    int pos_y = 0;

    if (!(utils->scenes[PAUSE]->buttons = malloc(sizeof(button_t *) * 4)))
        return 84;
    for (int i = 0; i < 4; i++)
        if (!(utils->scenes[PAUSE]->buttons[i] = malloc(sizeof(button_t))))
            return 84;
    for (int i = 0; i < 3; i++) {
        pos_y = 400 + (200 * i);
        utils->scenes[PAUSE]->buttons[i] = \
        create_btn(utils->scenes[PAUSE]->buttons[i], 660, pos_y, 0);
        if (text_add(utils->scenes[PAUSE]->buttons[i], (i + 4)) == 84)
            return 84;
    }
    return 0;
}

int end_scene_init(utils_t *utils)
{
    utils->scenes[LOSE]->gameobjects = malloc(sizeof(gameobject_t));
    utils->scenes[LOSE]->gameobjects->filepath = \
    "./ressources/losing_screen.png";
    obj_create(utils->scenes[LOSE]->gameobjects);
    utils->scenes[LOSE]->gameobjects->rect.height = 1080;
    utils->scenes[LOSE]->gameobjects->rect.width = 1920;
    sfSprite_setTextureRect(utils->scenes[LOSE]->gameobjects->sprite, \
    utils->scenes[LOSE]->gameobjects->rect);
    return 0;
}

int scenes_init(utils_t *utils)
{
    if (!(utils->scenes = malloc(sizeof(scene_t *) * 4)))
        return 84;
    for (int i = 0; i < 4; i++) {
        if (!(utils->scenes[i] = malloc(sizeof(scene_t))))
            return 84;
    }
    if (game_scene_init(utils) != 0 || pause_scene_init(utils) != 0 || \
    end_scene_init(utils) != 0)
        return 84;
    return 0;
}
