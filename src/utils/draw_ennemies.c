/*
** EPITECH PROJECT, 2022
** defender
** File description:
** draws
*/

#include "my.h"

void first_ennemy_draw(scene_t *scene, \
sfRenderWindow *win, map_t *map, utils_t *utils)
{
    if (health_check(scene, scene->ennemies, utils) != 1)
        sfRenderWindow_drawSprite(win, scene->ennemies->ennemy->sprite, NULL);
    else {
        return;
    }
    sprite_clock_handle((scene->ennemies->ennemy));
    ennemy_moves_handle(utils, scene->base, &scene->ennemies->ennemy, map);
    return;
}

int mul_enn_draw_check(scene_t *scene, sfRenderWindow *win, utils_t *utils)
{
    if (health_check(scene, scene->ennemies, utils) != 1) {
        sfRenderWindow_drawSprite(win, scene->ennemies->ennemy->sprite, NULL);
    } else {
        if (scene->ennemies->next != NULL)
            scene->ennemies = scene->ennemies->next;
        return 1;
    }
    return 0;
}

void multiple_ennemies_draw(scene_t *scene, \
sfRenderWindow *win, map_t *map, utils_t *utils)
{
    while (scene->ennemies != NULL) {
        if (mul_enn_draw_check(scene, win, utils) == 1)
            continue;
        sprite_clock_handle((scene->ennemies->ennemy));
        ennemy_moves_handle(utils, scene->base, &scene->ennemies->ennemy, map);
        if (scene->ennemies->next != NULL)
            scene->ennemies = scene->ennemies->next;
        else
            break;
    }
}

void ennemy_draw(scene_t *scene, \
sfRenderWindow *win, map_t *map, utils_t *utils)
{
    if (scene->ennemies->path_ind == -1 || \
    (scene->ennemies->path == NULL && scene->ennemies->health == 0))
        return;
    if (scene->ennemies->next == NULL && scene->ennemies->prev == NULL) {
        if (scene->ennemies->health >= 0)
            first_ennemy_draw(scene, win, map, utils);
        return;
    }
    multiple_ennemies_draw(scene, win, map, utils);
    ennemy_list_rewind(scene);
}

void ennemy_list_rewind(scene_t *scene)
{
    while (scene->ennemies != NULL) {
        if (scene->ennemies->prev != NULL)
            scene->ennemies = scene->ennemies->prev;
        else
            break;
    }
}
