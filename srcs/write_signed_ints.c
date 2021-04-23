/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_signed_ints.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:20:52 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/23 13:57:15 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void	write_d_and_i_right_ad_3(t_val *all, char *num_str, char *output, int x)
{
	while (all->precision > all->len)
	{
		output[x++] = all->fill_char;
		all->output_len++;
		all->real_len--;
		all->precision--;
	}
	output[x] = '\0';
	num_str = ft_itoa(all->num);
	all->output_len += all->len;
	all->real_len -= all->len;
	while (all->real_len > 0)
	{
		if (all->zero_flag && all->precision < 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		all->real_len--;
		all->output_len++;
	}
	ft_putstr(output);
	if (all->num < 0)
		num_str++;
	ft_putstr(num_str);
}

int	write_d_and_i_right_ad_2(t_val *all, char *output, int x)
{
	if (all->num >= 0)
	{
		if (all->zero_flag)
			write(1, "+", 1);
		if (!(all->zero_flag))
			output[x++] = '+';
		all->output_len++;
		all->real_len--;
	}
	if (all->num < 0)
	{
		if (all->precision == -1 && all->zero_flag)
			write(1, "-", 1);
		else
			output[x++] = '-';
		all->real_len--;
		all->output_len++;
	}
	return (x);
}

void	write_d_and_i_right_ad(t_val *all)
{
	char	*output;
	char	*num_str;
	int		x;
	int		i;

	x = 0;
	i = 0;
	output = (char *)malloc(sizeof(char) * 10000);
	if (output == NULL)
		return ;
	if (all->space_flag && all->num >= 0)
	{
		output[x++] = ' ';
		all->output_len++;
		all->real_len--;
	}
	if ((all->plus_flag && all->num >= 0) || (all->num < 0))
		x = write_d_and_i_right_ad_2(all, output, x);
	num_str = NULL;
	write_d_and_i_right_ad_3(all, num_str, output, x);
}

static void	write_d_and_i_left_ad_2(t_val *all)
{
	while (all->precision > all->len)
	{
		write(1, "0", 1);
		all->output_len++;
		all->real_len--;
		all->precision--;
	}
	if (all->num < 0)
		all->num = all->num * -1;
	ft_putnbr(all->num);
	all->output_len += ft_check_int_len(all->num);
	all->real_len -= ft_check_int_len(all->num);
	while (all->real_len > 0)
	{
		write(1, " ", 1);
		all->real_len--;
		all->output_len++;
	}
}

void	write_d_and_i_left_ad(t_val *all)
{
	if (all->num < 0)
	{
		write(1, "-", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->space_flag && all->num >= 0)
	{
		write(1, " ", 1);
		all->output_len++;
		all->real_len--;
	}
	if (all->plus_flag)
	{
		write(1, "+", 1);
		all->output_len++;
		all->real_len--;
	}
	write_d_and_i_left_ad_2(all);
}