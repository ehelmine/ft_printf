/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:31:36 by ehelmine          #+#    #+#             */
/*   Updated: 2021/03/26 00:09:45 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/header.h"

int		main(void)
{

	// what happens if you pass %s with NULL argument???
	// The plus takes priority over the space!!
	
	char *str = "this is a string";
	char *ptr = "";
	int i;
	i = 1;
	int my_print;
	int real_print;
	/*
// sentence in a string
	printf("test num %d only s\n", i++);
	my_print = ft_printf("%s", str);
	printf("\n");
	real_print = printf("%s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d 10s\n", i++);
	my_print = ft_printf("%10s", str);
	printf("\n");
	real_print = printf("%10s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d -6s\n", i++);
	my_print = ft_printf("%-6s", str);
	printf("\n");
	real_print = printf("%-6s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d 15.2s\n", i++);
	my_print = ft_printf("%15.2s", str);
	printf("\n");
	real_print = printf("%15.2s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d -5.2s\n", i++);
	my_print = ft_printf("%-5.2s", str);
	printf("\n");
	real_print = printf("%-5.2s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d .2s\n", i++);
	my_print = ft_printf("%.2s", str);
	printf("\n");
	real_print = printf("%.2s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d 1.5s\n", i++);
	my_print = ft_printf("%1.5s", str);
	printf("\n");
	real_print = printf("%1.5s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d 25s\n", i++);
	my_print = ft_printf("%25s", str);
	printf("\n");
	real_print = printf("%25s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d -.3s\n", i++);
	my_print = ft_printf("%-.3s", str);
	printf("\n");
	real_print = printf("%-.3s", str);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	// empty string
	printf("\ntest num %d empty str\n", i++);
	my_print = ft_printf("%s", ptr);
	printf("\n");
	real_print = printf("%s", ptr);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d null str\n", i++);
	my_print = ft_printf("%s", NULL);
	printf("\n");
	real_print = printf("%s", NULL);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d str and text after it\n", i++);
	my_print = ft_printf("%shaha", "first");
	printf("\n");
	real_print = printf("%shaha", "first");
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d str and text before to it\n", i++);
	my_print = ft_printf("haha%s", "last");
	printf("\n");
	real_print = printf("haha%s", "last");
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	// %c
	printf("\ntest num %d char\n", i++);
	my_print = ft_printf("%c", 'h');
	printf("\n");
	real_print = printf("%c", 'h');
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d char num\n", i++);
	my_print = ft_printf("%c", 42);
	printf("\n");
	real_print = printf("%c", 42);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d 5c\n", i++);
	my_print = ft_printf("%5c", 42);
	printf("\n");
	real_print = printf("%5c", 42);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");		

	printf("\ntest num %d -5c\n", i++);
	my_print = ft_printf("%-5c", 42);
	printf("\n");
	real_print = printf("%-5c", 42);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d 5c with 0\n", i++);
	my_print = ft_printf("%c", 0);
	printf("\n");
	real_print = printf("%c", 0);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");		
	
// %d and %i

	printf("\ntest num %d d 0\n", i++);
	my_print = ft_printf("%d", 0);
	printf("\n");
	real_print = printf("%d", 0);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");		

	printf("\ntest num %d d 2147483647\n", i++);
	my_print = ft_printf("%d", 2147483647);
	printf("\n");
	real_print = printf("%d", 2147483647);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d d -2147483648\n", i++);
	my_print = ft_printf("%d", -2147483648);
	printf("\n");
	real_print = printf("%d", -2147483648);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d d 2147483648 changes to minus\n", i++);
	my_print = ft_printf("%d", 2147483648);
	printf("\n");
	real_print = printf("%d", 2147483648);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	
////
	printf("\ntest num %d hd 0\n", i++);
	my_print = ft_printf("%hd", 0);
	printf("\n");
	real_print = printf("%hd", 0);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");		

	printf("\ntest num %d hd 32767\n", i++);
	my_print = ft_printf("%hd", 32767);
	printf("\n");
	real_print = printf("%hd", 32767);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d hd -32767\n", i++);
	my_print = ft_printf("%hd", -32767);
	printf("\n");
	real_print = printf("%hd", -32767);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d d -32768\n", i++);
	my_print = ft_printf("%hd", -32768);
	printf("\n");
	real_print = printf("%hd", -32768);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d d 32768 changes to minus\n", i++);
	my_print = ft_printf("%hd", 32768);
	printf("\n");
	real_print = printf("%hd", 32768);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");


	printf("\ntest num %d ld 0\n", i++);
	my_print = ft_printf("%ld", 0);
	printf("\n");
	real_print = printf("%ld", 0);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d ld 2147483647\n", i++);
	my_print = ft_printf("%ld", 2147483647);
	printf("\n");
	real_print = printf("%ld", 2147483647);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d ld -2147483648\n", i++);
	my_print = ft_printf("%ld", -2147483648);
	printf("\n");
	real_print = printf("%ld", -2147483648);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d ld 2147483648\n", i++);
	my_print = ft_printf("%ld", 2147483648);
	printf("\n");
	real_print = printf("%ld", 2147483648);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d lld 0\n", i++);
	my_print = ft_printf("%lld", 0);
	printf("\n");
	real_print = printf("%lld", 0);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d lld 9223372036854775807\n", i++);
	my_print = ft_printf("%lld", 9223372036854775807);
	printf("\n");
	real_print = printf("%lld", 9223372036854775807);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %d lld -9223372036854775807\n", i++);
	my_print = ft_printf("%lld", -9223372036854775807);
	printf("\n");
	real_print = printf("%lld", -9223372036854775807);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %d lld -9223372036854775808\n", i++);
	my_print = ft_printf("%lld", -9223372036854775808);
	printf("\n");
	real_print = printf("%lld", -9223372036854775808);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");




	printf("\ntest num %i i 0\n", i++);
	my_print = ft_printf("%i", 0);
	printf("\n");
	real_print = printf("%i", 0);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");		

	printf("\ntest num %i i 2147483647\n", i++);
	my_print = ft_printf("%i", 2147483647);
	printf("\n");
	real_print = printf("%i", 2147483647);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");	

	printf("\ntest num %i i -2147483648\n", i++);
	my_print = ft_printf("%i", -2147483648);
	printf("\n");
	real_print = printf("%i", -2147483648);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	printf("\ntest num %i i 2147483648\n", i++);
	my_print = ft_printf("%i", 2147483648);
	printf("\n");
	real_print = printf("%i", 2147483648);
	printf("\n");
	if (my_print != real_print)	
		printf("\n!!\nFAIL\n!!\n");
	printf("\n");

	// add hhd, hi, hhi, li, lli..

	// then u 
*/
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
//	printf("@moulitest: %.d %.0d", 0, 0);
	// 000000000000042
//	ft_printf("@moulitest: % 04.d % 04.d", 0, 0);	
	//printf("%-015.8d", 1000000);
	char *p;
	p = "";
	printf("%5p", 0);
//	printf("%0+5d", -42);
	return (0);
}