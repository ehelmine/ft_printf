/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:03:30 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/26 21:42:47 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_float_8_second(t_val *all)
{
	if (all->big_l)
	{
		if (all->extra_zero == 1)
			all->end_i = all->end_i;
		else
		{
			all->am_of_decimals = 1;
			all->precision = all->org_precision + 1;
			while (all->precision != 0)
			{
				all->am_of_decimals *= 5;
				all->precision--;
			}
			if ((all->end_i * 10 + 5) % (int)all->am_of_decimals == 0)
			{
				if ((int)all->end_i % 2 != 0)
					all->end_i++;
			}
		}
	}
}

void		write_float_8(t_val *all, int out, int x, int i)
{
	while (x < 18)
	{
		all->d_num -= (int)all->d_num;
		all->d_num *= 10;
		if ((int)all->d_num != 0)
		{
			all->end_i++;
			out = 1;
			break ;
		}
		x++;
	}
	if (out != 1)
	{
		all->end_str = ft_itoa(all->end_i);
		i = ft_strlen(all->end_str) - 1;
		if (all->big_l == 1)
			write_float_8_second(all);
		else if ((all->begin_i == 0 && all->end_i == 0)
				|| (int)all->end_str[i] % 2 != 0)
			all->end_i++;
		if ((int)all->end_str[i] % 2 != 0)
			all->d_num = 0;
		free(all->end_str);
	}
}

void		write_float_7(t_val *all)
{
	if (all->big_l == 1 && all->org_precision == 1 && (int)all->d_num == 5)
	{
		if (all->end_i == 0 || all->end_i == 1 || all->end_i == 5
			|| all->end_i == 8 || all->end_i == 7)
		{
			all->end_i++;
			all->d_num = 0;
		}
	}
	if ((int)all->d_num == 4 && all->big_l == 1)
	{
		all->d_num -= (int)all->d_num;
		all->d_num *= 10;
		if ((int)all->d_num == 9)
		{
			while ((int)all->d_num == 9)
				all->d_num = (all->d_num - (int)all->d_num) * 10;
			if ((int)all->d_num >= 0)
				all->d_num = 5;
			else
				all->d_num = 4;
		}
	}
}

int			write_float_6(t_val *all)
{
	int i;
	int out;

	i = 0;
	out = 0;
	while (i < 7)
	{
		all->d_num -= (int)all->d_num;
		all->d_num *= 10;
		if ((int)all->d_num >= 5)
		{
			free(all->begin_str);
			all->begin_str = ft_itoa(all->begin_i + 1);
			all->end_i = 0;
			out = 1;
			break ;
		}
		else if ((int)all->d_num > 0 && (int)all->d_num < 5)
		{
			out = 1;
			break ;
		}
		i++;
	}
	return (out);
}
