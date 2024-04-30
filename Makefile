SRC = main.c ./utils/tools.c ./parcing/parcing_1.c
OBJ = $(SRC:.c=.o)
FLAGS = cc -Wall -Wextra -Werror 
NAME = cub3D
LIBFT = ./libft/libft.a

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	$(FLAGS) -o $@ $(OBJ) -Llibft -lft 

%.o: %.c cub.h
	$(FLAGS) -c $< -o $@

$(LIBFT):
	cd libft && make -j6

clean:
	cd libft && make fclean
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean