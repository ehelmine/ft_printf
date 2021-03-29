/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:07:01 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/29 15:35:31 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

// %[flags in any order:#+-0 ]
// [min field width][.precision][conversion specifier]

int		check_flags_unsigned(t_val *all, char *flags)
{
	int i;

	all->width = -1;
	all->precision = 1;
	all->zero_flag = 0;
	all->minus_flag = 0;
	all->hash_flag = 0;
	all->big_x = 0;
	all->h = 0;
	all->hh = 0;
	all->l = 0;
	all->ll = 0;
	// spacea ja plussaa ei ole
	i = 0;

	if (flags[i + 1] == '\0')
		return (1);
	while (flags[i] == '-' || flags[i] == '#' || flags[i] == '0')
	{
		if (flags[i] == '-')
			all->minus_flag = 1;
		else if (flags[i] == '#')
			all->hash_flag = 1;
		else if (flags[i] == '0')
			all->zero_flag = 1;
		i++;
	}
	if (flags[i] >= '1' && flags[i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		i += ft_check_int_len(all->width);
	}
	if (flags[i] == '.')
	{
		if (!(ft_isdigit((int)flags[i + 1])))
		{
			if (flags[i + 1] == 'o' || flags[i + 1] == 'X' || flags[i + 1] == 'x')
			{
				all->precision = 0;
				return (1);
			}
			else
				return (0);
		}
		all->precision = ft_atoi(flags + i + 1);
		if (all->precision >= 0)
			i += ft_check_int_len(all->precision) + 1;
		else
			return (0);
	}
	if (flags[i] == 'h')
	{
		if (flags[i + 1] == 'h')
		{
			all->hh = 1;
			i += 2;
		}
		else
		{
			all->h = 1;
			i++;
		}
	}
	if (flags[i] == 'l')
	{
		if (flags[i + 1] == 'l')
		{
			all->ll = 1;
			i += 2;
		}
		else
		{
			all->l = 1;
			i++;
		}
	}
	if (flags[i] == 'X')
		all->big_x = 1;
	if (flags[i] == 'o' || flags[i] == 'X' || flags[i] == 'x')
		return (1);
	else
		return (0);
	return (1);
}

int		check_flags_p(t_val *all, char *flags)
{
	int i;

	all->width = -1;
	all->minus_flag = 0;
	i = 0;

	if (flags[i + 1] == '\0')
		return (1);
	if (flags[i] == '-')
	{
		all->minus_flag = 1;
		i++;
	}
	if (flags[i] >= '1' && flags[i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		i += ft_check_int_len(all->width);
	}
	if (flags[i] == 'p')
		return (1);
	else
		return (0);
}
int		check_flags_int(t_val *all, char *flags)
{
	int i;

	all->plus_flag = 0;
	all->minus_flag = 0;
	all->space_flag = 0;
	all->hash_flag = 0;
	all->zero_flag = 0;
	all->minimum_width = 0;
	all->precision = 1;
	all->h = 0;
	all->hh = 0;
	all->l = 0;
	all->ll = 0;
	all->width = -1;
	all->no_flags = 0;
	all->zero_num = 0;
	i = 0;
	if (flags[i + 1] == '\0')
	{
		all->no_flags = 1;
		return (1);
	}
	while (flags[i] == '+' || flags[i] == '-' || 
	flags[i] == ' ' || flags[i] == '#' || flags[i] == '0')
	{
		if (flags[i] == '+')
			all->plus_flag = 1;
		else if (flags[i] == '-')
			all->minus_flag = 1;
		else if (flags[i] == ' ')
			all->space_flag = 1;
		else if (flags[i] == '0')
			all->zero_flag = 1;
		else if (flags[i] == '#')
			all->hash_flag = 1;
		i++;
	}
	if (flags[i] >= '1' && flags[i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		i += ft_check_int_len(all->width);
	}
	if (flags[i] == '.')
	{
		if (!(ft_isdigit((int)flags[i + 1])))
		{
			if (flags[i + 1] == 'i' || flags[i + 1] == 'd' || flags[i + 1] == 'u')
			{
				all->precision = 0;
				return (1);
			}
			else
				return (0);
		}
		all->precision = ft_atoi(flags + i + 1);
		if (all->precision >= 0)
			i += ft_check_int_len(all->precision) + 1;
		else
			return (0);
	}
	if (flags[i] == 'h')
	{
		if (flags[i + 1] == 'h')
		{
			all->hh = 1;
			i += 2;
		}
		else
		{
			all->h = 1;
			i++;
		}
	}
	if (flags[i] == 'l')
	{
		if (flags[i + 1] == 'l')
		{
			all->ll = 1;
			i += 2;
		}
		else
		{
			all->l = 1;
			i++;
		}
	}
	if (flags[i] == 'i' || flags[i] == 'd' || flags[i] == 'u')
		return (1);
	else
		return (0);
}

int		check_flags_s(t_val *all, char *flags)
{
	if (*flags == '-')
		flags++;
	if (*flags >= '1' && *flags <= '9')
	{
		all->width = ft_atoi(flags);
		flags += ft_check_int_len(all->width);
	}
	if (*flags == '.')
	{
		all->precision = ft_atoi(++flags);
		if (all->precision >= 0)
			flags += ft_check_int_len(all->precision);
		else
			return (0);
	}
	if (*flags == 's' && *(flags + 1) == '\0')
		return (1);
	else
		return (0);
}

int		check_flags_percentage(t_val *all, char *flags)
{
	int i;
	
	i = 0;
	while (*flags == ' ')
		flags++;
	if (flags[0] == '-')
		i = 1;
	all->width = ft_strlen(flags);
	if ((flags[1] == '\0' && i == 0) || (flags[2] == '\0' && i == 1))
		return (1);
	if (flags[0 + i] == '.')
	{
		if (flags[0 + i + 1] >= '0' && flags[0 + i + 1] <= '9')
		{
			all->width = ft_atoi(flags + 0 + i + 1);
			flags += ft_check_int_len(all->width) + i + 1;
			all->width = 1;
			if (*flags == '%' && *(flags + 1) == '\0')
				return (1);
			else
				return (0);
		}
		return (0);
	}
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

