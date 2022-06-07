#include "my.h"

void do_pipe(char **env, Pipe *pipe)
{
    pid_t pid = 0;
    int confirmation = 0;
    pid = fork();
    if (pid > 0) {
        waitpid(pid, &confirmation, 0);
        verifi(confirmation);
    } else {
        tete(env, 0, pipe);
    }
}

int do_sup(char **env, int i, Pipe *pip)
{
    int fd;
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        fd = open(pip->next->str, O_RDWR | O_CREAT , S_IRWXU);
        char **cmd = put_str2(pip->str, " \n\t");
        char *test = path(env, i, cmd);
        dup2(fd, 1);
        execve(concat(test, cmd[0]), cmd, NULL);
        close(fd);
        perror("shell");
        exit (EXIT_FAILURE);
    }
}

int do_sup2(char **env, int i, Pipe *pip)
{
    int fd;
    pid_t pid;
    pid = fork();
    if (pid == 0) {
        fd = open(pip->next->str, O_RDWR | O_APPEND | O_CREAT, S_IRWXU);
        char **cmd = put_str2(pip->str, " \n\t");
        char *test = path(env, i, cmd);
        dup2(fd, 1);
        execve(concat(test, cmd[0]), cmd, NULL);
        close(fd);
        perror("shell");
        exit (EXIT_FAILURE);
    }
}

void do_fichier(char **env, Pipe *pipe)
{
    pid_t pid = 0;
    int confirmation = 0;
    pid = fork();
    if (pid > 0) {
        waitpid(pid, &confirmation, 0);
        verifi(confirmation);
    } else {
        do_sup(env, 0, pipe);
    }
}