/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:36:02 by ehelmine          #+#    #+#             */
/*   Updated: 2021/01/26 16:28:36 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

/* int		check_correct_flags()
{
	
}
 */
int		loop_parameters(const char *input, va_list args)
{
	char **flags;
	int x;
	int y;

	y = 0;
	x = 0;
	flags = (char**)malloc(sizeof(char*) * 2000);
	while (*input != '\0')
	{
		while (*input != '%')
		{
			if (*input == '\0')
				break ;
		//	write(1, (const void*)input, 1);
			input++;
		}
		input++;
		flags[y] = (char*)malloc(sizeof(char) * 20);
		while (*input != '\0')
		{
			if (*input == ' ')
				break ;
			flags[y][x++] = *input;
			input++;
		}
//		ft_putstr(va_arg(args, HERE THE TYPE));
		x = 0;
		y++;
	}
	return (0);
}

int		ft_printf(const char *begin, ...)
{
	va_list args;
	const char *input;
	
	input = ft_strdup(begin);
	va_start(args, begin);
	loop_parameters(input, args);
//	va_arg(ap, type);
//	ft_putstr(input);
	va_end(args);
	return (0);
}