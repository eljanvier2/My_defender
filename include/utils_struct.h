/*
** EPITECH PROJECT, 2022
** defender
** File description:
** utils struct
*/

#include <SFML/Audio/Types.h>
#include <SFML/Graphics/Text.h>
#include <SFML/System/Types.h>
#include <stdbool.h>
#include <stdio.h>
#include "button_struct.h"

#ifndef UTS_H_
    #define UTS_H_

typedef struct gameobject {
    char const *filepath;
    sfSprite *sprite;
    sfTexture *texture;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *texture_clock;
    sfClock *movement_clock;
    int walking_progress;
    int tile_x;
    int tile_y;
    int previous_tile;
    int speed;
    float clock_refresh;
    char type;
} gameobject_t;

typedef struct tile_s {
    char type;
    gameobject_t *sprite;
    gameobject_t *texture;
    gameobject_t *clock;
} tile_t;

typedef struct backgrounds
{
    gameobject_t *sky;
    gameobject_t *ground;
    gameobject_t *back;
    gameobject_t *mid;
    gameobject_t *front;
    gameobject_t *title;
} background_t;

typedef struct map_s {
    char **map;
    char const *filepath;
    FILE *file;
    tile_t **grass;
    tile_t **path;
    tile_t **t_spots;
    tile_t *base;
    int base_health;
    int grass_ind;
    int path_ind;
    int tspot_ind;
} map_t;

typedef struct ennemy_list_s {
    gameobject_t *ennemy;
    char *path;
    int path_ind;
    int health;
    int type;
    int death_price;
    int in_base;
    struct ennemy_list_s *next;
    struct ennemy_list_s *prev;
} ennemy_list_t;

typedef struct cursor_s {
    sfTexture *texture;
    sfSprite *sprite;
    sfVector2i mouse_pos;
    sfVector2f pos;
} cursor_t;

typedef struct tower_list_s {
    gameobject_t *tower;
    int damage;
    int type;
    int price;
    sfClock *shot_clock;
    struct tower_list_s *next;
    struct tower_list_s *prev;
} tower_list_t;

typedef struct base_s {
    sfClock *ennemy_refresh;
    int max_ennemy;
    int ennemies_in;
    bool win;
} base_t;

typedef struct scene_s {
    button_t **buttons;
    ennemy_list_t *ennemies;
    tower_list_t *towers;
    gameobject_t *gameobjects;
    base_t *base;
    int base_health;
    int clic_type;
    int menu_status;
} scene_t;

typedef struct audio_s {
    sfMusic *menu_music;
    sfMusic *game_music;
    sfSound *buttons_click;
    sfSoundBuffer *click_buffer;
} audio_t;

typedef struct wallet_s {
    sfText *money_text;
    sfText *money;
    sfFont *font;
    sfVector2f pos1;
    sfVector2f pos2;
    sfVector2f scale;
    sfClock *clock;
    int money_num;
    char *num_char;
    int tmp_val;
    int fin_nbr;
} wallet_t;

typedef struct utils_s {
    sfRenderWindow *win;
    background_t *background;
    map_t *map;
    wallet_t *wallet;
    scene_t **scenes;
    audio_t *sound_effects;
    cursor_t *cursor;
    int wave_count;
    int ennemies_nb;
    int dead_ennemies;
    bool pause;
} utils_t;

#endif
