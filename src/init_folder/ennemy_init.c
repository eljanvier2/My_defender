/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemy init
*/

#include "my.h"

int ennemy_base_init(ennemy_list_t **ennemy, int type, utils_t *utils)
{
    (*ennemy)->ennemy = malloc(sizeof(gameobject_t));
    (*ennemy)->type = type;
    (*ennemy)->next = NULL;
    (*ennemy)->prev = NULL;
    (*ennemy)->ennemy->filepath = ENNEMY_PATHS[type];
    if (obj_create((*ennemy)->ennemy) != 0)
        return 84;
    (*ennemy)->ennemy->pos.y = map_start_finder(utils);
    (*ennemy)->ennemy->tile_y = (map_start_finder(utils) / TILE);
    (*ennemy)->ennemy->tile_x = 0;
    (*ennemy)->path_ind = 0;
    (*ennemy)->ennemy->previous_tile = 0;
    (*ennemy)->health = (50 * (type + 1)) * utils->wave_count;
    (*ennemy)->death_price = 3 * (type + 1);
    sfSprite_setPosition((*ennemy)->ennemy->sprite, (*ennemy)->ennemy->pos);
    return 0;
}

void ennemy_linking(ennemy_list_t **e1, int type, utils_t *utils)
{
    ennemy_list_t *e2 = malloc(sizeof(ennemy_list_t));
    ennemy_list_t *ptr = *e1;

    while ((ptr)->next != NULL)
        ptr = ptr->next;
    ennemy_base_init(&e2, type, utils);
    e2->type = type;
    ptr->next = e2;
    e2->prev = ptr;
    e2->next = NULL;
}

void delete_obj(gameobject_t *obj)
{
    if (obj->sprite)
        sfSprite_destroy(obj->sprite);
    if (obj->texture)
        sfTexture_destroy(obj->texture);
    if (obj->texture_clock)
        sfClock_destroy(obj->texture_clock);
    if (obj->movement_clock)
        sfClock_destroy(obj->movement_clock);
}

void delete_ennemy(ennemy_list_t *removed, utils_t *utils)
{
    utils->wallet->money_num += removed->death_price;
    if (removed->prev != NULL)
        removed->prev->next = removed->next;
    if (removed->next != NULL)
        removed->next->prev = removed->prev;
    delete_obj(removed->ennemy);
    utils->dead_ennemies++;
    if (utils->dead_ennemies == utils->ennemies_nb) {
        utils->dead_ennemies = 0;
        utils->ennemies_nb = 0;
        utils->wave_count++;
    }
    free(removed->ennemy);
}

int map_start_finder(utils_t *utils)
{
    for (int i = 0; utils->map->map[i]; i++) {
        if (utils->map->map[i][0] == 'S')
            return (TILE * i);
    }
    return 0;
}
