/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 10:10:33 by ehelmine          #+#    #+#             */
/*   Updated: 2020/07/06 12:08:48 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Prototype char * ft_strmapi(char const *s, char (*f)(unsigned int, char));
** Description Applies the function f to each character of the string passed
** as argument by giving its index as first argument to create a
** “fresh” new string (with malloc(3)) resulting from the successive
** applications of f.
** Param. #1 The string to map.
** Param. #2 The function to apply to each character of s and its index.
** Return value The “fresh” string created from the successive applications
** of f.
*/

#include "libft.h"
#include <stdlib.h>

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*temp;
	char	*nwstr;

	if (!(temp = (char *)malloc(sizeof(*temp) * (ft_strlen(s)) + 1)))
		return (NULL);
	temp = ft_strcpy(temp, s);
	i = 0;
	while (temp[i] != '\0')
	{
		temp[i] = f(i, temp[i]);
		i++;
	}
	if (!(nwstr = (char *)malloc(sizeof(*nwstr) * (i + 1))))
		return (NULL);
	ft_strcpy(nwstr, temp);
	return (nwstr);
}
