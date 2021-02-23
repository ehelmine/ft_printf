/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 23:11:35 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/11 00:10:29 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_itoa(long n)
{
	int		minus;
	int		len;
	char	*number;

	minus = 0;
	if (n < 0)
	{
		minus = 1;
		n = n * -1;
	}
	len = ft_check_int_len(n) + minus;
	if (!(number = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	number[len--] = '\0';
	while (n > 9)
	{
		number[len--] = (n % 10) + 48;
		n = n / 10;
	}
	if (len >= 0)
		number[len--] = n + 48;
	if (minus)
		number[len] = '-';
	return (number);
}
