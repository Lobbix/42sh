/*
** EPITECH PROJECT, 2022
** function
** File description:
** function
*/

#include "my.h"

void my_strangeputchar(char *buff)
{
    int i = 0;

    while (buff[i] != ' ') {
        i++;
    }
    i++;
    while (buff[i] != '\0') {
        if (buff[i] == '"')
            i++;
        my_putchar(buff[i]);
        i++;
    }
}

int do_echo(char *buff, char **env)
{
    int i = 0;
    int j = 0;

    while (buff[i] != '\0') {
        if (buff[i] == '$') {
            put_var(buff, env);
            j = 1;
        }
        else if (buff[i] == '"' && j == 0) {
            my_strangeputchar(buff);
            return (1);
        }
        i++;
    }
}

void my_print(char *oui)
{
    int i = 0;

    while (oui[i] != '=') {
        i++;
    }
    i++;
    while (oui[i] != '\0') {
        my_putchar(oui[i]);
        i++;
    }
}

void put_var(char *buff, char **env)
{
    int i = 0;
    int j = 0;

    while (buff[i] != '$') {
        i ++;
    }
    i++;
    while (env[j] != NULL) {
        if (env[j][0] == buff[i] && env[j][1] == buff[i + 1]) {
            my_print(env[j]);
        }
        j++;
    }
    my_putchar('\n');
}

int eror(char *cmd)
{
    if (opendir(cmd) == NULL) {
        my_putstr(cmd);
        my_putstr(": no such file or directory\n");
        return (1);
    }
}
