# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:31:46 by ehelmine          #+#    #+#              #
#    Updated: 2021/04/27 00:55:09 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/handle_input.c srcs/check_flags_one.c srcs/check_flags_second.c \
srcs/write_c_and_ints.c srcs/help_functions.c srcs/write_signed_ints.c \
srcs/write_string.c srcs/write_p.c srcs/write_unsigned_ints.c \
srcs/write_zero.c srcs/convert_int.c srcs/write_float_1.c \
srcs/write_float_2.c srcs/write_float_3.c
	
OBJS = handle_input.o check_flags_one.o check_flags_second.o \
write_c_and_ints.o help_functions.o write_signed_ints.o write_string.o \
write_p.o write_unsigned_ints.o write_zero.o convert_int.o write_float_1.o \
write_float_2.o write_float_3.o

INCLUDE = libft/includes/libft.h

LIB = libft/libft.a

LIBFT_OBJS = $(wildcard libft/*.o)

CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	make -C libft
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Sources to objects done"
	@ar rc libftprintf.a $(OBJS) $(LIBFT_OBJS)
	@ranlib libftprintf.a
	@echo "Compiling libftprintf.a done"

clean:
	make clean -C libft
	@echo "Removing .o files"
	@rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	@echo "Removing ft_printf executable and libftprintf.a"
	@rm -f $(NAME)

re: fclean all
