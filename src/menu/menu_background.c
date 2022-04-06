/*
** EPITECH PROJECT, 2022
** defender
** File description:
** menu background
*/

#include "my.h"

void background_run(background_t *bckg, sfEvent event, utils_t *utils)
{
    sfRenderWindow_clear(utils->win, sfBlack);
    analyse_events(utils->win, event, utils);
    sfRenderWindow_drawSprite(utils->win, bckg->sky->sprite, NULL);
    parallax_pars(bckg);
    backg_draw(bckg, utils);
    sfRenderWindow_drawSprite(utils->win, bckg->title->sprite, NULL);
    menu_draw(utils->win, utils->scenes[MENU]->buttons);
}

int how_to_play_run(background_t *bckg, sfEvent event, utils_t *utils)
{
    sfRenderWindow_clear(utils->win, sfBlack);
    if (analyse_how_events(utils, event) == 1)
        return 0;
    sfRenderWindow_drawSprite(utils->win, bckg->sky->sprite, NULL);
    parallax_pars(bckg);
    backg_draw(bckg, utils);
    sfRenderWindow_drawSprite(utils->win, bckg->title->sprite, NULL);
    how_to_play_draw(utils->win, utils->scenes[MENU]->buttons);
    sfRenderWindow_display(utils->win);
    return 1;
}

int menu_loop(utils_t *utils, sfEvent event, int analysis_status)
{
    static int how_ind = 0;

    if (how_ind != 1)
        analysis_status = analyse_menu_events(utils, event);
    if (analysis_status == 1 || analysis_status == 3)
        return analysis_status;
    if (analysis_status != 2 && how_ind == 0)
        background_run(utils->background, event, utils);
    else
        how_ind = how_to_play_run(utils->background, event, utils);
    sfRenderWindow_display(utils->win);
    return 0;
}

int menu(utils_t *utils)
{
    int error = 0;
    sfEvent event;
    int analysis_status = 0;

    utils->background = malloc(sizeof(background_t));
    error = bg_init(utils->background);
    error += buttons_init(utils);
    if (error != 0)
        return 84;
    sfMusic_play(utils->sound_effects->menu_music);
    while (sfRenderWindow_isOpen(utils->win)) {
        analysis_status = menu_loop(utils, event, analysis_status);
        if (analysis_status != 0) {
            transition(utils, 1);
            sfMusic_stop(utils->sound_effects->menu_music);
            return analysis_status;
        }
    }
    sfMusic_stop(utils->sound_effects->menu_music);
    return 0;
}
