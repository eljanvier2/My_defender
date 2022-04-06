/*
** EPITECH PROJECT, 2022
** analyse events
** File description:
** analyse events
*/

#include "my.h"

int analyse_events(sfRenderWindow *window, sfEvent event, utils_t *utils)
{
    while (sfRenderWindow_pollEvent(window, &event)) {
        if (event.type == sfEvtClosed || \
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            sfRenderWindow_close(window);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyP) {
            utils->pause = true;
            return 1;
        }
        if (event.type == sfEvtMouseButtonReleased)
            tower_clicks(utils, event.mouseButton);
    }
    return 0;
}

int analyse_menu_events(utils_t *utils, sfEvent event)
{
    while (sfRenderWindow_pollEvent(utils->win, &event)) {
        if (event.type == sfEvtClosed || \
        (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape))
            sfRenderWindow_close(utils->win);
        if (event.type == sfEvtMouseButtonReleased)
            return (manage_menu_click(utils->scenes[MENU]->buttons, \
            event.mouseButton, utils));
    }
    return 0;
}

int analyse_how_events(utils_t *utils, sfEvent event)
{
    while (sfRenderWindow_pollEvent(utils->win, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(utils->win);
        if (event.type == sfEvtKeyPressed && event.key.code == sfKeyEscape)
            return 1;
    }
    return 0;
}

int manage_menu_click(button_t **buttons, \
sfMouseButtonEvent event, utils_t *utils)
{
    if (event.x >= 660 && event.x <= 1260) {
        if (event.y >= buttons[PLAY]->pos.y && \
        event.y <= buttons[PLAY]->pos.y + 125) {
            sfSound_play(utils->sound_effects->buttons_click);
            return 1;
        }
        if (event.y >= buttons[HOW]->pos.y && \
        event.y <= buttons[HOW]->pos.y + 125) {
            sfSound_play(utils->sound_effects->buttons_click);
            return 2;
        }
        if (event.y >= buttons[EXIT]->pos.y && \
        event.y <= buttons[EXIT]->pos.y + 125) {
            sfSound_play(utils->sound_effects->buttons_click);
            return 3;
        }
    }
    return 0;
}
