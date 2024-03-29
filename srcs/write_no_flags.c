/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_no_flags.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:22:07 by ehelmine          #+#    #+#             */
/*   Updated: 2022/04/12 23:26:45 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	write_asterisk(t_val *all, va_list args)
{
	int	i;
	int	len;

	i = 0;
	i = va_arg(args, signed int);
	i++;
	if (all->conv == 'i' || all->conv == 'd')
	{
		all->num = va_arg(args, long long int);
		len = (int)ft_check_int_len(all->num);
		all->output_len += len;
		while (--i > len)
			write(1, " ", 1);
		ft_putnbr(all->num);
	}
	else if (all->conv == 'u')
	{
		all->unum = va_arg(args, unsigned long long);
		len = (int)ft_check_int_len(all->unum);
		all->output_len += len;
		while (--i > len)
			write(1, " ", 1);
		ft_putnbr((long long)all->unum);
	}
	return (1);
}

int	write_no_flags(t_val *all)
{
	int	i;

	i = 0;
	if (all->conv == 's')
	{
		if (all->str == NULL)
		{
			write(1, "(null)", 6);
			all->output_len += 6;
		}
		else
		{
			while (all->str[i] != '\0')
				i++;
			write(1, all->str, i);
			all->output_len += i;
		}
	}
	else if (all->conv == 'i' || all->conv == 'd')
	{
		ft_putnbr(all->num);
		all->output_len += ft_check_int_len(all->num);
	}
	return (1);
}
