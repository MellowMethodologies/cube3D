# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 19:51:25 by idabligi          #+#    #+#              #
#    Updated: 2023/07/25 12:01:53 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS = get_next_line_utils.c parsing_1.c main.c ft_draw_minimap.c\
	ft_textures.c ft_get_image.c ft_hooks.c ft_draw_wall.c\
	cub_utils.c intercection.c helper_functions.c ft_wall_color.c ft_strcmp_m.c
OBJS := $(SRCS:.c=.o)
CC  = cc
CFLAGS = -g  -Wall -Wextra -Werror# -fsanitize=address 
NAME = cube
HEADER = ./includes/cube.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ./lib/libmlx42.a ./lib/libft.a -Iinclude -lglfw -L"/Users/idabligi/.brew/opt/glfw/lib/" $^ -o $@

%.o: %.c  $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus