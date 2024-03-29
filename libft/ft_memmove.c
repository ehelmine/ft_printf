/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/17 14:41:29 by ehelmine          #+#    #+#             */
/*   Updated: 2022/03/26 01:25:29 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** DESCRIPTION
**   The memmove() function copies len bytes from string src to string dst.
**   The two strings may overlap; the copy is always done in a non-destructive
**   manner.
**
** RETURN VALUES
**     The memmove() function returns the original value of dst.
*/

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*dsst;
	const char	*srrc;

	dsst = (char *)dst;
	srrc = (char *)src;
	if (len == 0)
		return (dst);
	if (dst > src)
	{
		while (len)
		{
			len--;
			*(dsst + len) = *(srrc + len);
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
