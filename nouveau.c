/*
** EPITECH PROJECT, 2022
** Minishell
** File description:
** Minishell
*/

#include "my.h"

char *make_fusion(char **cmd)
{
    char *truc = malloc(sizeof(char) * 200000);
    int i = 0;
    int o = 0;
    while (cmd[1][i] != '\0') {
        truc[o] = cmd[1][i];
        o++;
        i++;
    }
    truc[o] = '=';
    o++;
    if (cmd[2] == NULL)
        truc[o] = '\0';
    else {
        i = 0;
        while (cmd[2][i] != '\0') {
            truc[o] = cmd[2][i];
            o++;
            i++;
        }
        truc[o] = '\0';
    }
    return (truc);
}

void set_env(char **env, char **cmd)
{
    int i = 0;

    while (env[i] != NULL) {
        if (env[i][0] == cmd[1][0] && env[i][1] == cmd[1][1]) {
            env[i] = make_fusion(cmd);
            return ;
        }
        i++;
    }
    env[i] = make_fusion(cmd);
    env[i + 1] = NULL;
}

int unset_env(char **env, char **cmd)
{
    int i = 0;

    while (env[i] != NULL) {
        if (env[i][0] == cmd[1][0] && env[i][1] == cmd[1][1]
            && env[i][2] == cmd[1][2]) {
            env[i] = NULL;
            return (1);
        }
        i++;
    }
}

char *concat(char *str, char *str2)
{
    char *final = malloc(sizeof(char) * 100);
    int i = 0;
    int u = 0;

    while (str[u]) {
        final[i] = str[u];
        u++;
        i++;
    }
    u = 0;
    final[i] = '/';
    i++;
    while (str2[u]) {
        final[i] = str2[u];
        u++;
        i++;
    }
    final[i] = '\0';
    return final;
}

void mauvais(char **env, char *s, int p)
{
    int i = 0;
    while (env[i] != NULL) {
        if (env[i][0] == 'P' && env[i][1] == 'W' &&
            env[i][2] == 'D' && p == 1) {
            env[i] = concat("PWD=", s);
        } else if (env[i][0] == 'O' && env[i][1] == 'L'
            && env[i][2] == 'D' && p == 0)
            env[i] = concat("OLDPWD=", s);
        i++;
    }
}
