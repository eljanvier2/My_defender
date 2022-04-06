/*
** EPITECH PROJECT, 2022
** defender
** File description:
** fade transition
*/

#include "my.h"

void fade_o(int alpha, sfRectangleShape *rect, utils_t *utils)
{
    sfColor color;
    sfEvent event;

    while (alpha != 200) {
        color = sfColor_fromRGBA(0, 0, 0, alpha);
        sfRectangleShape_setFillColor(rect, color);
        background_run(utils->background, event, utils);
        sfRenderWindow_drawRectangleShape(utils->win, rect, NULL);
        sfRenderWindow_display(utils->win);
        alpha++;
    }
}

void fade_i(int alpha, sfRectangleShape *rect, utils_t *utils)
{
    sfColor color;

    while (alpha != 0) {
        color = sfColor_fromRGBA(0, 0, 0, alpha);
        sfRectangleShape_setFillColor(rect, color);
        map_displayer(utils->map, utils->win);
        sfRenderWindow_drawRectangleShape(utils->win, rect, NULL);
        sfRenderWindow_display(utils->win);
        alpha--;
    }
}

void transition(utils_t *utils, int type)
{
    int alpha = 0;
    sfRectangleShape *trans_rect = sfRectangleShape_create();
    sfVector2f trans_rect_size;

    trans_rect_size.x = 1920;
    trans_rect_size.y = 1080;
    sfRectangleShape_setSize(trans_rect, trans_rect_size);
    if (type == 1) {
        alpha = 0;
        fade_o(alpha, trans_rect, utils);
    } else if (type == 2) {
        alpha = 200;
        fade_i(alpha, trans_rect, utils);
    }
}
