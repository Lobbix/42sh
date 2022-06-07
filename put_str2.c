/*
** EPITECH PROJECT, 2022
** Minishell1
** File description:
** creer un char**
*/

#include "my.h"

void verifi(int verification)
{
    if (WCOREDUMP(verification))
        my_putstr("segmentation fault\n");
}

char *my_strcpy(char *src)
{
    int i = 0;
    char *dest = malloc(sizeof(char)* my_strlen(src) + 1);
    while (src[i] != '\0') {
        dest[i] = src[i];
        i = i + 1;
    }
    dest[i] = '\0';
    return (dest);
}

char **put_str2(char *av, char *truc)
{
    int i = 0;
    char *nouveau = strtok(my_strcpy(av), truc);
    int j = 0;
    char **tab;
    while (nouveau != NULL) {
        i++;
        nouveau = strtok(NULL, " \n\t");
    }
    tab = malloc(sizeof(char*) * (i + 1));
    nouveau = strtok(my_strcpy(av), truc);
    for (j = 0; nouveau != NULL; j++) {
        tab[j] = nouveau;
        nouveau = strtok(NULL, truc);
    }
    tab[j] = NULL;
    return (tab);
}
