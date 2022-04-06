/*
** EPITECH PROJECT, 2022
** defender
** File description:
** ennemy health check
*/

#include <SFML/System/Clock.h>
#include "my.h"

void single_ennem_health(scene_t *scene, ennemy_list_t *ennemy, sfVector2f pos)
{
    sfTime time = sfClock_getElapsedTime(ennemy->ennemy->movement_clock);
    float seconds = time.microseconds / 900.0;

    if (pos.x > scene->towers->tower->pos.x \
    && pos.x < scene->towers->tower->pos.x + (TILE * 2) \
    && pos.y > scene->towers->tower->pos.y \
    && pos.y < scene->towers->tower->pos.y + (TILE * 2))
        if (seconds > 2.0)
            ennemy->health -= scene->towers->damage;
}

void ennemy_list_rewind2(scene_t *scene)
{
    while (scene->towers != NULL) {
        if (scene->towers->prev != NULL)
            scene->towers = scene->towers->prev;
        else
            break;
    }
}

void mul_ennem_health(scene_t *scene, ennemy_list_t *ennemy, sfVector2f pos)
{
    while (scene->towers != NULL) {
        single_ennem_health(scene, ennemy, pos);
        if (scene->towers->next != NULL)
            scene->towers = scene->towers->next;
        else
            break;
    }
}

int health_check(scene_t *scene, ennemy_list_t *ennemy, utils_t *utils)
{
    sfVector2f pos = sfSprite_getPosition(ennemy->ennemy->sprite);

    if (scene->towers->type == -1 && scene->towers->next == NULL)
        return 0;
    if (scene->towers->next == NULL && scene->towers->prev == NULL) {
        single_ennem_health(scene, ennemy, pos);
    }
    mul_ennem_health(scene, ennemy, pos);
    ennemy_list_rewind2(scene);
    if (ennemy->health <= 0) {
        delete_ennemy(ennemy, utils);
        return 1;
    }
    return 0;
}
