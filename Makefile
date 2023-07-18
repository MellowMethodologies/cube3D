# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sbadr <sbadr@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 19:51:25 by idabligi          #+#    #+#              #
#    Updated: 2023/07/16 17:04:02 by sbadr            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c parsing_1.c main.c ft_draw_minimap.c\
	ft_textures.c ft_get_image.c ft_hooks.c ft_draw_wall.c\
	cub_utils.c intercection.c helper_functions.c
OBJS := $(SRCS:.c=.o)
CC  = cc -g
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = cube

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ./lib/libmlx42.a ./lib/libft.a -Iinclude -lglfw -L"/Users/sbadr/.brew/opt/glfw/lib/" $^ -o $@

%.o: %.c ./includes/cude.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus