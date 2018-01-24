##
## EPITECH PROJECT, 2018
## Mon Makefile
## File description:
## Makefile
##


SRC=		src/main.c\
		src/get_file.c\
		src/str.c\
		src/my_put_nbr.c\
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
