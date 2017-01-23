# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: stvalett <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/11/24 15:05:35 by stvalett          #+#    #+#              #
#    Updated: 2016/12/20 09:35:34 by stvalett         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf 

CC = gcc

CFLAGS = -Wall -Wextra -Werror

CFLAGMINI = -lm -lmlx -framework OpenGL -framework Appkit

INCLUDE = fdf.h

SRCS = 	main.c\
		draw.c\
		error.c\
		key.c\
		map.c\
		mlx.c\
		parser.c\
		rot.c\
		tools.c

OBJ = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : 
	make -C Libft
	make -C minilibx_macos
	$(CC) $(CFLAGS) $(CFLAGMINI) $(SRCS) Libft/libft.a minilibx_macos/libmlx.a -I$(INCLUDE) -o $(NAME)

clean :
	make clean -C Libft
	make clean -C minilibx_macos
	rm -f $(OBJ)

fclean : clean
	make fclean -C Libft
	rm -f $(NAME)

re : fclean all

.PHONY : clean fclean re
