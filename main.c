/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:31:36 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/15 17:21:12 by ehelmine         ###   ########.fr       */
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
//	i = ft_printf("%%");
//	ft_putnbr(i);
//	ft_printf("%.0%");
//	ft_printf("%d", -4242);
//printf("%010s is a string", "this");
//	ft_printf("@moulitest: %.d %.0d", 42, 43);
	printf("@moulitest: %.d %.0d", 0, 0);
	// 000000000000042
	return (0);
}