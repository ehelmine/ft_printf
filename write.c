/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:58 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/23 21:20:38 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	write_c(t_val *all)
{
	all->real_width = all->width - 1;
	if (all->new_flags[0] != '-')
	{
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->real_width--;
		}
		write(1, &all->c, 1);
		all->output_len++;
	}
	else
	{
		write(1, &all->c, 1);
		all->output_len++;
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->real_width--;
		}
	}
}

void	write_s(t_val *all)
{
	all->str_cpy = NULL;
	all->len = 1;
	if (all->str)
		all->len = ft_strlen(all->str);
	all->real_width = all->width - all->len;
	if (all->len > all->precision && all->precision > 0)
	{
		all->str_cpy = ft_strndup(all->str, all->precision);
		all->real_width = all->width - ft_strlen(all->str_cpy);
	}
	if (all->new_flags[0] != '-')
	{
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->real_width--;
		}
		if (all->str_cpy == NULL)
		{
			if (all->str != NULL)
			{
				ft_putstr(all->str);
				all->output_len += ft_strlen(all->str);
			}
			else
			{
				ft_putstr("(null)");
				all->output_len += 6;
			}
		}
		else
		{
			ft_putstr(all->str_cpy);
			all->output_len += ft_strlen(all->str_cpy);
		}
	}
	else
	{
		if (all->str_cpy == NULL)
		{
			ft_putstr(all->str);
			all->output_len += ft_strlen(all->str);
		}
		else if (all->str_cpy != NULL)
		{
			ft_putstr(all->str_cpy);
			all->output_len += ft_strlen(all->str_cpy);
		}
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->real_width--;
		}
	}
	free(all->str_cpy);
}

