/*
** EPITECH PROJECT, 2022
** defender
** File description:
** filepaths
*/

#include "enums.h"

#ifndef FILEPATHS_H_
    #define FILEPATHS_H_

static const char *const FILEPATHS[] = {
    [SKY] = "./ressources/menu_paral/back.png",
    [GROUND] = "./ressources/menu_paral/ground.png",
    [BACK] = "./ressources/menu_paral/back_decor.png",
    [MID] = "./ressources/menu_paral/mid.png",
    [FRONT] = "./ressources/menu_paral/front.png",
    [TITLE] = "./ressources/menu_paral/title.png"
};

static const char *const BUTTON_PATHS[] = {
    [0] = "./ressources/menu_paral/button.png",
    [1] = "./ressources/towers/locked_towers/rocket_tower_locked.png",
    [2] = "./ressources/towers/locked_towers/simple_tower_locked.png",
    [3] = "./ressources/towers/locked_towers/zone_tower_high_locked.png",
    [4] = "./ressources/towers/locked_towers/zone_tower_low_dmg.png",
    [5] = "./ressources/towers/locked_towers/cadenas.png"
};

static const char *const TEXT_PATHS[] = {
    [PLAY] = "./ressources/menu_paral/play.png",
    [HOW] = "./ressources/menu_paral/how.png",
    [EXIT] = "./ressources/menu_paral/exit.png",
    [RESU] = "./ressources/menu_paral/resume.png",
    [MAIN] = "./ressources/menu_paral/main.png",
    [EXIT2] = "./ressources/menu_paral/exit.png",
    [HOW_IMG] = "./ressources/menu_paral/how_to_play.png"
};

static const char *const ENNEMY_PATHS[] = {
    [HORD] = "./ressources/ennemy1/hord.png",
    [BOSS] = "./ressources/ennemy2/boss_spritesheet.png"
};

static const char *const AUDIO_PATH[] = {
    [MENU_MUSIC] = "./ressources/audio_files/menu_music.wav",
    [GAME_MUSIC] = "./ressources/audio_files/game_music.wav",
    [BUTTONS] = "./ressources/audio_files/click_sound.wav",
};

static const char *const TOWER_PATH[] = {
    [TOWER1] = "./ressources/towers/unlocked_towers/rocket_tower.png",
    [TOWER2] = "./ressources/towers/unlocked_towers/simple_tower.png",
    [TOWER3] = "./ressources/towers/unlocked_towers/zone_tower_high_dmg.png",
    [TOWER4] = "./ressources/towers/unlocked_towers/zone_tower_low_dmg.png"
};

static const int TOWER_PRICES[] = {
    [TOWER1] = 10,
    [TOWER2] = 20,
    [TOWER3] = 30,
    [TOWER4] = 40
};

#endif
