/*
** EPITECH PROJECT, 2022
** defender
** File description:
** menu init
*/

#include "my.h"

int error_check(gameobject_t *obj_struct)
{
    if (!obj_struct->texture)
        return 84;
    if (!obj_struct->sprite)
        return 84;
    return 0;
}

void speed_init(background_t *bckg)
{
    bckg->ground->speed = 1;
    bckg->ground->clock_refresh = 100;
    bckg->back->speed = 2;
    bckg->back->clock_refresh = 25;
    bckg->mid->speed = 2;
    bckg->mid->clock_refresh = 17;
    bckg->front->speed = 1;
    bckg->front->clock_refresh = 19;
}

int bg_init(background_t *bckg)
{
    bckg->sky = create_parallax_object(FILEPATHS[SKY]);
    bckg->ground = create_parallax_object(FILEPATHS[GROUND]);
    bckg->back = create_parallax_object(FILEPATHS[BACK]);
    bckg->mid = create_parallax_object(FILEPATHS[MID]);
    bckg->front = create_parallax_object(FILEPATHS[FRONT]);
    bckg->title = create_parallax_object(FILEPATHS[TITLE]);
    speed_init(bckg);
    if (bckg == NULL) {
        my_putsterr("Error initializing background");
        return 84;
    }
    return 0;
}

button_t *how_to_play_obj(button_t *button)
{
    button->rect = sfRectangleShape_create();
    button->size.x = 1050;
    button->size.y = 675;
    button->pos.x = 0;
    button->pos.y = 0;
    button->text_pos.x = 435;
    button->text_pos.y = 355;
    if (!(button->texture = \
    sfTexture_createFromFile("./ressources/menu_paral/how_texture.png", NULL)))
        return NULL;
    sfRectangleShape_setPosition(button->rect, button->text_pos);
    sfRectangleShape_setTexture(button->rect, button->texture, false);
    sfRectangleShape_setSize(button->rect, button->size);
    if (!(button->sprite = sfSprite_create()) || \
    !(button->text_img = sfTexture_createFromFile(TEXT_PATHS[HOW_IMG], NULL)))
        return NULL;
    sfSprite_setTexture(button->sprite, button->text_img, false);
    sfSprite_setPosition(button->sprite, button->pos);
    return button;
}

int buttons_init(utils_t *util)
{
    int pos_y = 0;

    if (!(util->scenes[MENU]->buttons = malloc(sizeof(button_t *) * 4)))
        return 84;
    for (int i = 0; i < 4; i++)
        if (!(util->scenes[MENU]->buttons[i] = malloc(sizeof(button_t))))
            return 84;
    for (int i = 0; i < 3; i++) {
        pos_y = 400 + (200 * i);
        util->scenes[MENU]->buttons[i] = \
        create_btn(util->scenes[MENU]->buttons[i], 660, pos_y, 0);
        if (text_add(util->scenes[MENU]->buttons[i], i) == 84)
            return 84;
    }
    if ((util->scenes[MENU]->buttons[3] = \
    how_to_play_obj(util->scenes[MENU]->buttons[3])) == NULL)
        return 84;
    return 0;
}
