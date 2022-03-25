/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 17:36:20 by ehelmine          #+#    #+#             */
/*   Updated: 2022/03/26 01:33:04 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static void	write_s_left_ad(t_val *all)
{
	int	i;

	i = 0;
	if (all->str_cpy == NULL)
	{
		write(1, all->str, 6);
		all->output_len += 6;
	}
	else if (all->str_cpy != NULL)
	{
		i = ft_strlen(all->str_cpy);
		write(1, all->str_cpy, i);
		all->output_len += i;
		free(all->str_cpy);
	}
	while (all->minimum_width > 0)
	{
		write(1, " ", 1);
		all->output_len++;
		all->minimum_width--;
	}
}

static void	write_s_right_ad(t_val *all)
{
	int	i;

	i = 0;
	while (all->minimum_width > 0)
	{
		write(1, " ", 1);
		all->output_len++;
		all->minimum_width--;
	}
	if (all->str_cpy == NULL)
	{
		write(1, all->str, 6);
		all->output_len += 6;
	}
	else
	{
		i = ft_strlen(all->str_cpy);
		write(1, all->str_cpy, i);
		all->output_len += i;
		free(all->str_cpy);
	}
}

int	write_s(t_val *all)
{
	char	*ptr;

	ptr = "(null)";
	all->str_cpy = NULL;
	all->len = 1;
	if (all->str)
		all->len = ft_strlen(all->str);
	if (all->str == NULL)
	{
		all->len = 6;
		all->str = ptr;
	}
	all->minimum_width = all->width - all->len;
	if (all->len > all->precision && all->precision >= 0)
	{
		all->str_cpy = ft_strndup(all->str, all->precision);
		if (all->str_cpy == NULL)
			return (-1);
		all->minimum_width = all->width - ft_strlen(all->str_cpy);
	}
	if (all->new_flags[0] != '-')
		write_s_right_ad(all);
	else
		write_s_left_ad(all);
	return (1);
}
