/*
** EPITECH PROJECT, 2021
** my_putchar.c
** File description:
** my_putchar
*/

#include <unistd.h>
#include "my.h"

void my_putchar(char c)
{
    write(1, &c, 1);
}

int my_strlen(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        i += 1;
    }
    return (i);
}

void my_putstr(char *str)
{
    int i = 0;

    while (str[i] != '\0') {
        my_putchar(str[i]);
        i += 1;
    }
}

void my_putnbr(int nbr)
{
    if (nbr < 0) {
        my_putchar('-');
        nbr = -nbr;
    }
    if (nbr > 9) {
        my_putnbr(nbr / 10);
    }
    my_putchar((nbr % 10) + 48);
}

int my_getnbr(char *str)
{
    int i = 0, res = 0, neg = 0;
    if (str[0] == '-') {
        i += 1;
        neg = 1;
	}
	while (str[i] != '\0') {
		res = res * 10;
		res += str[i] - 48;
		i += 1;
	}
	if (neg == 1) res = res * (-1);
    return (res);
}
