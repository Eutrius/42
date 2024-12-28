/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:21:31 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/28 18:06:16 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

static void	ft_putlstr_formatted(char *str, int *count, t_format *format);
static void	ft_putlnstr(char *str, int n, int *count);

void	ft_putlstr(char *str, int *count, t_format *format)
{
	int	i;

	if (format != NULL || !str)
	{
		ft_putlstr_formatted(str, count, format);
		return ;
	}
	i = 0;
	while (str[i] != '\0')
	{
		ft_putlchar(str[i], count, NULL);
		i++;
	}
}

static void	ft_putlstr_formatted(char *str, int *count, t_format *format)
{
	int	n;
	int	dot_flag;

	dot_flag = ft_strchr(format->flags, '.');
	if (!str)
	{
		if (!dot_flag || (dot_flag && format->precision >= 6))
			str = "(null)";
		else
		{
			str = "";
			dot_flag = 0;
		}
	}
	if (dot_flag)
		n = format->precision;
	else
		n = ft_strlen(str);
	if (ft_strchr(format->flags, '-'))
		ft_putlnchar(' ', format->width - n, count);
	ft_putlnstr(str, n, count);
	if (ft_strchr(format->flags, '-'))
		ft_putlnchar(' ', format->width - n, count);
}

static void	ft_putlnstr(char *str, int n, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && i < n)
	{
		ft_putlchar(str[i], count, NULL);
		i++;
	}
}
