/*
** EPITECH PROJECT, 2022
** minishell1
** File description:
** main of minishell
*/

#include "my.h"

char *path(char **env, int i, char **cmd)
{
    while ((env[i][0] != 'P' || env[i][3] != 'H')) {
        i++;
        if (env[i] == NULL)
            return NULL;
    }
    strtok(my_strcpy(env[i]), "=");
    char *test = strtok(NULL, ":");
    while (test != NULL && access(concat(test, cmd[0]), 0) != 0) {
        test = strtok(NULL, ":");
    }
    return test;
}

int first_try(char *buff, char **cmd, char **env)
{
    int i = 0;
    if (strcmpy(buff, "exit\n") == 1)
        exit (0);
    cmd = put_str2(buff, " \n\t");
    if (buff[0] == '.') {
        make_builtin(cmd[0], cmd);
        return (1);
    }
    if (buff[0] == '/') {
        third_try(env, 0, "env");
        return 1;
    }
    char *test = path(env, i, cmd);
    if (test != NULL) {
        make_builtin(concat(test, cmd[0]), cmd);
        return (1);
    }
    return (0);
}

int seconde_try(char *buff, char **cmd, char **env, char *s)
{
    if (strcmpy(buff, "cd") == 1) {
        cmd = put_str2(buff, " \n\t");
        make_cd(cmd[1], env);
        mauvais(env, getcwd(s, 100), 1);
        return (1);
    } else if (strcmpy(buff, "setenv") == 1) {
        cmd = put_str2(buff, " \n\t");
        set_env(env, cmd);
        return (1);
    } else if (strcmpy(buff, "unsetenv") == 1) {
        cmd = put_str2(buff, " \n\t");
        unset_env(env,cmd);
        return (1);
    }
    return 0;
}

int third_try(char **env, int i, char *buff)
{
    if (strcmpy(buff, "env") == 1) {
        i = 0;
        while (env[i]) {
            my_putstr(env[i]);
            my_putchar('\n');
            i++;
        }
        return 1;
    } else if (strcmpy(buff, "echo") == 1) {
        do_echo(buff, env);
        return 1;
    }
    return 0;
}

int main_inf(int argc, char **argv, char **env)
{
    size_t i = 0;
    char *buff = NULL;
    char **cmd = NULL;
    char s[100];

    my_putstr("$> ");
    if (getline(&buff,&i,stdin) == -1) {
        my_putstr("exit");
        exit (0);
    }
    test(buff, env, i, cmd);
    main_inf(argc, argv, env);
    /*
    if (strtok(my_strcpy(buff)," \n\t") != NULL) {
        if (third_try(env, i, buff) == 1) main_inf(argc, argv, env);
        if (seconde_try(buff, cmd, env, s) == 1) main_inf(argc, argv, env);
        if (first_try(buff, cmd, env) == 1) main_inf(argc, argv, env);
        my_putstr(strtok(buff, "\n"));
        my_putstr(": Command not found.\n");
        main_inf(argc, argv, env);
    } else {
        main_inf(argc, argv, env);
    }*/
}

int main(int argc, char **argv, char **env)
{
    size_t i = 0;
    char *buff = NULL;
    char **cmd = NULL;
    char *etoile;
    while (isatty(0) == 0) {
        if (getline(&buff,&i,stdin) == -1) exit (0);
        if (strtok(my_strcpy(buff), " \n\t") != NULL) {
            //my_putstr(buff);
            //test(buff, env, i, cmd);
            pipette(buff, env, i, cmd);
        }
    }
    main_inf(argc, argv, env);
}
