SRC = main.c ./utils/tools.c ./parcing/parcing_1.c
OBJ = $(SRC:.c=.o)
FLAGS = cc -Wall -Wextra -Werror
NAME = cub3D

all: $(NAME)

$(NAME): $(OBJ)
	$(FLAGS) -o $@ $(OBJ)

%.o: %.c cub.h
	$(FLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: clean