/*
** EPITECH PROJECT, 2022
** defender
** File description:
** move selector utils
*/

#include "my.h"

void move_selector(utils_t *utils, base_t *base, gameobject_t *obj, map_t *map)
{
    if (obj->walking_progress == 0) {
        switch (obj->previous_tile = next_tile(obj, map)) {
            case 1: move_right(obj); break;
            case 2: move_down(obj); break;
            case 3: move_up(obj); break;
            case 4: move_left(obj); break;
            case 5: \
            obj->previous_tile = base_attack(utils, base, obj, map); break;
            default: return; break;
        }
    } else {
        switch (obj->previous_tile) {
            case 1: move_right(obj); break;
            case 2: move_down(obj); break;
            case 3: move_up(obj); break;
            case 4: move_left(obj); break;
            default: return; break;
        }
    }
}

int next_tile_part2(gameobject_t *obj, map_t *map)
{
    if (obj->tile_y != 0 && map->map[obj->tile_y - 1][obj->tile_x] == '0'
        && obj->previous_tile != 2 && obj->previous_tile != 5) {
        obj->previous_tile = 3;
        return obj->previous_tile;
    }
    if (obj->tile_x != 0 && map->map[obj->tile_y][obj->tile_x - 1] == '0'
        && obj->previous_tile != 1 && obj->previous_tile != 5) {
        obj->previous_tile = 4;
        return obj->previous_tile;
    }
    return 5;
}

int next_tile(gameobject_t *obj, map_t *map)
{
    if (obj->tile_x != 17 && map->map[obj->tile_y][obj->tile_x + 1] == '0' && \
    obj->previous_tile != 4 && obj->previous_tile != 5) {
        obj->previous_tile = 1;
        return obj->previous_tile;
    }
    if (obj->tile_y != 9 && map->map[obj->tile_y + 1][obj->tile_x] == '0' && \
    obj->previous_tile != 3 && obj->previous_tile != 5) {
        obj->previous_tile = 2;
        return obj->previous_tile;
    }
    obj->previous_tile = next_tile_part2(obj, map);
    if (obj->previous_tile == 5)
        return 5;
    return obj->previous_tile;
}
