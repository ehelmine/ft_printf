/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_unsigned_ints.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:18:17 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/22 18:41:14 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_unsigned_4(t_val *all, char *output, int i)
{
	if (all->minus_flag)
	{
		while (i < all->real_len)
		{
			all->fill_char = ' ';
			if (i < all->precision && all->zero_num && all->precision != -1)
				all->fill_char = '0';
			output[i++] = all->fill_char;
			all->output_len++;
		}
	}
	output[i] = '\0';
	ft_putstr(output);
	free(output);
}

static void	write_unsigned_3(t_val *all, char *output, char *number, int i)
{
	if (!all->zero_x && all->hash_flag && !all->zero_num && (all->conv == 'X'
			|| all->conv == 'x'))
	{
		output[i++] = '0';
		output[i++] = all->conv;
		all->output_len += 2;
		all->real_len -= 2;
	}
	all->len--;
	while (all->len >= 0)
	{
		output[i++] = number[all->len--];
		if (output[i - 1] >= 'a' && output[i - 1] <= 'z' && all->big_x)
			output[i - 1] = output[i - 1] - 32;
		all->output_len++;
	}
	free(number);
	write_unsigned_4(all, output, i);
}

static void	write_unsigned_2(t_val *all, char *number)
{
	int		i;
	char	*output;

	if (all->zero_num && all->precision == 0)
	{
		write_zero(all);
		return ;
	}
	output = (char *)malloc(sizeof(char) * (all->real_len + 1));
	if (output == NULL)
		return ;
	i = 0;
	if (!all->minus_flag)
	{
		while (i < all->real_len - (all->len))
		{
			if (all->precision != -1 && i >= all->width - all->precision)
				all->fill_char = '0';
			output[i++] = all->fill_char;
			all->output_len++;
		}
	}
	write_unsigned_3(all, output, number, i);
}

void	write_unsigned(t_val *all)
{
	char	*abc;
	char	*number;

	abc = "0123456789abcdef";
	number = convert_num(all);
	if (all->minus_flag)
		all->zero_flag = 0;
	if (!all->zero_x && all->hash_flag && !all->zero_num && (all->conv == 'X'
			|| all->conv == 'x'))
		all->len += 2;
	all->real_len = all->len;
	all->fill_char = ' ';
	if (all->width > all->real_len)
		all->real_len = all->width;
	if (all->precision > all->real_len)
		all->real_len = all->precision;
	if ((all->zero_flag && all->precision && all->precision > all->width)
		|| (all->zero_num && all->precision == all->real_len) || (all->width
			== -1 && all->precision) || (all->zero_flag && all->width
			&& all->precision < 0))
		all->fill_char = '0';
	write_unsigned_2(all, number);
}
