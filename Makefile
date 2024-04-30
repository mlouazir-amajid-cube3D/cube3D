SRC = 
OBJ = $(SRC:.cpp=.o)
FLAGS = -Wall -Wextra -Werror -std=c++98
NAME = robots
CPP = c++

all: $(NAME)

%.o: %.cpp  
	$(CPP) $(FLAGS) -c $<

$(NAME): $(OBJ)
	$(CPP) $(FLAGS) -o $@ $(OBJ)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all
