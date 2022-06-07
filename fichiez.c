/*
** EPITECH PROJECT, 2022
** Minishell1
** File description:
** 2eme fichier
*/

#include "my.h"

void make_builtin(char *argv, char **cmd)
{
    pid_t pid = 0;
    int confirmation = 0;
    pid = fork();
    if (pid > 0) {
        waitpid(pid, &confirmation, 0);
        verifi(confirmation);
    } else {
        if (execve(argv, cmd, NULL) == -1)
            perror("shell");
        exit (EXIT_FAILURE);
    }
}

void get_old(char *truc, char **env, int moins)
{
    char oui[200];
    int i = 0;
    int u = 0;

    while (env[i][0] != truc[0] || env[i][2] !=  truc[1]) {
        i++;
    }
    while (env[i][u] != '\0') {
        oui[u] = env[i][u + moins];
        u++;
    }
    chdir(oui);
}

void make_cd(char *cmd,char **env)
{
    int index = 0;
    char oui[100];
    int continu = 0;
    char s[100];

    getcwd(oui, 100);
    if (cmd == NULL) {
        getcwd(s, 100);
        mauvais(env, s, 0);
        get_old("HM", env, 5);
        mauvais(env, s, 1);
    } else if (cmd[0] == '-') {
        get_old("OD", env, 7);
        getcwd(s, 100);
        mauvais(env, oui, 0);
        mauvais(env, s, 1);
    } else if (cmd[0] == '.' && cmd[1] == '.') {
        getcwd(s, 100);
        mauvais(env, s, 0);
        chdir("..");
    } else {
        getcwd(s, 100);
        mauvais(env, s, 0);
        if (eror(cmd) == 1) return;
        chdir(strtok(cmd, "\n"));
    }
}

int strcmpy(char *str1, char *str2)
{
    int i = 0;

    while (str2[i] != '\0') {
        if (str1[i] != str2[i]) {
            return 0;
        }
        i += 1;
    }
    return 1;
}
