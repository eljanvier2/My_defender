/*
** EPITECH PROJECT, 2022
** defender
** File description:
** draws
*/

#include <SFML/Graphics/RenderWindow.h>
#include "enums.h"
#include "my.h"

void draws(utils_t *utils, sfClock *wave_clock)
{
    map_displayer(utils->map, utils->win);
    tower_draw(utils->scenes[GAME], utils->win);
    wallet_update(utils);
    if (wave_clock != NULL)
        ennemy_handling(utils, wave_clock);
    game_menu_draw(utils);
}

void map_displayer(map_t *map, sfRenderWindow *win)
{
    for (int i = 0; i < map->grass_ind; i++)
        sfRenderWindow_drawSprite(win, map->grass[i]->sprite->sprite, NULL);
    for (int i = 0; i < map->path_ind; i++)
        sfRenderWindow_drawSprite(win, map->path[i]->sprite->sprite, NULL);
    for (int i = 0; i < map->tspot_ind; i++)
        sfRenderWindow_drawSprite(win, map->t_spots[i]->sprite->sprite, NULL);
    sfRenderWindow_drawSprite(win, map->base->sprite->sprite, NULL);
}

void tower_draw(scene_t *scene, sfRenderWindow *win)
{
    if (scene->towers->type == -1 && scene->towers->next == NULL)
        return;
    if (scene->towers->next == NULL && scene->towers->prev == NULL) {
        sfRenderWindow_drawSprite(win, scene->towers->tower->sprite, NULL);
        return;
    }
    while (scene->towers != NULL) {
        sfRenderWindow_drawSprite(win, scene->towers->tower->sprite, NULL);
        if (scene->towers->next != NULL)
            scene->towers = scene->towers->next;
        else
            break;
    }
    while (scene->towers != NULL) {
        if (scene->towers->prev != NULL)
            scene->towers = scene->towers->prev;
        else
            break;
    }
}
