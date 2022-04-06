/*
** EPITECH PROJECT, 2022
** analyse game menu
** File description:
** analyse game menu
*/

#include <SFML/Graphics/RenderWindow.h>
#include <SFML/Window/Event.h>
#include "my.h"

void sprite_cursor_pos_check(utils_t *util, sfVector2f m_pos, int i)
{
    if (m_pos.x >= util->map->t_spots[i]->sprite->pos.x && \
    m_pos.x <= util->map->t_spots[i]->sprite->pos.x + TILE) {
        if (m_pos.y >= util->map->t_spots[i]->sprite->pos.y && \
        m_pos.y <= util->map->t_spots[i]->sprite->pos.y + TILE)
            tower_linking(util, &util->scenes[GAME]->towers, \
            util->map->t_spots[i], util->scenes[GAME]->clic_type);
    }
}

void click_pos_check(utils_t *util)
{
    sfVector2i pos = sfMouse_getPositionRenderWindow(util->win);
    sfVector2f m_pos;

    m_pos.x = pos.x;
    m_pos.y = pos.y;
    for (int i = 0; util->map->t_spots[i] != NULL; i++)
        sprite_cursor_pos_check(util, m_pos, i);
}

void buttons_click_check(scene_t *scene, sfMouseButtonEvent event, int i, \
utils_t *utils)
{
    if (event.y >= scene->buttons[i]->pos.y && \
    event.y <= scene->buttons[i]->pos.y + TILE) {
        if (TOWER_PRICES[i - 1] <= utils->wallet->money_num) {
            scene->clic_type = i;
            menu_hider(scene);
        }
    }
}

void manage_tower_clicks(scene_t *scene, sfMouseButtonEvent event, utils_t *ut)
{
    if (event.x >= 1650 && event.x <= 1650 + TILE) {
        for (int i = 0; i < 5; i++) {
            buttons_click_check(scene, event, i, ut);
        }
    }
}

void tower_clicks(utils_t *utils, sfMouseButtonEvent event)
{
    if (utils->scenes[GAME]->menu_status == false) {
        menu_shower(utils, utils->scenes[GAME]);
        utils->scenes[GAME]->clic_type = 0;
    }
    if (utils->scenes[GAME]->menu_status == true)
        manage_tower_clicks(utils->scenes[GAME], event, utils);
}
