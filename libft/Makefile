# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: caking <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/15 21:29:29 by caking            #+#    #+#              #
#    Updated: 2019/01/15 21:29:35 by caking           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

HEADER = includes

SRC = ft_bzero.c \
	  ft_strcat.c \
	  ft_strcpy.c \
	  ft_memset.c \
	  ft_strlen.c \
	  ft_strnew.c \
	  ft_strjoin.c \
	  ft_memalloc.c

OBJ = $(SRC:.c=.o)

$(NAME):
	@gcc -Wall -Wextra -Werror -c $(SRC) -I $(HEADER)
	@ar rc $(NAME) $(OBJ)
	@ranlib $(NAME)

all: $(NAME)

clean:
	@rm -f $(OBJ)

fclean: clean
	@rm -f $(NAME)

re: fclean all
