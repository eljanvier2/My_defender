/*
** EPITECH PROJECT, 2022
** defender
** File description:
** tile generating files
*/

#include "my.h"

int type_count(char **map, char type)
{
    int count = 0;

    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++) {
            count = type_check(map[i][j], type, count);
        }
    }
    return count;
}

int loop2(map_t *map, int tower_spot)
{
    for (int i = 0; i < tower_spot; i++) {
        if (!(map->t_spots[i] = malloc(sizeof(tile_t))))
            return 84;
        map->t_spots[i]->type = TOWER_SPOT;
        if (tile_obj_create(map->t_spots[i], TOWER_SPOT) == 84)
            return 84;
        map->t_spots[i + 1] = NULL;
    }
    if (!(map->base = malloc(sizeof(tile_t))))
        return 84;
    map->base->type = BASE;
    if (tile_obj_create(map->base, BASE) == 84)
        return 84;
    return 0;
}

int loop(map_t *map, int grass, int en_path, int tower_spot)
{
    for (int i = 0; i < grass; i++) {
        if (!(map->grass[i] = malloc(sizeof(tile_t))))
            return 84;
        map->grass[i]->type = GRASS;
        if (tile_obj_create(map->grass[i], GRASS) == 84)
            return 84;
        map->grass[i + 1] = NULL;
    }
    for (int i = 0; i < en_path; i++) {
        if (!(map->path[i] = malloc(sizeof(tile_t))))
            return 84;
        map->path[i]->type = PATH;
        if (tile_obj_create(map->path[i], PATH) == 84)
            return 84;
        map->path[i + 1] = NULL;
    }
    return (loop2(map, tower_spot));
}

int tile_gen(map_t *map)
{
    int grass = type_count(map->map, GRASS);
    int en_path = type_count(map->map, PATH) + type_count(map->map, START);
    int tower_spot = type_count(map->map, TOWER_SPOT);

    if (!(map->grass = malloc(sizeof(tile_t) * grass)) || \
    !(map->path = malloc(sizeof(tile_t) * en_path)))
        return 84;
    if (!(map->t_spots = malloc(sizeof(tile_t) * tower_spot)))
        return 84;
    if (loop(map, grass, en_path, tower_spot) == 84)
        return 84;
    if (tile_placer(map) != 0)
        return 84;
    return 0;
}
