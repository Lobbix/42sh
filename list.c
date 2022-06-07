/*
** EPITECH PROJECT, 2022
** function
** File description:
** function
*/

#include "my.h"

Pipe *creat_cell(char *str)
{
    Pipe *cell = malloc(sizeof(Pipe));
    if (!cell) return NULL;
    cell->str = str;
    cell->next = NULL;
    return cell;
}

void affichage(Pipe *pipe)
{
    for (; pipe != NULL; pipe = pipe->next) {
        my_putstr(pipe->str);
        my_putstr("\n");
    }
}

Pipe *add_cell(Pipe *pipe, char *str)
{
    Pipe *cell = creat_cell(str);
    if(!cell) return pipe;
    if(pipe == NULL) {
        pipe = cell;
        return pipe;
    }
    Pipe *temp = pipe;
    for (; temp->next != NULL; temp = temp->next);
    temp->next = cell;
    return pipe;
}
