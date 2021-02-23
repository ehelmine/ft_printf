/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:07:01 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/23 21:21:38 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_flags_s(t_val *all, char *flags)
{
	int i;
	
	i = 0;
	if (flags[0] == '-')
		i = 1;
	if ((flags[1] == '\0' && i == 0) || (flags[2] == '\0' && i == 1))
		return (1);
	if (flags[0 + i] >= '1' && flags[0 + i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		flags += ft_check_int_len(all->width) + i;
		if (*flags == '.')
		{
//			flags++;
			all->precision = ft_atoi(++flags);
			if (all->precision < 0)
				return (0);
			flags += ft_check_int_len(all->precision) + 1;
			if (*flags == '\0')
				return (1);
			else
				return(0);
		}
		if (*flags == 's' && *(flags + 1) == '\0')
			return (1);
		else
			return(0);
	}
	return (0);
}

int		check_flags_percentage(t_val *all, char *flags)
{
	int i;
	
	i = 0;
	if (flags[0] == '-')
		i = 1;
	all->width = ft_strlen(flags);
	if ((flags[1] == '\0' && i == 0) || (flags[2] == '\0' && i == 1))
		return (1);
	if (flags[0 + i] >= '1' && flags[0 + i] <= '9')
	{
		all->width = ft_atoi(flags + i + 0);
		flags += ft_check_int_len(all->width) + i + 1;
		if (*flags == '\0')
			return (1);
		else
			return(0);
	}
	return (0);	
}

int		check_flags_c(t_val *all, char *flags)
{
	int i;
	
	i = 0;
	if (flags[0] == '-')
		i = 1;
	all->width = 0;
	if ((flags[1] == '\0' && i == 0) || (flags[2] == '\0' && i == 1))
		return (1);
	if (flags[0 + i] >= '1' && flags[0 + i] <= '9')
	{
		all->width = ft_atoi(flags + i + 0);
		flags += ft_check_int_len(all->width) + i + 1;
		if (*flags == '\0')
			return (1);
		else
			return(0);
	}
	return (0);	
}

