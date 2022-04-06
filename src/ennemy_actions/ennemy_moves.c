/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemy moves
*/

#include "my.h"

void move_right(gameobject_t *obj)
{
    obj->pos.x += 1.08;
    if (my_strcmp(obj->filepath, ENNEMY_PATHS[HORD]) == 0)
        obj->rect.top = 324;
    sfSprite_setPosition(obj->sprite, obj->pos);
    if (obj->walking_progress == 100) {
        obj->walking_progress = 0;
        obj->tile_x += 1;
    } else
        obj->walking_progress += 1;
}

void move_left(gameobject_t *obj)
{
    obj->pos.x -= 1.08;
    if (my_strcmp(obj->filepath, ENNEMY_PATHS[HORD]) == 0)
        obj->rect.top = 216;
    sfSprite_setPosition(obj->sprite, obj->pos);
    if (obj->walking_progress == 100) {
        obj->walking_progress = 0;
        obj->tile_x -= 1;
    } else
        obj->walking_progress += 1;
}

void move_up(gameobject_t *obj)
{
    obj->pos.y -= 1.08;
    if (my_strcmp(obj->filepath, ENNEMY_PATHS[HORD]) == 0)
        obj->rect.top = TILE;
    sfSprite_setPosition(obj->sprite, obj->pos);
    if (obj->walking_progress == 100) {
        obj->walking_progress = 0;
        obj->tile_y -= 1;
    } else
        obj->walking_progress += 1;
}

void move_down(gameobject_t *obj)
{
    obj->pos.y += 1.08;
    if (my_strcmp(obj->filepath, ENNEMY_PATHS[HORD]) == 0)
        obj->rect.top = 0;
    sfSprite_setPosition(obj->sprite, obj->pos);
    if (obj->walking_progress == 100) {
        obj->walking_progress = 0;
        obj->tile_y += 1;
    } else
        obj->walking_progress += 1;
}

void ennemy_moves_handle(utils_t *utils, \
base_t *base, gameobject_t **obj, map_t *map)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime((*obj)->movement_clock);
    seconds = time.microseconds / 3000.0;
    if (seconds > 1.0) {
        move_selector(utils, base, *obj, map);
        sfSprite_setTextureRect((*obj)->sprite, (*obj)->rect);
        sfClock_restart((*obj)->movement_clock);
    }
}
