# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:31:46 by ehelmine          #+#    #+#              #
#    Updated: 2021/04/22 18:34:05 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/handle_input.c srcs/check_flags_one.c srcs/check_flags_second.c \
srcs/write.c srcs/help_functions.c srcs/write_signed_ints.c srcs/write_string.c \
srcs/write_p.c srcs/write_unsigned_ints.c srcs/write_zero.c srcs/convert_int.c

OBJS = handle_input.o check_flags_one.o check_flags_second.o write.o help_functions.o \
write_signed_ints.o write_string.o write_p.o write_unsigned_ints.o write_zero.o \
convert_int.o

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
