/*
** EPITECH PROJECT, 2022
** defender
** File description:
** main file
*/

#include "my.h"

int usage(int argc, char const *argv[])
{
    if (!argv)
        exit(84);
    for (int i = 0; i < argc; i++) {
        if (my_strcmp(argv[i], "-h") == 0) {
            my_putstr("./my_defender [MAP FILE PATH]");
            return 1;
        }
    }
    return 0;
}

int env_check(char const **env)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (my_strcmp(env[i], "DISPLAY") == 0)
            return 0;
    }
    return 84;
}

int main(int argc, char const *argv[], char const **env)
{
    if (!argv)
        return 84;
    if (env_check(env) != 0)
        return 84;
    if (usage(argc, argv) == 1)
        return 0;
    if (argc < 2)
        return (start(NULL));
    char const *filepath = argv[1];
    return (start(filepath));
}
