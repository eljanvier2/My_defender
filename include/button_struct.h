/*
** EPITECH PROJECT, 2022
** defender
** File description:
** button structure
*/

#include <SFML/Graphics/Types.h>
#include <SFML/System/Vector2.h>

#ifndef BUTTON_H_
    #define BUTTON_H_

typedef struct button_s {
    sfRectangleShape *rect;
    sfVector2f pos;
    sfVector2f size;
    sfTexture *texture;
    sfText *text;
    sfSprite *sprite;
    sfTexture *text_img;
    sfVector2f text_pos;
} button_t;

#endif
