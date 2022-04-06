/*
** EPITECH PROJECT, 2022
** defender
** File description:
** filepath ops
*/

#include "my.h"

char *grass_path_selector(void)
{
    int alea = rand() % 10;
    switch (alea) {
        case 0: return "./ressources/tiles/bush.png"; break;
        case 1: return "./ressources/tiles/grass.png"; break;
        case 2: return "./ressources/tiles/log.png"; break;
        case 3: return "./ressources/tiles/mush1.png"; break;
        case 4: return "./ressources/tiles/mush2.png"; break;
        default: return "./ressources/tiles/grass.png"; break;
    }
}

void filepath_parse(tile_t *tile, char type)
{
    if (type == GRASS)
        tile->sprite->filepath = grass_path_selector();
    if (type == PATH)
        tile->sprite->filepath = "./ressources/tiles/path.png";
    if (type == TOWER_SPOT)
        tile->sprite->filepath = "./ressources/tiles/tower_grass.png";
    if (type == BASE)
        tile->sprite->filepath = "./ressources/tiles/base_resized.png";
}
