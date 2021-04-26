# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/01/19 13:31:46 by ehelmine          #+#    #+#              #
#    Updated: 2021/04/26 23:00:47 by ehelmine         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRCS = srcs/handle_input.c srcs/check_flags_one.c srcs/check_flags_second.c \
srcs/write_c_and_ints.c srcs/help_functions.c srcs/write_signed_ints.c \
srcs/write_string.c srcs/write_p.c srcs/write_unsigned_ints.c \
srcs/write_zero.c srcs/convert_int.c srcs/write_float_1.c \
srcs/write_float_2.c srcs/write_float_3.c 

LIBFT_SRCS = ft_putchar.c ft_putstr.c ft_atoi.c ft_strlen.c ft_strcmp.c ft_putnbr.c \
	ft_strdup.c ft_strcpy.c ft_strncpy.c ft_strclr.c ft_strcat.c ft_strncmp.c \
	ft_putendl.c ft_strlcat.c ft_bzero.c ft_strncat.c ft_strchr.c ft_strrchr.c \
	ft_isalpha.c ft_isdigit.c ft_isascii.c ft_isprint.c ft_strstr.c ft_strnstr.c \
	ft_tolower.c ft_toupper.c ft_isalnum.c ft_memset.c ft_memcpy.c ft_memccpy.c \
	ft_memchr.c ft_memcmp.c ft_memmove.c ft_strequ.c ft_strnequ.c ft_memalloc.c \
	ft_memdel.c ft_strnew.c ft_strdel.c ft_strtrim.c ft_strjoin.c ft_striter.c \
	ft_striteri.c ft_strsplit.c ft_strsub.c ft_strmap.c ft_strmapi.c ft_itoa.c \
	ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c ft_putnbr_fd.c ft_lstnew.c \
	ft_lstadd.c ft_lstdelone.c ft_lstdel.c ft_lstiter.c ft_lstmap.c \
	ft_check_int_len.c ft_islower.c ft_isupper.c ft_isspace.c ft_strndup.c \
	get_next_line.c
	
OBJS = handle_input.o check_flags_one.o check_flags_second.o \
write_c_and_ints.o help_functions.o write_signed_ints.o write_string.o \
write_p.o write_unsigned_ints.o write_zero.o convert_int.o write_float_1.o \
write_float_2.o write_float_3.o

INCLUDE = includes/ft_printf.h

#INCLUDE = libft/includes/libft.h
#LIB = libft/libft.a
##LIB = $(addprefix libft/, $(LIBFT_SRCS:.c=.o))
LIB = libft/libft.a

CFLAGS = -g -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS) $(INCLUDE)
#	@gcc $(CFLAGS) -c $(SRCS)
#	@echo "Sources to objects done"
	@ar rc libftprintf.a $(OBJS) $(addprefix libft/, $(LIBFT_SRCS:.c=.o))
	@ranlib libftprintf.a
	@echo "Compiling libftprintf.a done"

$(OBJS): $(SRCS)
	make -C libft
	@gcc $(CFLAGS) -c $(SRCS)
	@echo "Sources to objects done"	
	
#
#$(NAME):
#	make -C libft
#	@gcc $(CFLAGS) -c $(SRCS)
#	@echo "Sources to objects done"
#	@gcc -Wall -Wextra -Werror -c -I libft/includes
#	@ar rc libftprintf.a $(OBJS) libft/*.o
#	@ranlib libftprintf.a
#	@echo "Compiling libftprintf.a done"
#	@gcc $(CFLAGS) -o $(NAME) $(OBJECT) $(LIB)

#clean:
#	make -C libft clean
#	make -C libftprintf clean
#	@echo "Removing .o files"
#	@rm -f $(OBJS)
	
#$(LIB):
#	$(MAKE) -C libft

clean:
	make clean -C libft
	@echo "Removing .o files"
	@rm -f $(OBJS)

fclean: clean
	make -C libft fclean
	@echo "Removing ft_printf executable and libftprintf.a"
	@rm -f $(NAME)

re: fclean all
