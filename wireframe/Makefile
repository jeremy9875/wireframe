##
## Makefile for Makefile in /home/jeremy.el-kaim/CPool_infinadd
## 
## Made by jeremy elkaim
## Login   <jeremy.el-kaim@epitech.net>
## 
## Started on  Mon Oct 24 11:40:10 2016 jeremy elkaim
## Last update Wed Dec  7 10:51:55 2016 jeremy elkaim
##

NAME    = wireframe

SRC    = wireframe.c	\
	 my_put_pixel.c	\

OBJ    = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
		gcc $(OBJ) -o $(NAME) -lc_graph_prog

clean:
		rm -rf $(OBJ)

fclean:			clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:			all clean fclean re
