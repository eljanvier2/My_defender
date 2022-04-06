/*
** EPITECH PROJECT, 2022
** defender
** File description:
** headers
*/

#ifndef MY_H_
    #define MY_H_

    #include <SFML/Audio.h>
    #include <SFML/Audio/Music.h>
    #include <SFML/Audio/SoundBuffer.h>
    #include <SFML/Graphics.h>
    #include <SFML/Graphics/Texture.h>
    #include <SFML/Graphics/Sprite.h>
    #include <SFML/Graphics/Color.h>
    #include <SFML/Graphics/RenderWindow.h>
    #include <SFML/Graphics/Types.h>
    #include <SFML/Graphics/Font.h>
    #include <SFML/Graphics/RectangleShape.h>
    #include <SFML/Graphics/Text.h>
    #include <SFML/System.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Vector2.h>
    #include <SFML/System/Clock.h>
    #include <SFML/Window.h>
    #include <string.h>
    #include <fcntl.h>
    #include <stdbool.h>
    #include <stddef.h>
    #include <stdio.h>
    #include <stdlib.h>
    #include <sys/stat.h>
    #include <sys/types.h>
    #include <unistd.h>
    #include <limits.h>
    #include "button_struct.h"
    #include "utils_struct.h"
    #include "enums.h"
    #include "filepaths.h"

void filepath_parse(tile_t *tile, char type);

void is_grass(map_t *map, int i, int j);
void is_path(map_t *map, int i, int j);
void is_tower(map_t *map, int i, int j);
int is_base(map_t *map, int i, int j);

int type_check(char c, char type, int count);
int map_validity_check(int rows, int linelen, int linelen_prev);
int tile_type_check(map_t *map, int i, int j);
char backn_check(char c);

void move_right(gameobject_t *obj);
void move_left(gameobject_t *obj);
void move_up(gameobject_t *obj);
void move_down(gameobject_t *obj);
void ennemy_moves_handle(utils_t *utils, \
base_t *base, gameobject_t **obj, map_t *map);

void move_selector(utils_t *util, base_t *base, gameobject_t *obj, map_t *map);
int next_tile_part2(gameobject_t *obj, map_t *map);
int next_tile(gameobject_t *obj, map_t *map);
int base_attack(utils_t *utils, base_t *base, gameobject_t *obj, map_t *map);

int analyse_events(sfRenderWindow *window, sfEvent event, utils_t *utils);
int analyse_menu_events(utils_t *utils, sfEvent event);
int manage_menu_click(button_t **buttons, sfMouseButtonEvent event,\
utils_t *utils);
int analyse_how_events(utils_t *utils, sfEvent event);
void tower_clicks(utils_t *utils, sfMouseButtonEvent event);

int scenes_init(utils_t *utils);

int ennemy_base_init(ennemy_list_t **ennemy, int type, utils_t *utils);
void ennemy_linking(ennemy_list_t **e1, int type, utils_t *utils);
void delete_ennemy(ennemy_list_t *removed, utils_t *utils);
utils_t *utils_init(utils_t *utils);
int map_start_finder(utils_t *utils);

int map_loader(char const *filepath, map_t *map);
int tile_placer(map_t *map);

int tile_gen(map_t *map);

void transition(utils_t *utils, int type);

int menu(utils_t *utils);
void background_run(background_t *bckg, sfEvent event, utils_t *utils);

int bg_init(background_t *bckg);
int buttons_init(utils_t *utils);
int error_check(gameobject_t *obj_struct);
button_t *how_to_play_obj(button_t *button);

void parallax_pars(background_t *bckg);

void map_displayer(map_t *map, sfRenderWindow *win);
void ennemy_draw(scene_t *scene, sfRenderWindow *win, map_t *map, \
utils_t *utils);
void delete_obj(gameobject_t *obj);

void game_menu_draw(utils_t *utils);
void backg_draw(background_t *back, utils_t *utils);
void menu_draw(sfRenderWindow *win, button_t **buttons);
void how_to_play_draw(sfRenderWindow *win, button_t **buttons);
void hover_draw(utils_t * utils);
void first_ennemy_draw(scene_t *scene, sfRenderWindow *win, map_t *map, \
utils_t *utils);

int my_putstr(char const *str);
int my_putsterr(char const *str);

int tile_obj_create(tile_t *tile, char type);
int text_add(button_t *button, int ind);
int obj_create(gameobject_t *obj);
button_t *create_btn(button_t *button, int pos_x, int pos_y, int btn_nbr);
gameobject_t *create_parallax_object(const char *path);

int my_strcmp(char const *s1, char const *s2);

int run(utils_t *utils);

int start(char const *filepath);

int win_init(sfVideoMode mode, utils_t *utils);

void free_grass(utils_t *utils);
void free_path(utils_t *utils);
void free_tspot(utils_t *utils);
void free_utils(utils_t *utils);
void free_sound(audio_t *audio);
void first_free_utils(utils_t *utils);

int menu_create(gameobject_t *obj);
int game_menu_buttons(scene_t *scene);

int sounds_init(audio_t *audio);

void hover_texture(utils_t *utils, int type);

void tower_linking(utils_t *ut, tower_list_t **t1, tile_t *tile, int type);

void tower_draw(scene_t *scene, sfRenderWindow *win);

void ennemy_list_rewind(scene_t *scene);

int ennemies_in_base(utils_t *utils, base_t *base);

int health_check(scene_t *scene, ennemy_list_t *ennemy, utils_t *utils);

void menu_hider(scene_t *scene);
void menu_shower(utils_t *utils, scene_t *scene);
void lose_menu_draw(utils_t *utils);

void click_pos_check(utils_t *util);

void sprite_clock_handle(gameobject_t *obj);

char *my_revstr(char *str);
int my_strlen(char const *str);

void wallet_update(utils_t *utils);
int wallet_init(utils_t *utils);

void draws(utils_t *utils, sfClock *wave_clock);

int pause_game(utils_t *utils);

void ennemy_handling(utils_t *utils, sfClock *wave_clock);

int analyse_pause_events(utils_t *utils, sfEvent event);

int losing_screen(utils_t *utils, button_t **buttons);

#endif
