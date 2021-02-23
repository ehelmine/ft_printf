/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   help_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/16 17:05:32 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/16 17:05:52 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

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
