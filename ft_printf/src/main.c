/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 14:26:16 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/26 14:44:52 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <limits.h>
#include <stdarg.h>
#include <stdio.h>

int	main(void)
{
	char			*str;
	int				num;
	unsigned int	u_num;
	int				*ptr;

	// Test cases to compare ft_printf with printf
	str = "Hello, world!";
	num = -50;
	u_num = 120398;
	ptr = &num;
	// Test the character specifier
	printf("Original printf: ");
	printf("Character: %c\n", 'A');
	printf("My ft_printf: ");
	ft_printf("Character: %c\n", 'A');
	// Test the string specifier
	printf("Original printf: ");
	printf("String: %s\n", str);
	printf("My ft_printf: ");
	ft_printf("String: %s\n", str);
	// Test the pointer specifier
	printf("Original printf: ");
	printf("Pointer: %p\n", ptr);
	printf("My ft_printf: ");
	ft_printf("Pointer: %p\n", ptr);
	// Test the decimal specifier
	printf("Original printf: ");
	printf("Decimal: %d\n", num);
	printf("My ft_printf: ");
	ft_printf("Decimal: %d\n", num);
	// Test the integer specifier
	printf("Original printf: ");
	printf("Integer: %i\n", num);
	printf("My ft_printf: ");
	ft_printf("Integer: %i\n", num);
	// Test the unsigned integer specifier
	printf("Original printf: ");
	printf("Unsigned integer: %u\n", u_num);
	printf("My ft_printf: ");
	ft_printf("Unsigned integer: %u\n", u_num);
	// Test the hexadecimal specifier (lowercase)
	printf("Original printf: ");
	printf("Hexadecimal (lowercase): %x\n", u_num);
	printf("My ft_printf: ");
	ft_printf("Hexadecimal (lowercase): %x\n", u_num);
	// Test the hexadecimal specifier (uppercase)
	printf("Original printf: ");
	printf("Hexadecimal (uppercase): %X\n", u_num);
	printf("My ft_printf: ");
	ft_printf("Hexadecimal (uppercase): %X\n", u_num);
	// Test the percent specifier
	printf("Original printf: ");
	printf("Percent: %%\n");
	printf("My ft_printf: ");
	ft_printf("Percent: %%\n");
	// Edge case testing
	printf("Original printf: ");
	printf("INT_MIN: %d\n", INT_MIN);
	printf("My ft_printf: ");
	ft_printf("INT_MIN: %d\n", INT_MIN);
	printf("Original printf: ");
	printf("INT_MAX: %d\n", INT_MAX);
	printf("My ft_printf: ");
	ft_printf("INT_MAX: %d\n", INT_MAX);
	printf("Original printf: ");
	printf("ZERO: %d\n", 0);
	printf("My ft_printf: ");
	ft_printf("ZERO: %d\n", 0);
	return (0);
}
