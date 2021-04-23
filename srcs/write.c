/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:58 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/23 22:01:57 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int	real_width(int num_len, int input_width, int precision)
{
	if ((num_len == input_width && input_width == precision) || (num_len 
		>= input_width && num_len >= precision))
		return (num_len);
	else if (num_len <= input_width && input_width >= precision)
		return (input_width);
	else if (precision >= input_width && num_len <= precision)
		return (precision);
	return (-1);
}

/*void	check_long_double(t_val *all, int amount_of_decimals)
{
	while (amount_of_decimals != 1)
	{
		all->d_num *= 10;
		amount_of_decimals /= 10;
	}
	all->end_i = (intmax_t)all->d_num;
	all->d_num -= all->end_i;
	printf("begin %li end %jd d_num %Lf\n", all->begin_i, all->end_i, all->d_num);
	all->d_num *= 10;
	all->i = 0;
	return ;
}*/

void	write_float(t_val *all)
{
	int negative_val;
	double amount_of_decimals;
	int precis;
	int extra_zero;
	int i;
	int ii;
	int x;
//	char y;
	int out;

	if (all->space_flag && all->plus_flag)
		all->space_flag = 0;
	negative_val = 0;
	if (all->d_num < 0 || (all->d_num == 0 && 1.0 / all->d_num < 0))
	{
		all->d_num *= -1;
		negative_val = 1;
	}
	all->begin_i = (signed long int)all->d_num;
	amount_of_decimals = 1;
	precis = all->precision;
	while (all->precision != 0)
	{
		amount_of_decimals *= 10;
		all->precision--;
	}
	all->begin_str = ft_itoa(all->begin_i);
	all->d_num -= all->begin_i;
	extra_zero = 0;
//	printf("decis %i begin %li end %jd d_num %Lf\n", amount_of_decimals, all->begin_i, all->end_i, all->d_num);
//	if (all->L)
//		check_long_double(all, amount_of_decimals);
	while (amount_of_decimals != 1)
	{
		all->d_num *= 10;
		if ((int)all->d_num == 0)
			extra_zero++;
		amount_of_decimals /= 10;
	}
	// tassa jaettiin sita jaljella olevaa numeroa precisionin maaralla. eli paastaan siihen kohtaan
	// missa pilkun jalkee seuraava numero on VERY IMPORTANT
	i = 0;
	all->end_i = (intmax_t)all->d_num;
	all->d_num -= all->end_i;
	printf("begin %li end %jd d_num %.10Lf\n", all->begin_i, all->end_i, all->d_num);
	all->d_num *= 10;
	if (precis == 0)
	{
	//	printf("begin %li end %jd d_num %Lf\n", all->begin_i, all->end_i, all->d_num);
		if ((int)all->d_num > 5)
		{
			free(all->begin_str);
			all->begin_str = ft_itoa(all->begin_i + 1);
			all->d_num = 0;
		}
		else if ((int)all->d_num == 5)
		{
			out = 0;
			while (i < 7)
			{
				all->d_num -= (int)all->d_num;
				all->d_num *= 10;
			//	printf("%i string %s begin %li end %jd d_num %Lf\n", i, all->end_str, all->begin_i, all->end_i, all->d_num);
				if ((int)all->d_num >= 5)
				{
					free(all->begin_str);
					all->begin_str = ft_itoa(all->begin_i + 1);
					all->end_i = 0;
					out = 1;
			//		printf("INSIDE %i string %s begin %li end %jd d_num %Lf\n", i, all->end_str, all->begin_i, all->end_i, all->d_num);
					break ;
				}
				else if ((int)all->d_num > 0 && (int)all->d_num < 5)
				{
					out = 1;
					break ;
				}
				i++;
			}
			if (out != 1)
			{
				if (all->begin_i % 2 != 0)
				{
					free(all->begin_str);
					all->begin_str = ft_itoa(all->begin_i + 1);
					all->d_num = 0;
				}
			}
		}
		else if (all->end_i > 5)
		{
			free(all->begin_str);
			all->begin_str = ft_itoa(all->begin_i + 1);
			all->end_i = 0;
			all->d_num = 0;
		}
	}
	else if (precis > 0)
	{
		if ((int)all->d_num == 5)
		{
			x = 0;
			out = 0;
			while (x < 18)
			{
				all->d_num -= (int)all->d_num;
				all->d_num *= 10;
				if ((int)all->d_num != 0)
				{
					all->end_i++;
					out = 1;
					break ;
				}
				x++;
			}
//		printf("extrazero %i out %i begin %li end %jd d_num %Lf\n", extra_zero, out, all->begin_i, all->end_i, all->d_num);
			if (out != 1)
			{
				all->end_str = ft_itoa(all->end_i);
				i = ft_strlen(all->end_str) - 1;
				if (all->begin_i == 0 && all->end_i == 0)
				{
					all->end_i++;
				}
				else if ((int)all->end_str[i] % 2 != 0)
				{
//					printf("%c str %s begin %li end %jd d_num %Lf\n", all->end_str[i], all->end_str, all->begin_i, all->end_i, all->d_num);
					free(all->end_str);
					all->end_i++;
					all->d_num = 0;
				}
			}
		}
		else if ((int)all->d_num > 5)
		{
			i = 0;
	//		printf("begin %li end %jd d_num %Lf\n", all->begin_i, all->end_i, all->d_num);
			if ((int)all->end_i % 10 == 9)
			{
	//			printf("begin %li end %jd d_num %Lf\n", all->begin_i, all->end_i, all->d_num);
				all->end_str = ft_itoa(all->end_i);
				i = ft_strlen(all->end_str) - 1;
				while (i >= 0 && all->end_str[i] == '9')
					i--;
		//		printf("%i %c begin %li end %jd d_num %Lf\n", i, all->end_str[i] + '1', all->begin_i, all->end_i, all->d_num);
				if (i >= 0)
				{
		//			printf("%i %s\n", i, all->end_str);
					all->end_str[i] = all->end_str[i] + 1;
					i++;
					while (all->end_str[i] != '\0')
						all->end_str[i++] = '0';
					all->end_i = ft_atoi(all->end_str);
				}
				else
				{
					free(all->begin_str);
					all->begin_str = ft_itoa(all->begin_i + 1);
					all->end_i = 0;
					all->d_num = 0;
				}
			}
			else
			{
			//	printf("%i begin %li end %jd d_num %Lf\n", i, all->begin_i, all->end_i, all->d_num);
				all->end_i++;
				all->d_num = 0;
			}
		}
	}
	all->end_str = ft_itoa(all->end_i);
	if (!(all->str = (char*)malloc(sizeof(char) * 10000)))
		return ;
	all->tmp = all->str;
	i = 0;
	if (all->space_flag && !negative_val)
		all->str[i++] = ' ';
	if (negative_val)
		all->str[i++] = '-';
	if (!negative_val && all->plus_flag && !all->space_flag)
		all->str[i++] = '+';
	ii = 0;
	while (all->begin_str[ii] != '\0')
		all->str[i++] = all->begin_str[ii++];
	all->str[i] = '\0';
	if (precis != 0 || all->hash_flag)
		all->str[i++] = '.';
	if (precis != 0)
	{
		x = ft_strlen(all->end_str);
		while (x < precis)
		{
			all->str[i++] = '0';
			x++;
		}
		ii = 0;
		while (all->end_str[ii] != '\0')
			all->str[i++] = all->end_str[ii++];
		all->str[i] = '\0';
	}
	all->len = ft_strlen(all->str);
	if (all->len < all->width)
	{
		while (all->len < all->width)
		{
			if (all->minus_flag)
				all->str[i++] = ' ';
			else
			{
				if (all->zero_flag)
				{
					if (all->str[0] == '+' || all->str[0] == '-' || all->str[0] == ' ')
					{
						ft_putchar(all->str[0]);
						all->str++;
					}
					ft_putchar('0');
				}
				else
					ft_putchar(' ');
			}
			all->len++;
		}
	}
	all->output_len += all->len;
	ft_putstr(all->str);
	free(all->end_str);
	free(all->begin_str);
}
/*
void	write_float(t_val *all)
{
	int negative_val;
	double amount_of_decimals;
	int precis;
	int x;
	int i;
	int ii;
	int out;
	int extra_zero;
	double y;
	
	if (all->space_flag && all->plus_flag)
		all->space_flag = 0;
	negative_val = 0;
	if (all->d_num < 0 || (all->d_num == 0 && 1.0 / all->d_num < 0))
	{
		all->d_num *= -1;
		negative_val = 1;
	}
	all->begin_i = (signed long int)all->d_num;
	amount_of_decimals = 1;
	precis = all->precision;
	while (all->precision != 0)
	{
		amount_of_decimals *= 10;
		all->precision--;
	}
	all->begin_str = ft_itoa(all->begin_i);
	all->d_num -= all->begin_i;
	extra_zero = 0;
	while (amount_of_decimals != 1)
	{
		all->d_num *= 10;
		if ((int)all->d_num == 0)
			extra_zero++;
		amount_of_decimals /= 10;
	}
	i = 0;
	all->end_i = (signed long long int)all->d_num;
	if (all->L)
		check_long_double(all);
	if (precis == 0)
	{
		if (all->begin_i != 0)
		{
			all->d_num *= 10;
			if ((int)all->d_num >= 5)
			{
				free(all->begin_str);
				if ((all->begin_i + 1) % 2 == 0)
					all->begin_i++;
				all->begin_str = ft_itoa(all->begin_i);
				all->d_num = 0;
			}
		}
		else
		{
			all->d_num *= 10;
			if ((int)all->d_num == 5)
			{
				x = 0;
				while (x < 5)
				{
					i = (int)all->d_num;
					all->d_num -= i;
					all->d_num *= 10;
					if ((int)all->d_num != 0)
					{
						if ((int)all->d_num >= 5)
						{
							free(all->begin_str);
							all->begin_str = ft_itoa(all->begin_i + 1);
							all->d_num = 0;
							break ;
						}
						if ((int)all->d_num < 5)
							break ;
					}
					x++;
				}
			}
			else if ((int)all->d_num > 5)
			{
				free(all->begin_str);
				all->begin_str = ft_itoa(all->begin_i + 1);
				all->d_num = 0;
			}
		}
	}
	if (precis > 0)
	{
		out = 0;
		x = 0;
		y = 0;
		all->d_num = all->d_num - all->end_i;
		all->d_num *= 10;
		if ((int)all->d_num == 5 || (((int)(all->d_num + 0.5) == 5) && all->L))
		{
			if ((int)all->d_num == 4 && (int)(all->d_num + 0.5) == 5)
				y = 0.5;
			while (x < 5)
			{
				i = (int)(all->d_num + y);
				all->d_num -= i;
				all->d_num *= 10;
				if ((int)all->d_num != 0)
				{
					if ((int)all->d_num >= 5)
					{
						all->end_i++;
						out = 1;
						break ;
					}
					if ((int)all->d_num < 5)
					{
						out = 1;
						break ;
					}
				}
				x++;
			}
		}
		else if ((int)all->d_num > 5 && !out)
		{
			all->end_str = ft_itoa(all->end_i);
			if (all->end_str[0] == '9')
			{
				if (precis == 1)
				{
					free(all->end_str);
					free(all->begin_str);
					all->begin_str = ft_itoa(all->begin_i + 1);
					all->end_i = 0;
					out = 1;
				}
				else if (precis > 1 && all->begin_i != 0)
				{
					free(all->end_str);
					free(all->begin_str);
					all->begin_str = ft_itoa(all->begin_i + 1);
					all->end_i = 0;
					out = 1;
				}
				else
				{
					all->end_i++;
					out = 1;
				}		
			}
			else
			{

				all->end_i++;
				out = 1;
			}
		}
		else if ((int)all->d_num >= 0 && (int)all->d_num < 5 && !out)
		{
			out = 1;
		}
		if (!out)
		{
			if (all->end_i == 0)
			{
				if (!all->L || (precis == 1 && all->L))
					all->end_i++;
				else
				{
					x = extra_zero;
					all->end_str = ft_itoa(all->end_i);
					out = all->end_str[x];
					all->end_str[x] = out + 1;
					all->end_i = ft_atoi(all->end_str);
					free(all->end_str);
				}
			}
			else if (all->end_i > 0 && all->end_i < 10)
			{
				if (!all->L)
				{
					if (all->end_i % 2 != 0 || all->end_i == 4 || all->end_i == 6)
						all->end_i++;
				}
				else
				{
					if ((all->end_i >= 5 && all->end_i != 6 && all->end_i != 9) || all->end_i == 1)
						all->end_i++;
				}
				
			}
			else if (all->end_i > 9)
			{
				if (all->begin_i != 0)
				{
					all->end_str = ft_itoa(all->end_i);
					if (all->L)
					{
						if (all->end_str[(ft_strlen(all->end_str) - 1)] == '1')
							all->end_i++;
					}
					if (all->end_i % 2 != 0 && !all->L) 
						all->end_i++;
					free(all->end_str);
				}
				else
				{
					all->end_str = ft_itoa(all->end_i);
					if (!all->L)
					{
						if (all->end_str[(ft_strlen(all->end_str) - 1)] > '5')
							all->end_i++;
						else
						{
							if (all->end_i % 2 != 0)
								all->end_i++;
						}
						free(all->end_str);
					}
					else
					{
						if (all->end_str[(ft_strlen(all->end_str) - 1)] >= '5')
							all->end_i++;
						free(all->end_str);
					}
				}
			}
		}
	}
	all->end_str = ft_itoa(all->end_i);
	if (!(all->str = (char*)malloc(sizeof(char) * 10000)))
		return ;
	all->tmp = all->str;
	i = 0;
	if (all->space_flag && !negative_val)
		all->str[i++] = ' ';
	if (negative_val)
		all->str[i++] = '-';
	if (!negative_val && all->plus_flag && !all->space_flag)
		all->str[i++] = '+';
	ii = 0;
	while (all->begin_str[ii] != '\0')
		all->str[i++] = all->begin_str[ii++];
	all->str[i] = '\0';
	if (precis != 0 || all->hash_flag)
		all->str[i++] = '.';
	if (precis != 0)
	{
		x = ft_strlen(all->end_str);
		while (x < precis)
		{
			all->str[i++] = '0';
			x++;
		}
		ii = 0;
		while (all->end_str[ii] != '\0')
			all->str[i++] = all->end_str[ii++];
		all->str[i] = '\0';
	}
	all->len = ft_strlen(all->str);
	if (all->len < all->width)
	{
		while (all->len < all->width)
		{
			if (all->minus_flag)
				all->str[i++] = ' ';
			else
			{
				if (all->zero_flag)
				{
					if (all->str[0] == '+' || all->str[0] == '-' || all->str[0] == ' ')
					{
						ft_putchar(all->str[0]);
						all->str++;
					}
					ft_putchar('0');
				}
				else
					ft_putchar(' ');
			}
			all->len++;
		}
	}
	all->output_len += all->len;
	ft_putstr(all->str);
	free(all->end_str);
	free(all->begin_str);
}*/

void	write_d_and_i(t_val *all)
{
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
			write_d_and_i_left_ad(all);
		else
			write_d_and_i_right_ad(all);
	}
}

void	write_c(t_val *all)
{
	all->fill_char = ' ';
	if (!all->minus_flag && all->zero_flag)
		all->fill_char = '0';
	if (all->new_flags[0] != '-')
	{
		while (all->width - 1 > 0)
		{
			write(1, &all->fill_char, 1);
			all->output_len++;
			all->width--;
		}
		write(1, &all->c, 1);
		all->output_len++;
	}
	else
	{
		write(1, &all->c, 1);
		all->output_len++;
		while (all->width - 1 > 0)
		{
			write(1, &all->fill_char, 1);
			all->output_len++;
			all->width--;
		}
	}
}
