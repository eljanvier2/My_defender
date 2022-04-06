/*
** EPITECH PROJECT, 2022
** B-MUL-200-BDX-2-1-mydefender-elliot.janvier
** File description: base attacking
** base attack
*/

#include "my.h"

int base_attack(utils_t *utils, base_t *base, gameobject_t *obj, map_t *map)
{
    if (obj->tile_x != 17 && map->map[obj->tile_y][obj->tile_x + 1] == 'B') {
        move_right(obj);
    }
    if (obj->tile_x != 0 && map->map[obj->tile_y][obj->tile_x - 1] == 'B') {
        move_left(obj);
    }
    if (obj->tile_y != 9 && map->map[obj->tile_y + 1][obj->tile_x] == 'B') {
        move_down(obj);
    }
    if (obj->tile_y != 0 && map->map[obj->tile_y - 1][obj->tile_x] == 'B') {
        move_up(obj);
    }
    base->ennemies_in++;
    return (ennemies_in_base(utils, base));
}

void lose_menu_draw(utils_t *utils)
{
    sfRenderWindow_clear(utils->win, sfBlack);
    draws(utils, NULL);
}

int ennemies_in_base(utils_t *utils, base_t *base)
{
    sfTime time;
    float seconds = 0;

    time = sfClock_getElapsedTime(base->ennemy_refresh);
    seconds = time.microseconds / 100000.0;
    if (seconds > 4.0) {
        if (base->ennemies_in > base->max_ennemy) {
            base->win = false;
            lose_menu_draw(utils);
            return -2;
        }
    }
    return -1;
}