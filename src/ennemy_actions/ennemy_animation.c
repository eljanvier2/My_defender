/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemy_animation
*/

#include "my.h"

void move_rect(gameobject_t *obj, int offset, int max)
{
    static int cont = 0;

    if ((obj->rect.left + offset) < max && cont == 0) {
        obj->rect.top -= 0;
        obj->rect.left += offset;
        cont = 1;
    } else if ((obj->rect.left + offset) < max && cont == 1) {
        obj->rect.top += 0;
        obj->rect.left += offset;
        cont = 0;
    } else {
        obj->rect.left = 0;
    }
}

void sprite_clock_handle(gameobject_t *obj)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(obj->texture_clock);
    seconds = time.microseconds / 100000.0;
    if (seconds > 1.0) {
        move_rect(obj, TILE, 324);
        sfSprite_setTextureRect(obj->sprite, obj->rect);
        sfClock_restart(obj->texture_clock);
    }
}
