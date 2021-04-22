/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ehelmine <ehelmine@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 13:31:36 by ehelmine          #+#    #+#             */
/*   Updated: 2021/04/22 16:53:05 by ehelmine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "includes/ft_printf.h"
#include <limits.h>

int		main(void)
{

	// what happens if you pass %s with NULL argument???
	// The plus takes priority over the space!!
	
	char *str = "this is a string";
	char *ptr = "";
//	int i;
//	i = 1;
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
	p = "haha";
//	printf("13 '%%05.0' '%05.0hhd' '%05.0hhi'\n", '~', '~');

//	printf("13 '%%05.0' '%05.0hd' '%05.0hi'\n", -10, -10);
//	printf("13 '%%05.0' '%05.0hhd' '%05.0hhi'\n", -10, -10);

//	printf("13 '%%05.0' '%05.0hhd' '%05.0hhi'\n", 127, 127);

//	printf("13 '%%05.0' '%05.0hhd' '%05.0hhi'\n", 42, 42);
//	printf("13 '%%05.0' '%05.0hd' '%05.0hi'\n", 42, 42);
//	ft_printf("22 '%%#-10.10' '%#-10.10o' '%-10.10u' '%#-10.10x' '%#-10.10X'\n", 392082, 392082, 392082, 392082);
//	printf("%0+5d", -42);
//	ft_printf("11 '%%.' '%.o' '%.u' '%.x' '%.X'\n", 0, 0, 0, 0);
//	ft_printf("11 '%%.' '%.o' '%.u' '%.x' '%.X'\n", 392082, 392082, 392082, 392082);
	unsigned char s;
	s = 0;
	unsigned long ulong;
	ulong = ULONG_MAX - 1;
	float x;
	float y;
	int len;
	int i;
	int ii;
//	x = -3.14159265;
	x = 1.500000;
	y = 1.0;
	//POISTA
//	ft_check_float_len(x);
//	len = printf("%f", x);
//	ft_putnbr(len);
//	printf("real %.3f\n", 0.1255);
//	ft_printf("my %.3f\n", 0.1255);
//	printf("%.1f\n",  0.84999999999999997779553950749686919152736663818359375);
//	ft_printf("my %.1f\n",  0.84999999999999997779553950749686919152736663818359375);
//printf("print %.1Lf\n", 0.85l);
//ft_printf("my %.1Lf\n", 0.85l);
 //printf("%.20Lf\n", 0.85l);


 // ft_printf("%.2c\n", (int)NULL);
// printf("%.2c\n", (int)NULL);

//printf("%08.5d\n", -8473);
//ft_printf("%08.5d\n", -8473);

//ft_printf("simple test");
// i = printf("%.09s\n", NULL);
// ii = ft_printf("%.09s\n", NULL);
// printf("real one %i and my %i\n", i, ii);
// KORJAA NAA KAKS
//ft_printf("@moulitest: |%5.x| |%5.0x|\n", 0, 0);
//printf("@moulitest: |%5.x| |%5.0x|\n", 0, 0);
//ft_printf("%.f\n", 0.876509);
//printf("%.f\n", 0.876509);
//ft_printf("%.1f\n", -958.125000);
//printf("%.1f\n",-958.125000);
//ft_printf("%.3Lf\n", 0.1255000l);
//printf("%.3Lf\n", 0.1255000l);
//ii = printf("{%}\n");
//i = ft_printf("{%}\n");

ii = printf("hehe %iheh %c\n", 50, '%');
i = ft_printf("hehe %iheh %c\n", 50, '%');
printf("real one %i and my %i\n", i, ii);
//ft_printf("%.15f\n", 3.141593);
//printf("%.15f\n", 3.141593);
//  ft_printf("%+u\n", 4294967295);
// printf("%+u\n", 4294967295);
//	ft_printf("%%f '%f' %%lf '%lf'\n", x, x);
//	ft_printf("15 '%%1.5' '%1.5ho' '%1.5hu' '%1.5hx' '%1.5hX'\n", 42, 42, 42, 42);
//	ft_printf("24 '%%.' '%.hho' '%.hhu' '%.hhx' '%.hhX'\n", s, s, s, s);
//	ft_printf("7 '%%' '%lo' '%lu' '%lx' '%lX'\n", ulong, ulong, ulong, ulong);
//	ft_printf("13 '%%05.0' '%05.0ho' '%05.0hu' '%05.0hx' '%05.0hX'\n", 42, 42, 42, 42);
//printf("24 '%%.' '%.o' '%.u' '%.x' '%.X'\n", 4294967295, 4294967295, 4294967295, 4294967295);
	return (0);
}