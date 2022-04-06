/*
** EPITECH PROJECT, 2022
** game menu
** File description:
** game menu
*/

#include "my.h"

int game_menu_buttons(scene_t *scene)
{
    if (!(scene->buttons = malloc(sizeof(button_t *) * 5)))
        return 84;
    for (int i = 0; i < 5; i++) {
        if (!(scene->buttons[i] = malloc(sizeof(button_t))))
            return 84;
    }
    for (int i = 1; i < 5; i++)
        if (!(scene->buttons[i] =
        create_btn(scene->buttons[i], 1625, i * 200, i)))
        return 84;
    return 0;
}

int menu_create(gameobject_t *obj)
{
    obj->rect.width = 500;
    obj->rect.height = 1080;
    obj->rect.left = 1420;
    obj->pos.x = 1420;
    obj->pos.y = 0;
    obj->filepath = "./ressources/game_menu/game_menu.png";
    if (!(obj->sprite = sfSprite_create()))
        return 84;
    if (!(obj->texture = sfTexture_createFromFile(obj->filepath, NULL)))
        return 84;
    sfSprite_setTexture(obj->sprite, obj->texture, 0);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    return 0;
}

void game_menu(scene_t *scene)
{
    scene->gameobjects = malloc(sizeof(gameobject_t));
    menu_create(scene->gameobjects);
}
