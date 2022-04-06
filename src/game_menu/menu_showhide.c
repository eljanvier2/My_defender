/*
** EPITECH PROJECT, 2022
** menu show and hide
** File description:
** menu show and hide
*/

#include "my.h"

void menu_hider(scene_t *scene)
{
    for (int i = 1; i < 5; i++) {
        scene->buttons[i]->pos.x += 500;
        sfRectangleShape_setPosition(scene->buttons[i]->rect, \
        scene->buttons[i]->pos);
    }
    scene->gameobjects->pos.x += 500;
    sfSprite_setPosition(scene->gameobjects->sprite, scene->gameobjects->pos);
    scene->menu_status = false;
}

void menu_shower(utils_t *utils, scene_t *scene)
{
    for (int i = 1; i < 5; i++) {
        scene->buttons[i]->pos.x -= 500;
        sfRectangleShape_setPosition(scene->buttons[i]->rect, \
        scene->buttons[i]->pos);
    }
    scene->gameobjects->pos.x -= 500;
    sfSprite_setPosition(scene->gameobjects->sprite, scene->gameobjects->pos);
    click_pos_check(utils);
    scene->menu_status = true;
}
