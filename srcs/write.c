/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:58 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/29 15:45:29 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		real_width(int num_len, int input_width, int precision)
{
	if ((num_len == input_width && input_width == precision) || (
		num_len >= input_width && num_len >= precision))
		return (num_len);
	else if (num_len <= input_width && input_width >= precision)
		return (input_width);
	else if (precision >= input_width && num_len <= precision)
		return (precision);
	return (-1);
}

char	*convert_num(t_val *all)
{
	char *number;
	char *abc;
	int a;
	int x;
	
	abc = "0123456789abcdef";
	if (!(number = (char*)malloc(sizeof(char) * 1000)))
		return NULL;
	a = 0;
	if (all->num == 0)
	{
		number[a++] = '0';
		return (number);
	}
	while (all->num != 0)
	{
		x = all->num % 16;
		number[a++] = abc[x];
		all->num /= 16;
	}
	all->len = a;
	return (number);
}

void	write_unsigned(t_val *all)
{
	char *abc;
	int i;
	char *output;
	char *number;
	int a;

	abc = "0123456789abcdef";
	number = convert_num(all);
//	all->len = ft_check_int_len(all->num);
//	if (all->hash_flag && all->num != 0 && (all->conv == 'x' || all->conv == 'X'))
//		all->len += 2;
	all->real_len = all->len;
	all->fill_char = ' ';
	if (all->zero_flag)
		all->fill_char = '0';
	if (all->width > all->len)
		all->real_len = all->width;
	if (!(output = (char*)malloc(sizeof(char) * (all->real_len + 1))))
		return ;
	i = 0;
	if (!all->minus_flag)
	{
		while (i < all->real_len - (all->len))
		{
			output[i++] = all->fill_char;
			all->output_len++;
		}
	}
	if (all->hash_flag && all->num != 0 && (all->conv == 'x' || all->conv == 'X'))
	{
		output[i++] = '0';
		output[i++] = 'x';
		all->output_len += 2;
	}
/*	if (!(number = (char*)malloc(sizeof(char) * 1000)))
		return ;
	a = 0;
	while (all->num != 0)
	{
		x = all->num % 16;
		number[a++] = abc[x];
		all->num /= 16;
	}
	a--;*/
	a = all->len - 1;
	while (a >= 0)
	{
		output[i++] = number[a--];
		if (output[i - 1] >= 'a' && output[i - 1] <= 'z' && all->big_x)
			output[i - 1] = output[i - 1] - 32;
		all->output_len++;
	}
	if (all->minus_flag)
	{
		while (i < all->real_len)
		{
			output[i++] = ' ';
			all->output_len++;
		}
	}
	output[i] = '\0';
	ft_putstr(output);
	return ;
}

void	write_p(t_val *all)
{
	char *abc;
	int i;
	int x;
	char *output;
	char *number;
	int a;

	abc = "0123456789abcdef";
	all->len = ft_check_int_len(all->num);
	all->real_len = all->len + 2;
	if (all->width > all->len + 2)
		all->real_len = all->width;
	if (!(output = (char*)malloc(sizeof(char) * (all->real_len + 1))))
		return ;
	i = 0;
	if (!all->minus_flag)
	{
		while (i < all->real_len - (all->len + 2))
		{
			output[i++] = ' ';
			all->output_len++;
		}
	}
	output[i++] = '0';
	output[i++] = 'x';
	all->output_len += 2;
	if (all->num == 0)
	{
		output[i++] = '0';
		all->output_len++;
	}
	if (!(number = (char*)malloc(sizeof(char) * 1000)))
		return ;
	a = 0;
	while (all->num != 0)
	{
		x = all->num % 16;
		number[a++] = abc[x];
		all->num /= 16;
	}
	a--;
	while (a >= 0)
	{
		output[i++] = number[a--];
		all->output_len++;
	}
	if (all->minus_flag)
	{
		while (i < all->real_len)
		{
			output[i++] = ' ';
			all->output_len++;
		}
	}
	output[i] = '\0';
	ft_putstr(output);
	return ;
}

