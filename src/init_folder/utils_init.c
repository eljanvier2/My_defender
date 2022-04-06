/*
** EPITECH PROJECT, 2022
** defender
** File description:
** utils
*/

#include "my.h"

utils_t *utils_init(utils_t *utils)
{
    if (!(utils = malloc(sizeof(utils_t))) || \
    !(utils->map = malloc(sizeof(map_t))) || \
    !(utils->map->map = malloc(11 * sizeof(char *))))
        return NULL;
    if (!(utils->sound_effects = malloc(sizeof(audio_t))))
        return NULL;
    if (!(utils->cursor = malloc(sizeof(cursor_t))))
        return NULL;
    if (!(utils->wallet = malloc(sizeof(wallet_t))))
        return NULL;
    utils->map->grass_ind = 0;
    utils->map->path_ind = 0;
    utils->map->tspot_ind = 0;
    utils->wave_count = 1;
    utils->ennemies_nb = 0;
    utils->dead_ennemies = 0;
    utils->wallet->money_num = 20;
    utils->pause = false;
    return utils;
}
