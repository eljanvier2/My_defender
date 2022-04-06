/*
** EPITECH PROJECT, 2022
** defender
** File description:
** run
*/

#include <SFML/Graphics/RenderWindow.h>
#include "my.h"

void ennemy_handling(utils_t *utils, sfClock *wave_clock)
{
    sfTime time;
    float seconds = 0;
    int alea = rand() % 2;

    time = sfClock_getElapsedTime(wave_clock);
    seconds = time.microseconds / 1200000.0;
    if (seconds > 1.0 && utils->ennemies_nb < (5 * utils->wave_count)) {
        ennemy_linking(&utils->scenes[GAME]->ennemies, alea, utils);
        sfClock_restart(wave_clock);
        utils->ennemies_nb++;
    }
    ennemy_draw(utils->scenes[GAME], utils->win, utils->map, utils);
}

int before_game(utils_t *utils, int menu_status)
{
    menu_status = menu(utils);
    if (menu_status == 84)
        return 84;
    if (menu_status == 3) {
        free_utils(utils);
        return 4;
    }
    transition(utils, 2);
    return menu_status;
}

int run_loop(utils_t *utils, sfClock *wave_clock, sfEvent event)
{
    int error = 0;

    while (sfRenderWindow_isOpen(utils->win)) {
        if (analyse_events(utils->win, event, utils) == 1)
            error = pause_game(utils);
        if (error != 0)
            return error;
        sfRenderWindow_clear(utils->win, sfBlack);
        draws(utils, wave_clock);
        sfRenderWindow_display(utils->win);
        if (utils->scenes[GAME]->base->win == false)
            return (losing_screen(utils, utils->scenes[PAUSE]->buttons));
    }
    return 0;
}

int run(utils_t *utils)
{
    sfEvent event;
    sfClock *wave_clock = sfClock_create();
    int menu_status = 0;

    menu_status = before_game(utils, menu_status);
    if (menu_status == 4)
        return 0;
    ennemy_base_init((&utils->scenes[GAME]->ennemies), 0, utils);
    sfMusic_play(utils->sound_effects->game_music);
    if (run_loop(utils, wave_clock, event) != 0)
        return 84;
    sfMusic_stop(utils->sound_effects->game_music);
    free_utils(utils);
    return 0;
}
