/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/09 10:15:31 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/22 18:49:41 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void	ft_putnbr(long long n)
{
	int x;

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
