/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 18:31:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/23 18:53:28 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
# define HEADER_H
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>
# include <string.h>
# include <stdlib.h>
# include "libft/includes/libft.h"

typedef struct		s_val
{
					char *type;
					const char *output;
					int plus_flag;
					int minus_flag;
					int space_flag;
					int hash_flag;
					long width;
					int real_width;
					size_t precision;
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
					int num;
					size_t len;
					size_t output_len;
}					t_val;


int		ft_printf(const char *begin, ...);

char	*trim_string(char *flags);

int		check_flags_s(t_val *all, char *flags);

int		check_flags_percentage(t_val *all, char *flags);

int		check_flags_c(t_val *all, char *flags);

void	write_c(t_val *all);

void	write_s(t_val *all);

#endif