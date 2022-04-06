/*
** EPITECH PROJECT, 2022
** pause
** File description:
** pause game
*/

#include "my.h"

void pause_menu_draw(utils_t *utils, button_t **buttons)
{
    sfRenderWindow_clear(utils->win, sfBlack);
    draws(utils, NULL);
    sfRenderWindow_drawRectangleShape(utils->win, \
    utils->scenes[PAUSE]->buttons[0]->rect, NULL);
    sfRenderWindow_drawRectangleShape(utils->win, \
    utils->scenes[PAUSE]->buttons[1]->rect, NULL);
    sfRenderWindow_drawRectangleShape(utils->win, \
    utils->scenes[PAUSE]->buttons[2]->rect, NULL);
    sfRenderWindow_drawSprite(utils->win, buttons[0]->sprite, NULL);
    sfRenderWindow_drawSprite(utils->win, buttons[1]->sprite, NULL);
    sfRenderWindow_drawSprite(utils->win, buttons[2]->sprite, NULL);
    sfRenderWindow_display(utils->win);
}

int analyse_pause_events(utils_t *utils, sfEvent event)
{
    while (sfRenderWindow_pollEvent(utils->win, &event)) {
        if (event.type == sfEvtClosed || \
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)) {
            utils->pause = false;
            sfRenderWindow_close(utils->win);
        }
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP)
            utils->pause = false;
        if (event.type == sfEvtMouseButtonReleased)
            return (manage_menu_click(utils->scenes[PAUSE]->buttons, \
            event.mouseButton, utils));
    }
    return 0;
}

int pause_game(utils_t *utils)
{
    sfEvent event;
    int analysis_return = 0;
    char const *filepath = utils->map->filepath;

    while (utils->pause == true) {
        analysis_return = analyse_pause_events(utils, event);
        if (analysis_return == 1)
            utils->pause = false;
        if (analysis_return == 2) {
            free_utils(utils);
            start(filepath);
            return (-1);
        }
        if (analysis_return == 3) {
            sfRenderWindow_close(utils->win);
            return 0;
        }
        pause_menu_draw(utils, utils->scenes[PAUSE]->buttons);
    }
    return 0;
}
