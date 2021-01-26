/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:31:36 by ehelmine          #+#    #+#             */
/*   Updated: 2021/01/26 16:05:30 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int		main(void)
{
	char *str = "oma ohjelma";
	char *ptr = "hei";
//	printf("%s", str);
//	ft_printf("tassa on %15i ja %s myos", 25, str);
	ft_printf("haha %s ja %15s", str, ptr);
	return (0);
}