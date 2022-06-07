/*
** EPITECH PROJECT, 2022
** function
** File description:
** function
*/

#include "my.h"

void test(char *buff, char **env, size_t i, char **cmd)
{
    char s[100];
    if (buff[0] == '.') {
        my_putstr(strtok(buff, " \n"));
        my_putstr(": Command not found.\n");
        exit (1);
    } else if (third_try(env, i, buff) == 1);
    else if (seconde_try(buff, cmd, env, s) == 1);
    else if (first_try(buff, cmd, env) == 1);
    else {
        my_putstr(strtok(buff, " \n"));
        my_putstr(": Command not found.\n");
    }
}

char *my_revstr(char *str)
{
    int i = my_strlen(str) - 1;
    int j = 0;
    char c;

    while (j < (i/2) + 1) {
        c = str[i - j];
        str[i - j] = str[j];
        str[j] = c;
        j += 1;
    }
    return (str);
}

char *int_to_str(int i)
{
    char *str = malloc (sizeof(char) * (100));
    int a = 0;
    while (i > 9) {
        str[a] = i % 10 + 48;
        i = i / 10;
        a = a + 1;
    }
    str[a] = i + 48;
    str[a + 1] = '\0';
    my_revstr(str);
    return (str);
}
