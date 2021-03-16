##
## EPITECH PROJECT, 2020
## Makefile
## File description:
## makefile infin_add
##

NAME	=	101pong

SRC	=	main.c

all:	$(NAME)

$(NAME):
	make -C ./lib/my
	gcc -o $(NAME) $(SRC) -L./lib/my -lmymath -lm

clean:
	make -C ./lib/my
	rm -f *~
	rm -f *.c#

fclean:	clean
	make -C ./lib/my
	rm -f $(NAME)

re:	fclean all
	make -C ./lib/my
