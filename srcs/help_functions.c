/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:05:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/25 15:57:55 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

/*void	write_d_and_i_test(t_val *all)
{
	char *output;
	char *num_str;
	int x;
	
	x = 0;
	all->fill_char = '0';
	if (all->space_flag && all->plus_flag)
		all->space_flag = 0;
	all->len = ft_check_int_len(all->num);
	if (all->num < 0)
		all->len -= 1;
	all->real_len = all->len;
	if (all->precision != -1 || all->width != -1)
		all->real_len = real_width(all->len, all->width, all->precision);
	if (all->zero_num && all->precision == 0)
	{
		write_zero(all);
		return ;
	}
	while (all->real_len > 0)
	{
		if (all->minus_flag)
		{
			
		}
		else
		{
			
		}
	}
}*/


int		check_num_type(t_val *all)
{
	if (all->h)
	{
		if (all->num >= -32768 && all->num <= 32767)
			return(1);
		else if (all->num < -32768)
			all->num = 0;
		else if (all->num > 32767)
			all->num = -32768;
		return (1);
	}
	else if (all->l)
		return (1);
	else if (all->ll)
		return (1);
	else if (all->hh)
	{
		if (all->num >= -128 && all->num <= 127)	
			return (1);
		else if (all->num < -128)
			all->num = 127;
		else if (all->num > 127)
			all->num = -128;
		return (1);
	}
	else
		return (1);	
}

char	*trim_string(char *flags)
{
	int i;
	int ii;
	char *new_str;
	
	new_str = (char*)malloc(sizeof(char) * 100);
	i = 0;
	ii = 0;
	while (flags[i] != '\0')
	{
		if (flags[i] != ' ')
			new_str[ii++] = flags[i];
		i++;
	}
	new_str[ii] = '\0';
	return (new_str);
}
