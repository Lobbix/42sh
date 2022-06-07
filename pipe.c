/*
** EPITECH PROJECT, 2022
** function
** File description:
** function
*/

#include "my.h"

int taille(char *buff)
{
    size_t k = 0;
    char *buffer = strtok(my_strcpy(buff), " \n\0");
    for (; buffer; buffer = strtok(NULL, " \n\0")) {
        if (strcmpy(buffer, "|") == 1) return 1;
        if (strcmpy(buffer, ">>") == 1) return 4;
        if (strcmpy(buffer, "<<") == 1) return 5;
        if (strcmpy(buffer, ">") == 1) return 2;
        if (strcmpy(buffer, "<") == 1) return 3;
    }
    return 0;
}

int tete(char **env, int i, Pipe *pip)
{
    int pfd[2];
    pipe(pfd);
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        char **cmd = put_str2(pip->next->str, " \n\t");
        char *test = path(env, i, cmd);
        close(pfd[1]);
        dup2(pfd[0], 0);
        close(pfd[0]);
        execve(concat(test, cmd[0]), cmd, NULL);
        perror("shell");
        exit (EXIT_FAILURE);
    } else {
        char **cmd = put_str2(pip->str, " \n\t");
        char *test = path(env, i, cmd);
        close(pfd[0]);
        dup2(pfd[1], 1);
        close(pfd[1]);
        execve(concat(test, cmd[0]), cmd, NULL);
        perror("shell");
        exit (EXIT_FAILURE);
    }
}

void pipette(char *buff, char **env, size_t i2, char **cmd)
{
    Pipe *pipe = NULL;
    int truc = taille(buff);
    char *yes = strtok(my_strcpy(buff), "|><;\n\0");
    for (; yes != NULL; yes = strtok(NULL, "\n|><;\0")) {
        pipe = add_cell(pipe, yes);
    }
    my_putstr(buff);
    if (truc == 1) {
        do_pipe(env, pipe);
    } else if (truc == 2) {
        do_sup(env, 0, pipe);
    } else if (truc == 4) {
        do_sup2(env, 0, pipe);
    } else
        for (; pipe != NULL; pipe = pipe->next) test(pipe->str, env, i2, cmd);
}