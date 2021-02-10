/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:58 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/10 19:42:26 by ehelmine         ###   ########.fr       */
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
			all->real_width--;
		}
		write(1, &all->c, 1);
	}
	else
	{
		write(1, &all->c, 1);
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->real_width--;
		}
	}
}

void	write_s(t_val *all)
{
	all->str_cpy = NULL;
	all->real_width = all->width - ft_strlen(all->str);
	if (ft_strlen(all->str) > all->precision)
	{
		all->str_cpy = ft_strndup(all->str, all->precision);
		all->real_width = all->width - ft_strlen(all->str_cpy);
	}
	if (all->new_flags[0] != '-')
	{
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->real_width--;
		}
		if (all->str_cpy == NULL)
			ft_putstr(all->str);
		else
			ft_putstr(all->str_cpy);
	}
	else
	{
		if (all->str_cpy == NULL)
			ft_putstr(all->str);
		else if (all->str_cpy != NULL)
			ft_putstr(all->str_cpy);
		while (all->real_width > 0)
		{
			write(1, " ", 1);
			all->real_width--;
		}
	}
	free(all->str_cpy);
}

