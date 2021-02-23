/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:31:36 by ehelmine          #+#    #+#             */
/*   Updated: 2021/02/23 21:13:20 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "header.h"

int		main(void)
{

	// what happens if you pass %s with NULL argument???
	// The plus takes priority over the space!!
	
	char *str = "this is a string";
	char *ptr = "hello";
	char cha;
	cha = 'k';
	char *p;
	p = "no";
	char *pp;
	pp = "where";
	int i;
//	char *nulli = NULL;
//	char ha;
//	ha = '4';
//	printf("%-15s", str);
//	ft_printf("%15%");
//	ft_printf("%c", cha);
//	ft_printf("%3s%-6s", p, pp);
//	ft_printf("haha %  -    sK ja |%9  c", str, cha);
//	ft_printf("hehe %i", 25);
//	ft_printf("%-12c, %c", cha, ha);
//	ft_putstr("\n");
//	printf("%.3s", str);
//	printf("|%p|", ptr);
//	printf("%d", 2147483647);
//	ft_printf("%d", 2147483647);
	i = ft_printf("%%");
	ft_putnbr(i);
	return (0);
}