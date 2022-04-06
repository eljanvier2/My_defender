/*
** EPITECH PROJECT, 2022
** defender
** File description:
** map loader
*/

#include "my.h"

void n_remover(char **map)
{
    for (int i = 0; map[i] != NULL; i++) {
        for (int j = 0; map[i][j] != '\0'; j++)
            map[i][j] = backn_check(map[i][j]);
    }
}

int map_loader_loop(map_t *map, size_t linelen, size_t linelen_prev, int rows)
{
    while (linelen < INT_MAX) {
        if (map_validity_check(rows, linelen, linelen_prev) != 0)
            return 84;
        linelen_prev = linelen;
        if (!(map->map[rows] = malloc(sizeof(char) * linelen_prev)))
            return 84;
        if (!(linelen = getline(&(map->map[rows]), &linelen, map->file)))
            return 84;
        rows++;
    }
    return rows;
}

int standard_map_loader(map_t *map)
{
    map->map = malloc(sizeof(char *) * 10);
    if (!map->map)
        return 84;
    for (int i = 0; i < 10; i++) {
        map->map[i] = malloc(sizeof(char) * 18);
        if (!map->map[i])
            return 84;
    }
    map->map[0] = "..................";
    map->map[1] = "............T.....";
    map->map[2] = "S000T...T....000..";
    map->map[3] = "..T000000T..T0T0..";
    map->map[4] = "...T...T000000.0..";
    map->map[5] = "..........T....0..";
    map->map[6] = "...............0..";
    map->map[7] = "...............0..";
    map->map[8] = "...........00000..";
    map->map[9] = "...........B......X";
    return 0;
}

int map_loader(char const *filepath, map_t *map)
{
    size_t linelen = 0;
    size_t linelen_prev = 0;
    int rows = 0;

    if (filepath == NULL)
        return (standard_map_loader(map));
    if (!(map->file = fopen(filepath, "r")))
        return 84;
    rows = map_loader_loop(map, linelen, linelen_prev, rows);
    if (rows != 11) {
        my_putsterr("Invalid map size\n");
        return 84;
    }
    map->map[rows - 1] = NULL;
    n_remover(map->map);
    return 0;
}

int tile_placer(map_t *map)
{
    int error = 0;

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 18; j++) {
            error += tile_type_check(map, i, j);
        }
    }
    if (error != 0)
        return 84;
    return 0;
}
