# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:31:46 by ehelmine          #+#    #+#              #
#    Updated: 2021/02/10 17:54:39 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_printf

SRCS = main.c handle_input.c write.c

OBJECT = $(SRCS:.c=.o)

INCLUDE = libft/includes/libft.h

LIB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
#	make -C libftprintf
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Sources to objects"
	@gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(LIB)
	@echo "Compiling fdf"

clean:
	make -C libft clean
#	make -C libftprintf clean
	@echo "Removing .o files"
	@rm -f $(OBJECT)

fclean: clean
	make -C libft fclean
#	make -C libftprintf fclean
	@echo "Removing ft_printf executable and libftprintf.a"
	@rm -f $(NAME)

re: fclean all
