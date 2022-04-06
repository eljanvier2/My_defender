/*
** EPITECH PROJECT, 2022
** defender
** File description:
** tower init
*/

#include "my.h"

void delete_tower(tower_list_t **removed)
{
    (*removed)->prev->next = (*removed)->next;
    (*removed)->next->prev = (*removed)->prev;
    delete_obj((*removed)->tower);
    free((*removed)->tower);
}

int tower_base_init(tower_list_t **tower, int type, sfVector2f pos)
{
    (*tower)->tower = malloc(sizeof(gameobject_t));
    (*tower)->type = type;
    (*tower)->damage = 5 * type;
    (*tower)->next = NULL;
    (*tower)->prev = NULL;
    (*tower)->tower->filepath = TOWER_PATH[type - 1];
    (*tower)->price = 10 * (*tower)->type;
    if (obj_create((*tower)->tower) != 0)
        return 84;
    (*tower)->tower->pos.x = pos.x;
    (*tower)->tower->pos.y = pos.y;
    sfSprite_setPosition((*tower)->tower->sprite, (*tower)->tower->pos);
    return 0;
}

void tower_linking(utils_t *ut, tower_list_t **t1, tile_t *tile, int type)
{
    tower_list_t *t2 = malloc(sizeof(tower_list_t));
    tower_list_t *ptr = *t1;

    if ((*t1)->type == -1) {
        tower_base_init(t1, type, tile->sprite->pos);
        (*t1)->next = NULL;
        (*t1)->prev = NULL;
        return;
    }
    while ((ptr)->next != NULL)
        ptr = ptr->next;
    tower_base_init(&t2, type, tile->sprite->pos);
    ptr->next = t2;
    t2->prev = ptr;
    t2->next = NULL;
    ut->wallet->money_num -= t2->price;
}
