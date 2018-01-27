##
## EPITECH PROJECT, 2018
## Mon Makefile
## File description:
## Makefile
##


SRC=		src/bsq2.c\
		src/my_getnbr.c\
		src/bsq.c

OBJ=		$(SRC:.c=.o)

CFLAGS=		-W -Wall -Wextra -I./include

NAME=		bsq

all:		$(NAME)

$(NAME):	$(OBJ)
		gcc -o $(NAME) $(OBJ)

clean:
		rm -f $(OBJ)

fclean:		clean
		rm -f $(NAME)

re:		fclean all
