##
## EPITECH PROJECT, 2021
## stumper
## File description:
## Makefile
##

NAME = 	42sh

all: $(NAME)

$(NAME):
	gcc -O3 ./*.c -o $(NAME)

clean:
	rm -f $(NAME)

fclean:	clean

re:	fclean all

