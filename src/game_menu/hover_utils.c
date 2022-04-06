/*
** EPITECH PROJECT, 2022
** hover utils
** File description:
** hover utils
*/

#include "my.h"

void hover_texture(utils_t *utils, int type)
{
    utils->cursor->mouse_pos = sfMouse_getPositionRenderWindow(utils->win);
    utils->cursor->pos.x = utils->cursor->mouse_pos.x;
    utils->cursor->pos.y = utils->cursor->mouse_pos.y;
    utils->cursor->texture = sfTexture_createFromFile(TOWER_PATH[type - 1], 0);
    utils->cursor->sprite = sfSprite_create();
    sfSprite_setTexture(utils->cursor->sprite, utils->cursor->texture, true);
    sfSprite_setPosition(utils->cursor->sprite, utils->cursor->pos);
}
