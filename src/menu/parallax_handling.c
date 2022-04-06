/*
** EPITECH PROJECT, 2022
** defender
** File description:
** parallax handling
*/

#include "my.h"

void parallax_handle2(gameobject_t *obj)
{
    if (obj->rect.left + obj->speed < 1920 * 2)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void parallax_handle(gameobject_t *obj)
{
    if (obj->rect.left + obj->speed < 1920)
        obj->rect.left += obj->speed;
    else
        obj->rect.left = 0;
    sfSprite_setTextureRect(obj->sprite, obj->rect);
}

void bck_clock_handle(gameobject_t *obj, int type)
{
    sfTime time;
    float milliseconds = 0;

    time = sfClock_getElapsedTime(obj->texture_clock);
    milliseconds = time.microseconds / 1000.0;
    if (milliseconds > obj->clock_refresh && type == 0) {
        parallax_handle(obj);
        sfClock_restart(obj->texture_clock);
    } else if (milliseconds > obj->clock_refresh && type == 1) {
        parallax_handle2(obj);
        sfClock_restart(obj->texture_clock);
    }
}

void parallax_pars(background_t *bckg)
{
    bck_clock_handle(bckg->ground, 0);
    bck_clock_handle(bckg->back, 0);
    bck_clock_handle(bckg->mid, 0);
    bck_clock_handle(bckg->front, 0);
}
