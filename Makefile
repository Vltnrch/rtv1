# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vroche <vroche@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/03/16 10:49:38 by vroche            #+#    #+#              #
#    Updated: 2015/10/09 18:03:48 by vroche           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = rtv1

LIB = -framework OpenGL -framework AppKit \
		-L./minilibx_macos -lmlx -L./libft -lft

HDR = -I./minilibx_macos -I./libft

FLAGS = -Wall -Wextra -Werror

C = ft_hit_object.c \
	ft_init_obj.c \
	ft_init_obj_work.c \
	ft_key.c \
	ft_light.c \
	ft_list.c \
	ft_manage.c \
	ft_scene_1.c \
	ft_scene_2.c \
	ft_scene_3.c \
	ft_scene_4.c \
	ft_scene_5.c \
	ft_scene_6.c \
	ft_scene_7.c \
	ft_scene_8.c \
	ft_scene_9.c \
	ft_shadow.c \
	main.c \
	rtv1.c

O = $(C:.c=.o)

all: $(NAME)

$(NAME): $(O)
	make -C ./libft
	make -C ./minilibx_macos
	gcc $(FLAGS) $(HDR) $(LIB) $(O) -o $(NAME)

%.o:%.c
	gcc $(FLAGS) $(HDR) -c $<

clean:
	make -C ./libft clean
	make -C ./minilibx_macos clean
	rm -f $(O)

fclean: clean
	make -C ./libft fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re