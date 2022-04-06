/*
** EPITECH PROJECT, 2022
** defender
** File description:
** tiles_free
*/

#include <SFML/Audio/SoundBuffer.h>
#include "my.h"
#include "utils_struct.h"

void free_grass(utils_t *utils)
{
    for (int i = 0; i < utils->map->grass_ind; i++) {
        sfTexture_destroy(utils->map->grass[i]->sprite->texture);
        sfSprite_destroy(utils->map->grass[i]->sprite->sprite);
        free(utils->map->grass[i]);
    }
    free(utils->map->grass);
}

void free_path(utils_t *utils)
{
    for (int i = 0; i < utils->map->path_ind; i++) {
        sfTexture_destroy(utils->map->path[i]->sprite->texture);
        sfSprite_destroy(utils->map->path[i]->sprite->sprite);
        free(utils->map->path[i]);
    }
    free(utils->map->path);
}

void free_tspot(utils_t *utils)
{
    for (int i = 0; i < utils->map->tspot_ind; i++) {
        sfTexture_destroy(utils->map->t_spots[i]->sprite->texture);
        sfSprite_destroy(utils->map->t_spots[i]->sprite->sprite);
        free(utils->map->t_spots[i]);
    }
    free(utils->map->t_spots);
}
