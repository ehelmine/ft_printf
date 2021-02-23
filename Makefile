# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:31:46 by ehelmine          #+#    #+#              #
#    Updated: 2021/02/21 05:39:00 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = handle_input.c check_flags.c write.c help_functions.c

OBJS = $(SRCS:.c=.o)

INCLUDE = libft/includes/libft.h

LIB = libft/libft.a

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Sources to objects done"
#	@gcc -Wall -Wextra -Werror -c -I libft/includes
	@ar rc libftprintf.a $(OBJS) libft/*.o
	@ranlib libftprintf.a
	@echo "Compiling libftprintf.a done"
#	@gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(LIB)

clean:
	make -C libft clean
#	make -C libftprintf clean
	@echo "Removing .o files"
	@rm -f $(OBJS)

fclean: clean
	make -C libft fclean
#	make -C libftprintf fclean
	@echo "Removing ft_printf executable and libftprintf.a"
	@rm -f $(NAME)

re: fclean all
