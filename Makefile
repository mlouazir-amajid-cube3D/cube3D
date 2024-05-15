SRC = main.c ./renderer/texture.c ./renderer/renderer.c ./renderer/ren_tools.c ./renderer/key_hook.c ./utils/tools.c ./utils/mlx.c ./parcing/parc_map.c ./parcing/parc_filename.c ./parcing/parc_content.c ./parcing/parc_content_2.c ./parcing/parc_colors.c ./parcing/parc_elements.c ./parcing/parc_texture.c ./utils/gnl/get_next_line.c
SRC_LIBFT = ./utils/libft/ft_putnbr_fd.c	./utils/libft/ft_putendl_fd.c		./utils/libft/ft_putstr_fd.c		./utils/libft/ft_putchar_fd.c		./utils/libft/ft_striteri.c		./utils/libft/ft_strmapi.c	./utils/libft/ft_itoa.c	./utils/libft/ft_strtrim.c	./utils/libft/ft_strjoin.c	./utils/libft/ft_substr.c		./utils/libft/ft_strdup.c		./utils/libft/ft_calloc.c		./utils/libft/ft_atoi.c	./utils/libft/ft_strnstr.c	./utils/libft/ft_memcmp.c		./utils/libft/ft_memchr.c		./utils/libft/ft_strncmp.c	./utils/libft/ft_strchr.c		./utils/libft/ft_strrchr.c	./utils/libft/ft_bzero.c      ./utils/libft/ft_isalnum.c    ./utils/libft/ft_isalpha.c    ./utils/libft/ft_isascii.c    ./utils/libft/ft_isdigit.c    ./utils/libft/ft_isprint.c    ./utils/libft/ft_memcpy.c     ./utils/libft/ft_memmove.c    ./utils/libft/ft_memset.c     ./utils/libft/ft_split.c      ./utils/libft/ft_strlcat.c    ./utils/libft/ft_strlcpy.c    ./utils/libft/ft_strlen.c		./utils/libft/ft_toupper.c	./utils/libft/ft_tolower.c \
			./utils/libft/ft_lstnew.c	./utils/libft/ft_lstadd_front.c	./utils/libft/ft_lstsize.c	./utils/libft/ft_lstlast.c	./utils/libft/ft_lstadd_back.c	./utils/libft/ft_lstdelone.c		./utils/libft/ft_lstclear.c		./utils/libft/ft_lstiter.c	./utils/libft/ft_lstmap.c ./utils/libft/ft_strcmp.c
OBJ = $(SRC:.c=.o)
OBJ_LIBFT = $(SRC_LIBFT:.c=.o)
FLAGS = cc -Wall -Wextra -Werror  # -fsanitize=address -g
NAME = cub3D

all: $(NAME)

$(NAME): $(OBJ) $(OBJ_LIBFT)
	$(FLAGS) -o $@ $(OBJ) $(OBJ_LIBFT) -lmlx -framework OpenGL -framework AppKit

%.o: %.c cub.h ./utils/libft/libft.h
	$(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ) $(OBJ_LIBFT)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean