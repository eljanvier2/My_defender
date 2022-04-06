/*
** EPITECH PROJECT, 2022
** defender
** File description:
** main running file
*/

#include "my.h"

int start(char const *filepath)
{
    utils_t *utils = NULL;
    sfVideoMode mode = {1920, 1080, 600};
    int error = 0;

    if ((utils = utils_init(utils)) == NULL)
        return 84;
    if (filepath == NULL)
        utils->map->filepath = NULL;
    else
        utils->map->filepath = filepath;
    error = map_loader(filepath, utils->map);
    error += tile_gen(utils->map);
    error += win_init(mode, utils);
    error += scenes_init(utils);
    error += wallet_init(utils);
    error += sounds_init(utils->sound_effects);
    if (error != 0)
        return 84;
    return (run(utils));
}
