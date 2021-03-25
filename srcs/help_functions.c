/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:05:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/25 12:15:46 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

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
