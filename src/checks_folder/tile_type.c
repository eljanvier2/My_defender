/*
** EPITECH PROJECT, 2022
** defenfer
** File description:
** tile_type
*/

#include "my.h"

void is_grass(map_t *map, int i, int j)
{
    map->grass[map->grass_ind]->sprite->pos.y += TILE * i;
    map->grass[map->grass_ind]->sprite->pos.x += TILE * j;
    sfSprite_setPosition(map->grass[map->grass_ind]->sprite->sprite,
        map->grass[map->grass_ind]->sprite->pos);
}

void is_path(map_t *map, int i, int j)
{
    map->path[map->path_ind]->sprite->pos.x += TILE * j;
    map->path[map->path_ind]->sprite->pos.y += TILE * i;
    sfSprite_setPosition(map->path[map->path_ind]->sprite->sprite,
        map->path[map->path_ind]->sprite->pos);
}

void is_tower(map_t *map, int i, int j)
{
    map->t_spots[map->tspot_ind]->sprite->pos.y += TILE * i;
    map->t_spots[map->tspot_ind]->sprite->pos.x += TILE * j;
    sfSprite_setPosition(map->t_spots[map->tspot_ind]->sprite->sprite,
        map->t_spots[map->tspot_ind]->sprite->pos);
}

int check_base_placement(map_t *map, int i, int j)
{
    if (i != 0 && (map->map[i - 1][j] == PATH || map->map[i][j - 1] == PATH))
        return 0;
    if (i != 9 && (map->map[i + 1][j] == PATH || map->map[i][j + 1] == PATH))
        return 0;
    my_putsterr("Bad map placement\n");
    return 84;
}

int is_base(map_t *map, int i, int j)
{
    if (check_base_placement(map, i, j) == 84)
        return 84;
    map->base->sprite->pos.y += TILE * i;
    map->base->sprite->pos.x += TILE * j;
    sfSprite_setPosition(map->base->sprite->sprite, map->base->sprite->pos);
    return 0;
}
