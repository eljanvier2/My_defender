/*
** EPITECH PROJECT, 2022
** defender
** File description:
** sounds_init
*/

#include "my.h"

int sounds_init(audio_t *audio)
{
    audio->game_music = sfMusic_createFromFile(AUDIO_PATH[GAME_MUSIC]);
    audio->menu_music = sfMusic_createFromFile(AUDIO_PATH[MENU_MUSIC]);
    audio->buttons_click = sfSound_create();
    audio->click_buffer = sfSoundBuffer_createFromFile(AUDIO_PATH[BUTTONS]);

    if (!audio->game_music || !audio->menu_music || !audio->buttons_click || \
    !audio->click_buffer)
        return 84;
    sfSound_setBuffer(audio->buttons_click, audio->click_buffer);
    sfMusic_setLoop(audio->game_music, true);
    sfMusic_setLoop(audio->menu_music, true);
    return 0;
}
