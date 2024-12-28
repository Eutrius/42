/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 13:07:19 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/29 00:31:18 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

void	print_format(const char *str, int *index, va_list args, int *count)
{
	static t_format	curr_format;

	if (parse_format(str, index, &curr_format))
		print_specifier(str[*index], args, count, &curr_format);
	reset_format(&curr_format);
}

void	reset_format(t_format *format)
{
	int	i;

	i = 0;
	while (format->flags[i] != '\0')
	{
		format->flags[i] = '\0';
		i++;
	}
	format->width = 0;
	format->precision = 0;
}

int	parse_format(const char *str, int *index, t_format *format)
{
	while (str[*index] != '\0' && ft_strchr(FORMAT_FLAGS, str[*index]))
	{
		ft_strcat(format->flags, str[*index]);
		(*index)++;
	}
	while (ft_isdigit(str[*index]))
	{
		format->width = (format->width * 10) + (str[*index] - '0');
		(*index)++;
	}
	if (str[*index] == '.')
	{
		ft_strcat(format->flags, str[*index]);
		(*index)++;
		while (ft_isdigit(str[*index]))
		{
			format->precision = (format->precision * 10) + (str[*index] - '0');
			(*index)++;
		}
	}
	if (str[*index] && ft_strchr(FORMAT_SPECIFIERS, str[*index]))
		return (1);
	return (0);
}

void	print_specifier(int c, va_list args, int *count, t_format *format)
{
	if (c == 'c')
		ft_putlchar(va_arg(args, int), count, format);
	else if (c == 's')
		ft_putlstr(va_arg(args, char *), count, format);
	else if (c == 'p')
		ft_putlmem(va_arg(args, void *), count, format);
	else if (c == 'd' || c == 'i')
		ft_putlint(va_arg(args, int), count, format);
	else if (c == 'u')
		ft_putluint(va_arg(args, unsigned int), count);
	else if (c == 'x')
		ft_putlhex(va_arg(args, unsigned int), 0, count);
	else if (c == 'X')
		ft_putlhex(va_arg(args, unsigned int), 1, count);
	else if (c == '%')
		ft_putlchar('%', count, format);
}
