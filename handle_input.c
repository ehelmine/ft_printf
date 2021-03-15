/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:36:02 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/15 17:18:39 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

// %[flags in any order:#+-0 ]
// [min field width][.precision][conversion specifier]

int		check_flags_int(t_val *all, char *flags)
{
	int i;

	all->plus_flag = 0;
	all->minus_flag = 0;
	all->space_flag = 0;
	all->hash_flag = 0;
	all->zero_flag = 0;
	all->minimum_width = 0;
	all->precision = -1;
	all->h = 0;
	all->hh = 0;
	all->l = 0;
	all->ll = 0;
	all->width = -1;
	all->no_flags = 0;
	i = 0;
	if (flags[i + 1] == '\0')
	{
		all->no_flags = 1;
		return (1);
	}
	while (flags[i] == '+' || flags[i] == '-' || 
	flags[i] == ' ' || flags[i] == '#' || flags[i] == '0')
	{
		if (flags[i] == '+')
			all->plus_flag = 1;
		else if (flags[i] == '-')
			all->minus_flag = 1;
		else if (flags[i] == ' ')
			all->space_flag = 1;
		else if (flags[i] == '0')
			all->zero_flag = 1;
		else if (flags[i] == '#')
			all->hash_flag = 1;
		i++;
	}
	if (flags[i] >= '1' && flags[i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		i += ft_check_int_len(all->width);
	}
	if (flags[i] == '.')
	{
		if (!(ft_isdigit((int)flags[i + 1])))
		{
			if (flags[i + 1] == 'i' || flags[i + 1] == 'd' || flags[i + 1] == 'u')
				return (1);
			else
				return (0);
		}
		all->precision = ft_atoi(flags + i + 1);
		if (all->precision >= 0)
			i += ft_check_int_len(all->precision) + 1;
		else
			return (0);
	}
	if (flags[i] == 'h')
	{
		if (flags[i + 1] == 'h')
		{
			all->hh = 1;
			i += 2;
		}
		else
		{
			all->h = 1;
			i++;
		}
	}
	if (flags[i] == 'l')
	{
		if (flags[i + 1] == 'l')
		{
			all->ll = 1;
			i += 2;
		}
		else
		{
			all->l = 1;
			i++;
		}
	}
	if (flags[i] == 'i' || flags[i] == 'd' || flags[i] == 'u')
		return (1);
	else
		return (0);
}

int		check_num_type(t_val *all)
{
	if (all->h)
	{
		if (all->num >= -32768 && all->num <= 32767)
			return(1);
		else if (all->num < -32768)
			all->num = 0;
		else if (all->num > 32767)
			all->num = -32768;
		return (1);
	}
	else if (all->l)
		return (1);
	else if (all->ll)
	{
		return (1);
	}
	else if (all->hh)
	{
		if (all->num >= -128 && all->num <= 127)	
			return (1);
		else if (all->num < -128)
			all->num = 127;
		else if (all->num > 127)
			all->num = -128;
		return (1);
	}
	else
		return (1);
	
}

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
	else if (flags[i] == 'p')
	{
		ft_putstr(va_arg(args, void*));
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
	all.precision = -1;
	va_start(args, begin);
	loop_parameters(begin, args, &all);
	all.check = 1;
	all.precision = -1;
	loop_parameters(begin, args, &all);
	va_end(args);
	len = all.output_len;
//	system("leaks ft_printf");
	return (len);
}