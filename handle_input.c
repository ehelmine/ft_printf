/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/21 17:36:02 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/10 20:29:34 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		check_flags_s(t_val *all, char *flags)
{
	int i;
	
	i = 0;
	all->dot = 0;
	if (flags[0] == '-')
		i = 1;
	all->width = 0;
	if ((flags[1] == '\0' && i == 0) || (flags[2] == '\0' && i == 1))
		return (1);
	if (flags[0 + i] >= '1' && flags[0 + i] <= '9')
	{
		all->width = ft_atoi(flags + i);
		flags += ft_check_int(all->width) + i;
		if (*flags == '.')
		{
			all->dot = 1;
			flags++;
			all->precision = ft_atoi(flags);
			if (all->precision < 0)
				return (0);
			flags += ft_check_int(all->precision) + 1;
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
	all->width = 0;
	if ((flags[1] == '\0' && i == 0) || (flags[2] == '\0' && i == 1))
		return (1);
	if (flags[0 + i] >= '1' && flags[0 + i] <= '9')
	{
		all->width = ft_atoi(flags + i + 0);
		flags += ft_check_int(all->width) + i + 1;
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
		flags += ft_check_int(all->width) + i + 1;
		if (*flags == '\0')
			return (1);
		else
			return(0);
	}
	return (0);	
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

int		check_correct_flags2(char *flags, va_list args, t_val *all, int i)
{
	if (flags[i] == 'i' || flags[i] == 'd')
	{
	
	}
}
int		check_correct_flags(char *flags, va_list args, t_val *all)
{
	int i;

	i = 0;
	while (flags[i] != '\0')
		i++;
	i--;
	all->new_flags = trim_string(flags);
	if (flags[i] == 's')
	{
		if (check_flags_s(all, all->new_flags))
		{
			if (all->check)
			{
				all->str = (va_arg(args, char*));
				write_s(all);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	else if (flags[i] == 'p')
	{
		ft_putstr(va_arg(args, void*));
	}
	else if (flags[i] == '%')
	{
		if (check_flags_percentage(all, all->new_flags))
		{
			if (all->check)
			{
				all->c = '%';
				write_c(all);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	else if (flags[i] == 'c')
	{
		if (check_flags_c(all, all->new_flags))
		{
			if (all->check)
			{
				all->c = (va_arg(args, int));
				write_c(all);
			}
			else
				return (1);
		}
		else
			return (0);
	}
	else
		check_correct_flags2(flags, args, all, i);
	return (0);
}

int		loop_parameters(const char *input, va_list args, t_val *all)
{
	char *flags;
	int x;
	int i;

	x = 0;
	i = 0;
	while (*input != '\0')
	{
		while (*input != '%')
		{
			if (*input == '\0')
				break ;
			if (all->check)
				write(1, (const void*)input, 1);
			input++;
		}
		input++;
		flags = (char*)malloc(sizeof(char) * 200);
		while (*input != '\0')
		{
			if (*input == '\0')
				break ;
			flags[x++] = *input;
			if (*input == 's' || *input == 'c' ||  *input == 'p' || 
			*input == 'd' || *input == 'i' || *input == 'o' || *input == 'u' ||
			*input == 'x' || *input == 'X' || *input == 'f' || *input == '%')
				break ;
			input++;
		}
		input++;
		flags[x] = '\0';
		check_correct_flags(flags, args, all);
		free(all->new_flags);
		free(flags);
		x = 0;
		if (*input == '\0')
			break ;
	}
	return (0);
}

int		ft_printf(const char *begin, ...)
{
	va_list args;
	t_val all;
	
	all.check = 0;
	va_start(args, begin);
	loop_parameters(begin, args, &all);
	all.check = 1;
	loop_parameters(begin, args, &all);
	va_end(args);
//	system("leaks ft_printf");
	return (all.width);
}