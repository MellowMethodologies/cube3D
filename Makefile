# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: idabligi <idabligi@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/07/09 19:51:25 by idabligi          #+#    #+#              #
#    Updated: 2023/07/11 16:31:53 by idabligi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS_LIBFT = ./Libft/ft_itoa.c ./Libft/ft_split.c ./Libft/ft_strmapi.c ./Libft/ft_putchar_fd.c ./Libft/ft_putstr_fd.c ./Libft/ft_striteri.c\
			./Libft/ft_putendl_fd.c ./Libft/ft_putnbr_fd.c ./Libft/ft_strtrim.c ./Libft/ft_strjoin.c ./Libft/ft_atoi.c ./Libft/ft_bzero.c\
			./Libft/ft_calloc.c ./Libft/ft_isalnum.c ./Libft/ft_isalpha.c ./Libft/ft_isascii.c ./Libft/ft_isdigit.c ./Libft/ft_isprint.c\
			./Libft/ft_memchr.c ./Libft/ft_memcmp.c ./Libft/ft_memcpy.c ./Libft/ft_memmove.c ./Libft/ft_memset.c ./Libft/ft_strchr.c\
			./Libft/ft_strdup.c ./Libft/ft_strlcat.c ./Libft/ft_strlcpy.c ./Libft/ft_strlen.c ./Libft/ft_strncmp.c ./Libft/ft_strnstr.c\
			./Libft/ft_strrchr.c ./Libft/ft_tolower.c ./Libft/ft_toupper.c ./Libft/ft_substr.c

SRCS_CUB = get_next_line_utils.c parsing_1.c main.c ft_textures.c cub3d_utils.c ft_get_image.c ft_draw_wall.c

SRCS = $(SRCS_LIBFT) $(SRCS_CUB)

OBJS = $(SRCS:.c=.o)
CC  = cc -g
CFLAGS =
NAME = cube

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) libmlx42.a -Iinclude -lglfw -L"/Users/idabligi/.brew/opt/glfw/lib/" $^ -o $@
	./$(NAME) ./maps/map.cub

%.o: %.c ./Libft/libft.h ./includes/cude.h
	$(CC) $(CFLAGS) -c $< -o $@

	
clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus