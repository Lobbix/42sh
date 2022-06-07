/*
** EPITECH PROJECT, 2021
** my.h
** File description:
** tt les trucs
*/

#pragma once
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stddef.h>
#include "stdarg.h"
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdbool.h>
#include <pwd.h>
#include <time.h>

typedef struct Pipe {
    char *str;
    int separ;
    struct Pipe *next;
} Pipe;

char *my_strncpy(char *dest, char const *src, int n, int z);
int my_strlen(char *str);
void my_putstr(char *str);
void my_putchar(char c);
void my_binary (int z);
void my_octal(int nombre);
void my_strange_nbr(char *str);
void my_putnbr(int nbr);
void my_printf(char *frm, ...);
void not_possible(int j);
void my_hexa(int nombre, int ui);
int my_getnbr(char *str);
char *int_to_str(int i);
char *my_revstr(char *str);

void make_builtin(char *argv, char **cmd);
void get_old(char *truc, char **env, int moins);
void make_cd(char *cmd,char **env);
int strcmpy(char *str1, char *str2);

void my_strangeputchar(char *buff);
int do_echo(char *buff, char **env);
void my_print(char *oui);
void put_var(char *buff, char **env);
int eror(char *cmd);

void verifi(int verification);
char *my_strcpy(char *src);
char **put_str2(char *av, char *truc);

char *make_fusion(char **cmd);
void set_env(char **env, char **cmd);
int unset_env(char **env, char **cmd);
char *concat(char *str, char *str2);
void mauvais(char **env, char *s, int p);

char *path(char **env, int i, char **cmd);
int first_try(char *buff, char **cmd, char **env);
int seconde_try(char *buff, char **cmd, char **env, char *s);
int third_try(char **env, int i, char *buff);
int main_inf(int argc, char **argv, char **env);
int main(int argc, char **argv, char **env);

Pipe *creat_cell(char *str);
Pipe *add_cell(Pipe *pipe, char *str);
void affichage(Pipe *pipe);

void pipette(char *buff, char **env, size_t i2, char **cmd);
int taille(char *buff);
int tete(char **env, int i, Pipe *pip);

void test(char *buff, char **env, size_t i, char **cmd);

void do_pipe(char **env, Pipe *pipe);
void do_fichier(char **env, Pipe *pipe);
int do_sup(char **env, int i, Pipe *pip);
int do_sup2(char **env, int i, Pipe *pip);
