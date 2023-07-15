# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 19:51:25 by idabligi          #+#    #+#              #
#    Updated: 2023/07/15 17:27:41 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_CUB = get_next_line_utils.c parsing_1.c main.c ft_draw_minimap.c ft_textures.c cub3d_utils.c ft_get_image.c ft_hooks.c ft_draw_wall.c

SRCS = $(SRCS_CUB)

OBJS = $(SRCS:.c=.o)
CC  = cc -g
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
NAME = cube

all: $(NAME)

%.o:%.c ./includes/cude.h
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) ./lib/libmlx42.a ./lib/libft.a -Iinclude -lglfw -L"/Users/idabligi/.brew/opt/glfw/lib/" $^ -o $@
	./$(NAME) ./maps/map.cub
		
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus