/*
** EPITECH PROJECT, 2022
** parallax obj create
** File description:
** para obj crate
*/

#include "my.h"

gameobject_t *create_parallax_object(const char *path)
{
    gameobject_t *obj = malloc(sizeof(gameobject_t));
    obj->pos.x = 0;
    obj->pos.y = 0;
    obj->sprite = sfSprite_create();
    obj->texture = sfTexture_createFromFile(path, NULL);
    obj->texture_clock = sfClock_create();
    obj->rect.height = 1080;
    obj->rect.width = 1920;
    obj->rect.left = 0;

    if (error_check(obj) == 84)
        return NULL;
    sfSprite_setTexture(obj->sprite, obj->texture, 0);
    sfSprite_setPosition(obj->sprite, obj->pos);
    return (obj);
}
