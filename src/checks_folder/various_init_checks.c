/*
** EPITECH PROJECT, 2022
** defender
** File description:
** tile creation check, map init check
*/

#include "my.h"

char backn_check(char c)
{
    if (c == '\n')
        c = '\0';
    return c;
}

int map_validity_check(int rows, int linelen, int linelen_prev)
{
    if (linelen_prev != 0 && linelen != linelen_prev) {
        my_putsterr("Invalid map given\n");
        return 84;
    }
    if (linelen > 19 || rows > 10) {
        my_putsterr("Invalid map size\n");
        return 84;
    }
    return 0;
}

int type_check(char c, char type, int count)
{
    if (c == type)
        count++;
    return count;
}

int tile_type_check(map_t *map, int i, int j)
{
    if (map->map[i][j] == GRASS) {
        is_grass(map, i, j);
        map->grass_ind++;
    }
    if (map->map[i][j] == PATH || map->map[i][j] == START) {
        is_path(map, i, j);
        map->path_ind++;
    }
    if (map->map[i][j] == TOWER_SPOT) {
        is_tower(map, i, j);
        map->tspot_ind++;
    }
    if (map->map[i][j] == BASE)
        if (is_base(map, i, j) == 84)
            return 84;
    return 0;
}
