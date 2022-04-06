/*
** EPITECH PROJECT, 2022
** defender
** File description:
** object creation functions
*/

#include "my.h"

int tile_obj_create(tile_t *tile, char type)
{
    if (!(tile->sprite = malloc(sizeof(gameobject_t))))
        return 84;
    filepath_parse(tile, type);
    tile->sprite->rect.width = TILE;
    tile->sprite->rect.height = TILE;
    tile->sprite->pos.x = 0;
    tile->sprite->pos.y = 0;
    if (!(tile->sprite->sprite = sfSprite_create()))
        return 84;
    if (!(tile->sprite->texture = \
    sfTexture_createFromFile(tile->sprite->filepath, NULL)))
        return 84;
    sfSprite_setTexture(tile->sprite->sprite, tile->sprite->texture, 0);
    sfSprite_setPosition(tile->sprite->sprite, tile->sprite->pos);
    return 0;
}

int obj_create(gameobject_t *obj)
{
    obj->rect.width = TILE;
    obj->rect.height = TILE;
    obj->rect.left = 0;
    obj->pos.x = 0;
    obj->pos.y = 0;
    obj->sprite = sfSprite_create();
    if (!obj->sprite)
        return 84;
    obj->texture = sfTexture_createFromFile(obj->filepath, NULL);
    if (!obj->texture)
        return 84;
    sfSprite_setTexture(obj->sprite, obj->texture, 0);
    sfSprite_setPosition(obj->sprite, obj->pos);
    sfSprite_setTextureRect(obj->sprite, obj->rect);
    obj->texture_clock = sfClock_create();
    obj->movement_clock = sfClock_create();
    obj->walking_progress = 0;
    return 0;
}

button_t *create_btn(button_t *button, int pos_x, int pos_y, int btn_nbr)
{
    button->rect = sfRectangleShape_create();
    if (btn_nbr == 0) {
        button->size.x = 600;
        button->size.y = 125;
    } else {
        button->size.x = TILE;
        button->size.y = TILE;
    }
    button->pos.x = pos_x;
    button->pos.y = pos_y;
    if (!(button->texture = \
    sfTexture_createFromFile(BUTTON_PATHS[btn_nbr], NULL)))
        return NULL;
    sfRectangleShape_setPosition(button->rect, button->pos);
    sfRectangleShape_setTexture(button->rect, button->texture, false);
    sfRectangleShape_setSize(button->rect, button->size);
    return button;
}

int text_add(button_t *button, int ind)
{
    if (!(button->sprite = sfSprite_create()))
        return 84;
    if (!(button->text_img = sfTexture_createFromFile(TEXT_PATHS[ind], NULL)))
        return 84;
    sfSprite_setTexture(button->sprite, button->text_img, false);
    sfSprite_setPosition(button->sprite, button->pos);
    return 0;
}
