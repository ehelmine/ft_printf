/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:05:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/22 14:35:35 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	check_num_type(t_val *all)
{
	if (all->h)
	{
		if (all->num < -32768)
			all->num = 0;
		else if (all->num > 32767)
			all->num = -32768;
	}
	else if (all->hh)
	{
		if (all->num < -128)
			all->num = 127;
		else if (all->num > 127)
			all->num = -128;
	}
	return (1);
}

int	get_arg_unsigned_int(t_val *all, va_list args, char x)
{
	all->conv = x;
	if (all->conv == 'u')
		all->base = 10;
	if (all->conv == 'o')
		all->base = 8;
	if (all->conv == 'x' || all->conv == 'X')
	{
		all->base = 16;
		if (all->conv == 'X')
			all->big_x = 1;
	}
	if (all->h)
		all->unum = (unsigned short)va_arg(args, unsigned int);
	else if (all->l)
		all->unum = (unsigned long)va_arg(args, unsigned long);
	else if (all->ll)
		all->unum = (unsigned long long)va_arg(args, unsigned long long);
	else if (all->hh)
		all->unum = (unsigned char)va_arg(args, unsigned int);
	else
		all->unum = va_arg(args, unsigned int);
	if (all->unum == 0)
		all->zero_num = 1;
	write_unsigned(all);
	return (1);
}

int	get_arg_signed_int(t_val *all, va_list args)
{
	if (all->h)
		all->num = (short int)va_arg(args, int);
	else if (all->l)
		all->num = (long int)va_arg(args, long);
	else if (all->ll)
	{
		all->num = (long long int)va_arg(args, long long int);
		if ((long long int)all->num == -9223372036854775807 - 1)
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
		write_d_and_i(all);
	return (1);
}

int	get_arg_s_and_p(t_val *all, va_list args, char x)
{
	if (x == 's')
	{
		all->str = va_arg(args, char *);
		write_s(all);
	}
	else if (x == 'p')
	{
		all->vd_ptr = va_arg(args, void *);
		all->num = (intmax_t)all->vd_ptr;
		if (all->num == 0)
			all->zero_num = 1;
		write_p(all);
	}
	return (1);
}

int	get_arg(t_val *all, va_list args, char x)
{
	if (x == 'c' || x == '%')
	{
		if (x == 'c')
			all->c = (char)va_arg(args, int);
		if (x == '%')
			all->c = '%';
		write_c(all);
	}
	else if (x == 'f')
	{
		all->d_num = va_arg(args, double);
		if (all->L)
			all->d_num = va_arg(args, long double);
		write_float(all);
	}
	else if (x == 'i' || x == 'd')
		get_arg_signed_int(all, args);
	else if (x == 's' || x == 'p')
		get_arg_s_and_p(all, args, x);
	else if (x == 'o' || x == 'x' || x == 'X' || x == 'u')
		get_arg_unsigned_int(all, args, x);
	return (1);
}
