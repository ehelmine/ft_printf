/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_float_3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/26 21:04:23 by ehelmine          #+#    #+#             */
/*   Updated: 2021/05/03 03:34:21 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_float_output_3(t_val *all, int i)
{
	while (all->len < all->width)
	{
		if (all->minus_flag)
			all->str[i++] = ' ';
		else
		{
			if (all->zero_flag)
			{
				if (all->str[0] == '+' || all->str[0] == '-'
					|| all->str[0] == ' ')
				{
					ft_putchar(all->str[0]);
					all->str++;
				}
				ft_putchar('0');
			}
			else
				ft_putchar(' ');
		}
		all->len++;
	}
}

static int	write_float_output_2(t_val *all, int i)
{
	int	ii;
	int	x;

	ii = 0;
	while (all->begin_str[ii] != '\0')
		all->str[i++] = all->begin_str[ii++];
	all->str[i] = '\0';
	if (all->org_precision != 0 || all->hash_flag)
		all->str[i++] = '.';
	if (all->org_precision != 0)
	{
		x = ft_strlen(all->end_str);
		while (x < all->org_precision)
		{
			all->str[i++] = '0';
			x++;
		}
		ii = 0;
		while (all->end_str[ii] != '\0')
			all->str[i++] = all->end_str[ii++];
		all->str[i] = '\0';
	}
	return (i);
}

int	write_float_output(t_val *all)
{
	int	i;

	all->end_str = ft_itoa(all->end_i);
	if (all->end_str == NULL)
		return (-1);
	all->str = (char *)malloc(sizeof(char) * 10000);
	if (all->str == NULL)
		return (-1);
	all->tmp = all->str;
	i = 0;
	if (all->space_flag && !all->negative_val)
		all->str[i++] = ' ';
	if (all->negative_val)
		all->str[i++] = '-';
	if (!all->negative_val && all->plus_flag && !all->space_flag)
		all->str[i++] = '+';
	i = write_float_output_2(all, i);
	all->len = ft_strlen(all->str);
	if (all->len < all->width)
		write_float_output_3(all, i);
	all->output_len += all->len;
	ft_putstr(all->str);
	free(all->end_str);
	free(all->begin_str);
	free(all->tmp);
	ft_bzero((void *)all->tmp, 10000);
	return (1);
}

int	write_float_9(t_val *all)
{
	int	i;

	free(all->end_str);
	all->end_str = ft_itoa(all->end_i);
	if (all->end_str == NULL)
		return (-1);
	i = ft_strlen(all->end_str) - 1;
	while (i >= 0 && all->end_str[i] == '9')
		i--;
	if (i >= 0)
	{
		all->end_str[i] = all->end_str[i] + 1;
		i++;
		while (all->end_str[i] != '\0')
			all->end_str[i++] = '0';
		all->end_i = ft_atoi(all->end_str);
	}
	else
	{
		free(all->begin_str);
		all->begin_str = ft_itoa(all->begin_i + 1);
		if (all->begin_str == NULL)
			return (-1);
		all->end_i = 0;
		all->d_num = 0;
	}
	free(all->end_str);
	return (1);
}

void	write_float_8_second(t_val *all)
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
