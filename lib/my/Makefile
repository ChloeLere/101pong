##
## EPITECH PROJECT, 2020
## makefile
## File description:
## makefile
##

SRC	=	add_vector.c	\
		mult_vector.c	\
		norm_vector.c	\
		my_getnbr.c	\
		my_strlen.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmymath.a

all:	$(NAME)

$(NAME):	$(OBJ)
	ar rc $(NAME) $(OBJ)
	mkdir -p ../../include 
	cp mymath.h ../../include
	cp libmymath.a ../../lib

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)

re:	fclean all
