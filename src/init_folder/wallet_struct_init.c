/*
** EPITECH PROJECT, 2022
** defender
** File description:
** wallet
*/

#include <SFML/Graphics/Font.h>
#include <SFML/Graphics/Text.h>
#include "my.h"

void wallet_init_sets(utils_t *utils)
{
    sfText_setFont(utils->wallet->money_text, utils->wallet->font);
    sfText_setFont(utils->wallet->money, utils->wallet->font);
    sfText_setString(utils->wallet->money_text, "Money : ");
    sfText_setString(utils->wallet->money, utils->wallet->num_char);
    sfText_setPosition(utils->wallet->money_text, utils->wallet->pos1);
    sfText_setPosition(utils->wallet->money, utils->wallet->pos2);
}

int wallet_init(utils_t *utils)
{
    utils->wallet->pos1.x = 50;
    utils->wallet->pos1.y = 980;
    utils->wallet->pos2.x = 210;
    utils->wallet->pos2.y = 980;
    utils->wallet->font = \
    sfFont_createFromFile("./ressources/Font/Rounded.ttf");
    utils->wallet->money_text = sfText_create();
    utils->wallet->money = sfText_create();
    utils->wallet->clock = sfClock_create();
    utils->wallet->num_char = malloc(sizeof(char) * 5);
    utils->wallet->num_char[0] = '0';
    utils->wallet->num_char[1] = '\0';
    if (!utils->wallet->money_text || !utils->wallet->money || \
    !utils->wallet->clock)
        return 84;
    wallet_init_sets(utils);
    return 0;
}

char *count_wallet(utils_t *utils)
{
    int i = 0;
    int ret = (utils->wallet->money_num) % 10;
    int tmp = utils->wallet->money_num;

    if (utils->wallet->money_num == 0) {
        utils->wallet->num_char[i] = '0';
        utils->wallet->num_char[i + 1] = '\0';
        return "0";
    }
    while (utils->wallet->money_num != 0) {
        ret = utils->wallet->money_num % 10;
        utils->wallet->num_char[i] = (ret > 9) ? (ret - 10) + 'a' : ret + '0';
        utils->wallet->money_num /= 10;
        i++;
    }
    utils->wallet->num_char[i] = '\0';
    my_revstr(utils->wallet->num_char);
    utils->wallet->money_num = tmp;
    return utils->wallet->num_char;
}

void wallet_update(utils_t *utils)
{
    sfTime time = sfClock_getElapsedTime(utils->wallet->clock);
    float seconds = time.microseconds / 250000.0;

    if (seconds > 1.0) {
        sfText_setString(utils->wallet->money, count_wallet(utils));
        sfClock_restart(utils->wallet->clock);
    }
    sfRenderWindow_drawText(utils->win, utils->wallet->money_text, NULL);
    sfRenderWindow_drawText(utils->win, utils->wallet->money, NULL);
}
