# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mlouazir <mlouazir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/07 15:41:36 by mlouazir          #+#    #+#              #
#    Updated: 2023/11/12 16:56:03 by mlouazir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_isdigit.c ft_memset.c  ft_isprint.c ft_putendl_fd.c ft_itoa.c ft_strmapi.c \
		ft_bzero.c ft_putchar_fd.c  ft_atoi.c ft_strncmp.c ft_memchr.c ft_striteri.c \
		ft_tolower.c  ft_strlen.c ft_putstr_fd.c ft_strlcat.c ft_calloc.c ft_strtrim.c \
		ft_toupper.c ft_isalnum.c ft_strrchr.c  ft_strlcpy.c ft_memcmp.c ft_split.c \
		ft_isalpha.c ft_memcpy.c ft_strchr.c  ft_putnbr_fd.c ft_strnstr.c ft_strjoin.c \
		ft_isascii.c ft_memmove.c ft_isascii.c ft_strchr.c ft_strdup.c ft_substr.c \

SRCB = ft_lstiter_bonus.c ft_lstsize_bonus.c\
			ft_lstclear_bonus.c ft_lstdelone_bonus.c\
			ft_lstadd_back_bonus.c ft_lstlast_bonus.c\
			ft_lstnew_bonus.c ft_lstadd_front_bonus.c\
			ft_lstmap_bonus.c\

OBJECT = $(SRC:.c=.o)
OBJECTB = $(SRCB:.c=.o)
CC = cc
FLAGS = -Wall -Wextra -Werror 
NAME = libft.a
LIB = libft.h
AR = ar rc

$(NAME): $(OBJECT)
	$(AR) $(NAME) $(OBJECT)

%.o : %.c $(LIB)
	$(CC) $(FLAGS) -c $< -o $@

all: $(NAME)

bonus: $(OBJECTB)
	$(AR) $(NAME) $(OBJECTB)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all bonus
