/*
** EPITECH PROJECT, 2022
** defender
** File description:
** enums
*/

#ifndef ENUM_H_
    #define ENUM_H_

enum map_obj {
    PATH = '0',
    TOWER_SPOT = 'T',
    BASE = 'B',
    ENNEMY = 'E',
    GRASS = '.',
    START = 'S',
    MAP_END = 'X'
};

enum parallax_ind {
    SKY,
    GROUND,
    BACK,
    MID,
    FRONT,
    TITLE
};

enum button_ind {
    PLAY,
    HOW,
    EXIT,
    HOW_IMG,
    RESU,
    MAIN,
    EXIT2
};

enum scenes {
    MENU,
    GAME,
    LOSE,
    PAUSE
};

enum ennemies {
    HORD,
    BOSS
};

enum moves {
    VOID,
    RIGHT,
    DOWN,
    UP,
    LEFT,
    END
};

enum towers {
    TOWER1,
    TOWER2,
    TOWER3,
    TOWER4
};

enum tile_size {
    TILE = 108
};

enum audio_path {
    GAME_MUSIC,
    MENU_MUSIC,
    BUTTONS
};

#endif
