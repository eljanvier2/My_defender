/*
** EPITECH PROJECT, 2022
** window ops
** File description:
** window ops
*/

#include "my.h"

int win_init(sfVideoMode mode, utils_t *utils)
{
    utils->win = sfRenderWindow_create(mode, "defender", sfDefaultStyle, NULL);
    if (!utils->win)
        return 84;
    sfRenderWindow_setFramerateLimit(utils->win, 10000);
    return 0;
}
