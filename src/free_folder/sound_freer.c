/*
** EPITECH PROJECT, 2022
** defender1
** File description:
** sound_freer
*/

#include "my.h"

void free_sound(audio_t *audio)
{
    sfSoundBuffer_destroy(audio->click_buffer);
    sfSound_destroy(audio->buttons_click);
    sfMusic_destroy(audio->menu_music);
    sfMusic_destroy(audio->game_music);
}
