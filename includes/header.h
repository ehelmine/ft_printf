/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:31:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/25 23:50:44 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# define SHORT_MAX		+32767
# define SHORT_MIN		-32767
# define INT_MAX		+2147483647
# define INT_MIN		-2147483647
# define LLONG_MAX		+9223372036854775807
# define LLONG_MIN		-9223372036854775807
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "../libft/includes/libft.h"

typedef struct		s_val
{
					char *type;
					const char *output;
					int plus_flag;
					int minus_flag;
					int space_flag;
					int hash_flag;
					int zero_flag;
					int width;
					int minimum_width;
					int precision;
					char c;
					int check;
					char *str;
					int dot;
					char *str_cpy;
					char *new_flags;
					int h;
					int hh;
					int l;
					int ll;
					unsigned long long llnum;
					intmax_t num;
					int len;
					int output_len;
					char fill_char;
					int real_len;
					int i;
					int no_flags;
					int zero_num;
					void *vd_ptr;
}					t_val;


int		ft_printf(const char *begin, ...);

char	*trim_string(char *flags);

int		check_num_type(t_val *all);

int		check_flags_s(t_val *all, char *flags);

int		check_flags_percentage(t_val *all, char *flags);

int		check_flags_c(t_val *all, char *flags);

int		check_flags_int(t_val *all, char *flags);

int		check_flags_p(t_val *all, char *flags);

int		real_width(int num_len, int input_width, int precision);

void	write_c(t_val *all);

void	write_s(t_val *all);

void	write_d_and_i(t_val *all);

void	write_p(t_val *all);

#endif