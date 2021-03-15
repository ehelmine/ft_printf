/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:15:31 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/15 17:06:09 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(long long n)
{
	int x;

/*	if (n == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		ft_putnbr(147483648);
	}*/
	if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr(n * (-1));
	}
	else
	{
		if (n >= 10)
			ft_putnbr(n / 10);
		x = (n % 10) + '0';
		write(1, &x, 1);
	}
}
