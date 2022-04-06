/*
** EPITECH PROJECT, 2022
** end screen
** File description:
** loosing screen
*/

#include "my.h"

void lose_screen_draw(utils_t *utils, button_t **buttons)
{
    sfRenderWindow_clear(utils->win, sfBlack);
    sfRenderWindow_clear(utils->win, sfBlack);
    sfRenderWindow_drawSprite(utils->win, utils->scenes[LOSE]->gameobjects->sprite, NULL);
    sfRenderWindow_drawRectangleShape(utils->win, \
    utils->scenes[PAUSE]->buttons[1]->rect, NULL);
    sfRenderWindow_drawRectangleShape(utils->win, \
    utils->scenes[PAUSE]->buttons[2]->rect, NULL);
    sfRenderWindow_drawSprite(utils->win, buttons[1]->sprite, NULL);
    sfRenderWindow_drawSprite(utils->win, buttons[2]->sprite, NULL);
    sfRenderWindow_display(utils->win);
}

int losing_screen(utils_t *utils, button_t **buttons)
{
    sfEvent event;
    int analysis_return = 0;
    char const *filepath = utils->map->filepath;

    while (sfRenderWindow_isOpen(utils->win)) {
        analysis_return = analyse_pause_events(utils, event);
        if (analysis_return == 2) {
            sfMusic_stop(utils->sound_effects->game_music);
            free_utils(utils);
            start(filepath);
            return (-1);
        }
        if (analysis_return == 3) {
            sfRenderWindow_close(utils->win);
            return 0;
        }
        lose_screen_draw(utils, buttons);
    }
    return 0;
}