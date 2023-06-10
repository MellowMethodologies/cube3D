SRCS_LIBFT = ./libft/ft_itoa.c ./libft/ft_split.c ./libft/ft_strmapi.c ./libft/ft_putchar_fd.c ./libft/ft_putstr_fd.c ./libft/ft_striteri.c\
			./libft/ft_putendl_fd.c ./libft/ft_putnbr_fd.c ./libft/ft_strtrim.c ./libft/ft_strjoin.c ./libft/ft_atoi.c ./libft/ft_bzero.c\
			./libft/ft_calloc.c ./libft/ft_isalnum.c ./libft/ft_isalpha.c ./libft/ft_isascii.c ./libft/ft_isdigit.c ./libft/ft_isprint.c\
			./libft/ft_memchr.c ./libft/ft_memcmp.c ./libft/ft_memcpy.c ./libft/ft_memmove.c ./libft/ft_memset.c ./libft/ft_strchr.c\
			./libft/ft_strdup.c ./libft/ft_strlcat.c ./libft/ft_strlcpy.c ./libft/ft_strlen.c ./libft/ft_strncmp.c ./libft/ft_strnstr.c\
			./libft/ft_strrchr.c ./libft/ft_tolower.c ./libft/ft_toupper.c ./libft/ft_substr.c

SRCS_CUB = get_next_line_utils.c parsing_1.c main.c ft_textures.c cub3d_utils.c

SRCS = $(SRCS_LIBFT) $(SRCS_CUB)

OBJS = $(SRCS:.c=.o)
CC  = cc -g
CFLAGS = -Wall -Wextra -Werror 
NAME = cube

all: $(NAME)

$(NAME): $(OBJS)
	cc $(CFLAGS) -lmlx -framework OpenGL -framework AppKit $^ -o $@

%.o: %.c libft.h cube.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all fclean clean re bonus