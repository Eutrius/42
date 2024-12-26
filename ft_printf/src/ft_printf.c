/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:21:42 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/26 14:24:16 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"
#include <stdarg.h>
#include <stdio.h>

void	print_format(int c, va_list args, int *count);
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	count = 0;
	i = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			print_format(str[i], args, &count);
		}
		else
		{
			ft_putchar_fd(str[i], 1);
			count++;
		}
		i++;
	}
	va_end(args);
	return (count);
}

void	print_format(int c, va_list args, int *count)
{
	if (c == 'c')
		ft_putlchar(va_arg(args, int), count);
	else if (c == 's')
		ft_putlstr(va_arg(args, char *), count);
	else if (c == 'p')
		ft_putlmem(va_arg(args, void *), count);
	else if (c == 'd' || c == 'i')
		ft_putlint(va_arg(args, int), count);
	else if (c == 'u')
		ft_putluint(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_putlhex(va_arg(args, unsigned int), 0, count);
	else if (c == 'X')
		ft_putlhex(va_arg(args, unsigned int), 1, count);
	else if (c == '%')
		ft_putlchar('%', count);
}
