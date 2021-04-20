/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:53:58 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/20 17:47:41 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

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

/*void	write_float_2(t_val *all)
{

	all->real_len = 1;
	return ;
}*/
void	write_float(t_val *all)
{
	int negative_val;
	double amount_of_decimals;
	int precis;
	int x;
	int i;
	int ii;
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
//	printf("all->d_num after minusing begin %Lf\n", all->d_num);
	all->d_num *= amount_of_decimals;
	i = 0;
//	printf("%Lf\n", all->d_num);
/*	if (all->begin_i != 0 && all->d_num != 0.5 && (precis == 1 || precis == 0))
	{
		if (precis == 0)
			all->d_num *= 10;
		if ((int)all->d_num > 5)
		{
			free(all->begin_str);
			all->begin_str = ft_itoa(all->begin_i + 1);
			all->d_num = 0;
		}
	}
	if (precis == 0 && all->begin_i == 0)
	{
		out = 0;
		ii = (int)(all->d_num * 10);
		while (all->d_num)
		{
			all->d_num *= 10;
			if ((int)all->d_num == 5)
			{
				while (all->d_num)
				{
					i = (int)all->d_num;
					all->d_num -= i;
					all->d_num *= 10;
					if ((int)all->d_num != 0)
					{
						free(all->begin_str);
						all->begin_str = ft_itoa(all->begin_i + 1);
						all->d_num = 0;
						out = 1;
						break ;
					}
				}
			}
			if (out)
				break ;
			if ((int)all->d_num > 5)
			{
				free(all->begin_str);
				all->begin_str = ft_itoa(all->begin_i + 1);
				all->d_num = 0;
				out = 1;
				break ;
			}
			if ((int)all->d_num >= 0 && (int)all->d_num < 5)
			{
				out = 1;
				break ;
			}
		}
//		printf("numero %Lf out %i\n", all->d_num, out);
		if (out != 1)
			all->d_num = ii;
	}
//	ft_putnbr((int)all->d_num);
	if (all->d_num == 0.5)
	{
		ii = all->begin_i;
		if (ii % 2 != 0)
			ii++;
		all->begin_i = ii;
		free(all->begin_str);
		all->begin_str = ft_itoa(all->begin_i);
	}*/
//	all->end_i = (signed long long int)(all->d_num + 0.5);
	all->end_i = (signed long long int)all->d_num;
//	printf("end_i %li\n", all->end_i);
//	printf("%i\n", precis);
/*	if (precis == 0)
	{
		if (all->begin_i != 0)
		{

		}
		else
		{
			
		}
	}*/
//	printf("%i\n", precis);
	if (precis > 0)
	{
		out = 0;
		x = 0;
//		printf("end_i %li before d_num %Lf d_num as int %i\n", all->end_i, all->d_num, (int)all->d_num);
		all->d_num = all->d_num - all->end_i;
		all->d_num *= 10;
//		printf("after d_num %Lf d_num as int %i\n", all->d_num, (int)all->d_num);
		if ((int)all->d_num == 5)
		{
			while (x < 5)
			{
				i = (int)all->d_num;
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
	//		printf("after IFF d_num %Lf d_num as int %i\n", all->d_num, (int)all->d_num);
		}
		else if ((int)all->d_num > 5 && !out)
		{
			all->end_str = ft_itoa(all->end_i);
		//	printf("string %s\n", all->end_str);
			if (all->end_str[0] == '9')
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
		else if ((int)all->d_num >= 0 && (int)all->d_num < 5 && !out)
		{
			out = 1;
		}
	//	printf("out %i begin %ld end %ld\n", out, all->begin_i, all->end_i);
		if (!out)
		{
			//outtiin tullaan vain kun d_num on ollut 5000000 eli tasan puolikas
			// kun end_i on vain yhden numeron pituinen
			if (all->end_i == 0)
			{
				all->end_i++;
			}
			else if (all->end_i > 0 && all->end_i < 10)
			{
				if (all->end_i % 2 != 0 || all->end_i == 4 || all->end_i == 6)
					all->end_i++;
			}
			else if (all->end_i > 9)
			{
				if (all->begin_i != 0)
				{
					if (all->end_i % 2 != 0)
						all->end_i++;
				}
			}
		}
	}
	all->end_str = ft_itoa(all->end_i);
	if (!(all->str = (char*)malloc(sizeof(char) * 10000)))
		return ;
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
//	else
//		write_float_2(all);
}

void	write_zero(t_val *all)
{
//	char *num_str;
//	char *output;
	int x;
	
	x = 0;
	if (all->width == -1 && ((all->conv == 'o' && !all->hash_flag) ||
		(all->conv == 'x' || all->conv == 'X')))
		all->real_len -= 1;
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
//			ft_putchar(all->conv);
//			ft_putstr("\n");
			if (all->conv == 'o' && all->hash_flag && all->width <= 1 && all->real_len == 1)
			{
				write(1, "0", 1);
				all->output_len++;
				all->real_len--;
			}
//			if ((all->width != -1 && !all->plus_flag && !all->minus_flag) || (all->width != -1 &&
//				all->plus_flag && all->minus_flag))
			if (all->width != -1 && all->real_len == 1)
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
	if (all->unum == 0)
	{
		number[a++] = '0';
		all->len = a;
		return (number);
	}
	while (all->unum != 0)
	{
		x = all->unum % all->base;
		number[a++] = abc[x];
		all->unum /= all->base;
	}
	number[a] = '\0';
	if (all->precision && (all->conv == 'u' || all->conv == 'x' || all->conv == 'X'))
	{
//		if ((all->conv == 'x' || all->conv == 'X') && all->num > 0)
//		{
			while ((int)ft_strlen(number) < all->precision)
			{
				number[a++] = '0';
				number[a] = '\0';
//			}
		}
	}
	if (all->hash_flag && (all->conv == 'x' || all->conv == 'X') && !all->minus_flag && all->zero_flag)
	{
		while ((int)ft_strlen(number) < all->width - 2)
		{
		//	ft_putnbr((int)ft_strlen(number));
			number[a++] = '0';
			number[a] = '\0';
		}	
	}
	if (all->hash_flag && !all->zero_num && (all->conv == 'x' || all->conv == 'X'))
	{
		number[a++] = all->conv;
		number[a++] = '0';
		all->zero_x = 1;
	}
	if (all->conv == 'o' && all->hash_flag)
		number[a++] = '0';
	number[a] = '\0';
	if (all->precision && (all->conv == 'o' || all->conv == 'u'))
	{
		x = all->precision;
		while ((int)ft_strlen(number) < x)
		{
			number[a] = '0';
			number[++a] = '\0';
		}
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
	if (all->minus_flag)
		all->zero_flag = 0;
	if (!all->zero_x && all->hash_flag && !all->zero_num && (all->conv == 'X' || all->conv == 'x'))
		all->len += 2;
	all->real_len = all->len;
	all->fill_char = ' ';
	if (all->width > all->real_len)
		all->real_len = all->width;
	if (all->precision > all->real_len)
		all->real_len = all->precision;
	//ft_putnbr(all->real_len);
	if ((all->zero_flag && all->precision && all->precision > all->width) || (all->zero_num && all->precision == all->real_len) || 
	(all->width == -1 && all->precision) || (all->zero_flag && all->width && all->precision < 0))
		all->fill_char = '0';
	if (all->zero_num && all->precision == 0)
	{
		write_zero(all);
		return ;
	}
	if (!(output = (char*)malloc(sizeof(char) * (all->real_len + 1))))
		return ;
	i = 0;
//	ft_putstr(number);
//	ft_putstr("\n");
	if (!all->minus_flag)
	{
		while (i < all->real_len - (all->len))
		{
			if (all->precision != -1 && i >= all->width - all->precision)
				all->fill_char = '0';
			output[i++] = all->fill_char;
			all->output_len++;
		}
	}
	if (!all->zero_x && all->hash_flag && !all->zero_num && (all->conv == 'X' || all->conv == 'x'))
	{
		output[i++] = '0';
		output[i++] = all->conv;
		all->output_len += 2;
		all->real_len -= 2;
	}
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
			all->fill_char = ' ';
			if (i < all->precision && all->zero_num && all->precision != -1)
				all->fill_char = '0';
			output[i++] = all->fill_char;
			all->output_len++;
		}
	}
	output[i] = '\0';
	ft_putstr(output);
/*	free((void*)number);
	free((void*)output);*/
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
	if (!(number = (char*)malloc(sizeof(char) * 1000)))
		return ;
	a = 0;
	if (all->num == 0)
		number[a++] = '0';
	while (all->num != 0)
	{
		x = all->num % 16;
		number[a++] = abc[x];
		all->num /= 16;
	}
	number[a++] = 'x';
	number[a++] = '0';
	number[a] = '\0';
	all->len = a;
	all->real_len = all->len;
	if (all->width > all->len)
		all->real_len = all->width;
	if (!(output = (char*)malloc(sizeof(char) * (all->real_len + 1))))
		return ;
	i = 0;
	if (!all->minus_flag)
	{
		while (i < all->real_len - all->len)
		{
			output[i++] = ' ';
			all->output_len++;
		}
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
/*	if (*number)
		free((void*)number);
	if (*output)
		free((void*)output);*/
	return ;
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
			if (all->num < 0)
			{
				write(1, "-", 1);
				all->output_len++;
				all->real_len--;
			}
			if (all->space_flag && all->num >= 0)
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
			if (all->num < 0)
				all->num = all->num * -1;
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
			if (!(output = (char*)malloc(sizeof(char) * 10000)))
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
					if (all->precision == -1 && all->zero_flag)
//					(all->precision == 0 && all->zero_flag && all->width > all->len))
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
				if (all->zero_flag && all->precision < 0)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				all->real_len--;
				all->output_len++;
			}
			ft_putstr(output);
			if (all->num < 0)
				num_str++;
			ft_putstr(num_str);
/*			if (*output)
				free((void*)output);
			if (*num_str)
				free((void*)num_str);
*/		}
	}
}

void	write_c(t_val *all)
{
	all->fill_char = ' ';
	if (!all->minus_flag && all->zero_flag)
		all->fill_char = '0';
	all->minimum_width = all->width - 1;
	if (all->new_flags[0] != '-')
	{
		while (all->minimum_width > 0)
		{
			write(1, &all->fill_char, 1);
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
			write(1, &all->fill_char, 1);
			all->output_len++;
			all->minimum_width--;
		}
	}
}

void	write_s(t_val *all)
{
	char *ptr;

	ptr = "(null)";
	all->str_cpy = NULL;
	all->len = 1;
	if (all->str)
		all->len = ft_strlen(all->str);
	if (all->str == NULL)
	{
		all->len = 6;
		all->str = ptr;
	}
	all->minimum_width = all->width - all->len;
	if (all->len > all->precision && all->precision >= 0 && all->str != NULL)
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

