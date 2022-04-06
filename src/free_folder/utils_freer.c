/*
** EPITECH PROJECT, 2022
** defender1
** File description:
** utils_freer
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Clock.h>
#include "my.h"

void first_free_utils(utils_t *utils)
{
    free(utils->background->sky);
    free(utils->background->back);
    free(utils->background->mid);
    free(utils->background->title);
    free(utils->background->front);
    free(utils->background->ground);
    free(utils->wallet->num_char);
    free(utils->scenes[MENU]);
    free(utils->scenes[GAME]);
    free(utils->scenes[PAUSE]);
}

void second_free_utils(utils_t *utils)
{
    free(utils->scenes);
    free(utils->wallet);
    free(utils->background);
    free(utils->map->map);
    free(utils->map);
    free(utils->sound_effects);
    sfRenderWindow_destroy(utils->win);
}

void free_utils(utils_t *utils)
{
    free_grass(utils);
    free_path(utils);
    free_tspot(utils);
    free_sound(utils->sound_effects);
    first_free_utils(utils);
    second_free_utils(utils);
}
