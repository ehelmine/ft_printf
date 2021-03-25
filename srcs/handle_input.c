/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:36:02 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/25 15:31:40 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*
**	Conversion spesifier %u doesn't recognise space or plus flags.
*/

int		check_correct_flags2(char *flags, va_list args, t_val *all, int i)
{
	if (flags[i] == 'i' || flags[i] == 'd' || flags[i] == 'u')
	{
		if (check_flags_int(all, flags))
		{
			if (all->check)
			{
				if (flags[i] == 'u')
				{
					all->space_flag = 0;
					all->plus_flag = 0;
					if (all->h)
						all->num = (unsigned short int)va_arg(args, unsigned int);
					else if (all->l)
						all->num = (unsigned long int)va_arg(args, unsigned long);
					else if (all->ll)
						all->num = (unsigned long long int)va_arg(args, unsigned long long int);
					else if (all->hh)
						all->num = (unsigned char)va_arg(args, unsigned int);
					else
						all->num = va_arg(args, unsigned int);
					if (all->num == 0)
						all->zero_num = 1;
					write_d_and_i(all);
					return (1);
				}
				if (all->h)
					all->num = (short int)va_arg(args, int);
				else if (all->l)
					all->num = (long int)va_arg(args, long);
				else if (all->ll)
				{
					all->num = (long long int)va_arg(args, long long int);
					if ((long long int)all->num == LLONG_MIN - 1)
					{
						write(1, "-9223372036854775808", 20);
						all->output_len += 20;
						return (1);
					}
				}
				else if (all->hh)
					all->num = (signed char)va_arg(args, int);
				else
					all->num = va_arg(args, signed int);
				if (all->num == 0)
					all->zero_num = 1;
				if (check_num_type(all))
				{
					write_d_and_i(all);
					return (1);
				}
				else
					return (0);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	else if (flags[i] == 'p')
	{
		if (all->check)
		{
			write(1, "0x", 2);
			all->vd_ptr = va_arg(args, void *);
			all->num = (intmax_t)all->vd_ptr;
			write_p(all);
			return (1);
		}
		return (1);
	}
	return (0);
}
int		check_correct_flags(char *flags, va_list args, t_val *all)
{
	int i;

	i = 0;
	while (flags[i] != '\0')
		i++;
	i--;
//	all->new_flags = trim_string(flags);
	all->new_flags = flags;
	all->width = 0;
	if (flags[i] == 's')
	{
		if (check_flags_s(all, all->new_flags))
		{
			if (all->check)
			{
				all->str = va_arg(args, char*);
				write_s(all);
				return (1);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	else if (flags[i] == '%')
	{
		if (check_flags_percentage(all, all->new_flags))
		{
			if (all->check)
			{
//				all->c = (char)va_arg(args, int);
//				if (all->c == '0')
				all->c = '%';
				write_c(all);
				return (1);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	else if (flags[i] == 'c')
	{
		if (check_flags_c(all, all->new_flags))
		{
			if (all->check)
			{
				all->c = (char)va_arg(args, int);
				write_c(all);
				return (1);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	return(check_correct_flags2(all->new_flags, args, all, i));
}

int		loop_parameters(const char *input, va_list args, t_val *all)
{
	char *flags;
	int x;
	int i;

	x = 0;
	i = 0;
	all->output_len = 0;
	flags = (char*)malloc(sizeof(char) * 200);
	while (*input != '\0')
	{
		while (*input != '%' && *input != '\0')
		{
			if (all->check)
			{
				write(1, (const void*)input, 1);
				all->output_len++;
			}
			input++;
		}
		if (*input == '\0')
			break ;
		input++;
		while (*input != '\0')
		{
			flags[x++] = *input;
			if (*input == 's' || *input == 'c' ||  *input == 'p' || 
			*input == 'd' || *input == 'i' || *input == 'o' || *input == 'u' ||
			*input == 'x' || *input == 'X' || *input == 'f' || *input == '%')
				break ;
			input++;
		}
		input++;
		flags[x] = '\0';
		if (!(check_correct_flags(flags, args, all)))
			exit(0);
//		free(all->new_flags);
//		free(flags);
		x = 0;
		if (*input == '\0')
			break ;
	}
	return (1);
}

int		ft_printf(const char *begin, ...)
{
	va_list args;
	t_val all;
	int len;
	
	all.check = 0;
	va_start(args, begin);
	loop_parameters(begin, args, &all);
	all.check = 1;
	loop_parameters(begin, args, &all);
	va_end(args);
	len = all.output_len;
//	system("leaks ft_printf");
	return (len);
}