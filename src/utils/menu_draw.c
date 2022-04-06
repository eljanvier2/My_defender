/*
** EPITECH PROJECT, 2022
** defender
** File description:
** menu draw
*/

#include "my.h"

void backg_draw(background_t *back, utils_t *utils)
{
    sfRenderWindow_drawSprite(utils->win, back->back->sprite, NULL);
    sfRenderWindow_drawSprite(utils->win, back->mid->sprite, NULL);
    sfRenderWindow_drawSprite(utils->win, back->front->sprite, NULL);
    sfRenderWindow_drawSprite(utils->win, back->ground->sprite, NULL);
}

void menu_draw(sfRenderWindow *win, button_t **buttons)
{
    sfRenderWindow_drawRectangleShape(win, buttons[PLAY]->rect, NULL);
    sfRenderWindow_drawSprite(win, buttons[PLAY]->sprite, NULL);
    sfRenderWindow_drawRectangleShape(win, buttons[HOW]->rect, NULL);
    sfRenderWindow_drawSprite(win, buttons[HOW]->sprite, NULL);
    sfRenderWindow_drawRectangleShape(win, buttons[EXIT]->rect, NULL);
    sfRenderWindow_drawSprite(win, buttons[EXIT]->sprite, NULL);
}

void how_to_play_draw(sfRenderWindow *win, button_t **buttons)
{
    sfRenderWindow_drawRectangleShape(win, buttons[HOW_IMG]->rect, NULL);
    sfRenderWindow_drawSprite(win, buttons[HOW_IMG]->sprite, NULL);
}

void hover_draw(utils_t *utils)
{
    hover_texture(utils, utils->scenes[GAME]->clic_type);
    sfRenderWindow_drawSprite(utils->win, utils->cursor->sprite, NULL);
}

void game_menu_draw(utils_t *utils)
{
    sfRenderWindow_drawSprite(utils->win, \
    utils->scenes[GAME]->gameobjects->sprite, NULL);
    for (int i = 1; i < 5; i++) {
        sfRenderWindow_drawRectangleShape(utils->win, \
        utils->scenes[GAME]->buttons[i]->rect, NULL);
    }
    if (utils->scenes[GAME]->clic_type != 0)
        hover_draw(utils);
}
