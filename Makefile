##
## EPITECH PROJECT, 2018
## Mon Makefile
## File description:
## Makefile
##


SRC=		src/read_and_fill.c\
		src/my_getnbr.c\
		src/bsq.c\
		src/check_cases.c\
		src/my_inform.c

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