void	write_zero(t_val *all)
{
//	char *num_str;
//	char *output;
	int x;
	
	x = 0;
//	ft_putstr("\n");
//	ft_putnbr(all->real_len);
//	ft_putstr("\n");
	while (all->real_len > 0)
	{
		if (all->precision == 0)
		{
			if (all->plus_flag && all->minus_flag)
			{
				write(1, "+", 1);
				all->output_len++;
				all->real_len--;
			}
			if (all->space_flag)
			{
				write(1, " ", 1);
				all->output_len++;
				all->real_len--;
			}
			while (all->real_len > 1)
			{
				write(1, " ", 1);
				all->real_len--;
				all->output_len++;
			}
			if ((all->width != -1 && !all->plus_flag) || (all->width != -1 &&
				all->plus_flag && all->minus_flag))
			{
				write(1, " ", 1);
				all->output_len++;
				all->real_len--;
			}
			if (all->plus_flag && !all->minus_flag)
			{
				write(1, "+", 1);
				all->output_len++;
				all->real_len--;
			}
			return ;
		}
	}
/*		if (all->minus_flag)
		{
			if (all->space_flag)
			{
				write(1, " ", 1);
				all->output_len++;
				all->real_len--;
			}
			if (all->plus_flag)
			{
				write(1, "+", 1);
				all->output_len++;
				all->real_len--;
			}
			while (all->precision > all->len)
			{
				write(1, "0", 1);
				all->output_len++;
				all->real_len--;
				all->precision--;
			}
			ft_putnbr(all->num);		
			all->output_len += all->len;
			all->real_len -= all->len;
			while (all->real_len > 0)
			{
				write(1, " ", 1);
				all->real_len--;
				all->output_len++;
			}
		}
		else
		{
			if (!(output = (char*)malloc(sizeof(char) * 1000)))
				return ;
			if ((all->space_flag) || (all->precision > all->len && all->width > all->precision))
			{
				output[x++] = ' ';
				all->output_len++;
				all->real_len--;
			}
			if (all->plus_flag)
			{
				if (all->zero_flag)
					write(1, "+", 1);
				if (!(all->zero_flag))
					output[x++] = '+';
				all->output_len++;
				all->real_len--;
			}
			while (all->precision > all->len)
			{
				output[x++] = all->fill_char;
				all->output_len++;
				all->real_len--;
				all->precision--;
			}
			if (all->precision == all->len && all->num < 0 && all->width == -1)
			{
				output[x++] = all->fill_char;
				all->output_len++;
			}	
			output[x] = '\0';	
			num_str = ft_itoa(all->num);
			all->output_len += all->len;
			all->real_len -= all->len;
			while (all->real_len > 0)
			{
				if (all->zero_flag)
					write(1, "0", 1);
				if (!(all->zero_flag))
					write(1, " ", 1);
				all->real_len--;
				all->output_len++;
			}
			ft_putstr(output);
			if (all->num < 0)
				num_str++;
			ft_putstr(num_str);	
		}
	}*/
}

void	write_d_and_i(t_val *all)
{
	char *output;
	char *num_str;
	int x;
	
	x = 0;
	all->fill_char = '0';
	if (all->space_flag && all->plus_flag)
		all->space_flag = 0;
	if (all->plus_flag && all->num < 0)
		all->plus_flag = 0;
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
			if (all->space_flag)
			{
				write(1, " ", 1);
				all->output_len++;
				all->real_len--;
			}
			if (all->plus_flag)
			{
				write(1, "+", 1);
				all->output_len++;
				all->real_len--;
			}
			while (all->precision > all->len)
			{
				write(1, "0", 1);
				all->output_len++;
				all->real_len--;
				all->precision--;
			}
			ft_putnbr(all->num);		
			all->output_len += ft_check_int_len(all->num);
			all->real_len -= ft_check_int_len(all->num);
			while (all->real_len > 0)
			{
				write(1, " ", 1);
				all->real_len--;
				all->output_len++;
			}
		}
		else
		{
			if (!(output = (char*)malloc(sizeof(char) * 1000)))
				return ;
			if (all->space_flag && all->num >= 0)
			{
	//			write(1, " ", 1);
				output[x++] = ' ';
				all->output_len++;
				all->real_len--;
			}
			if ((all->plus_flag && all->num >= 0) || (all->num < 0))
			{
				if (all->num >= 0)
				{
					if (all->zero_flag)
						write(1, "+", 1);
					if (!(all->zero_flag))
						output[x++] = '+';
					all->output_len++;
					all->real_len--;
				}
				if (all->num < 0)
				{
					if (all->zero_flag)
						write(1, "-", 1);
					else
						output[x++] = '-';
					all->real_len--;
					all->output_len++;
				}
			}
			while (all->precision > all->len)
			{
				output[x++] = all->fill_char;
				all->output_len++;
				all->real_len--;
				all->precision--;
			}
			output[x] = '\0';	
			num_str = ft_itoa(all->num);
			all->output_len += all->len;
			all->real_len -= all->len;
			while (all->real_len > 0)
			{
				if (all->zero_flag && all->precision < all->len && all->precision >= 1)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				all->real_len--;
				all->output_len++;
			}
			ft_putstr(output);
			if (all->num < 0)
				num_str++;
			if (all->zero_num && all->precision == 0)
			{
				if (all->width == -1)
					all->output_len--;
				if (all->width > 0)
					write(1, " ", 1);
				return ;
			}
			ft_putstr(num_str);
		}
	}
}

void	write_c(t_val *all)
{
	all->minimum_width = all->width - 1;
	if (all->new_flags[0] != '-')
	{
		while (all->minimum_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->minimum_width--;
		}
		write(1, &all->c, 1);
		all->output_len++;
	}
	else
	{
		write(1, &all->c, 1);
		all->output_len++;
		while (all->minimum_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->minimum_width--;
		}
	}
}

void	write_s(t_val *all)
{
	all->str_cpy = NULL;
	all->len = 1;
	if (all->str)
		all->len = ft_strlen(all->str);
	all->minimum_width = all->width - all->len;
	if (all->len > all->precision && all->precision >= 0)
	{
		all->str_cpy = ft_strndup(all->str, all->precision);
		all->minimum_width = all->width - ft_strlen(all->str_cpy);
	}
	if (all->new_flags[0] != '-')
	{
		while (all->minimum_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->minimum_width--;
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
		while (all->minimum_width > 0)
		{
			write(1, " ", 1);
			all->output_len++;
			all->minimum_width--;
		}
	}
	free(all->str_cpy);
}

