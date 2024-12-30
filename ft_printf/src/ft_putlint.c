/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:21:53 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/29 00:05:01 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	total_len(int num, t_format *format);
static void	print_sign(long long *n, int *count, t_format *format);

void	ft_putlint(int num, int *count, t_format *format)
{
	long long	n;
	int			len;

	n = num;
	len = total_len(num, format);
	print_front_padding(len, count, format);
	print_sign(&n, count, format);
	print_middle_padding(len, count, format);
	if (!(n == 0 && ft_strchr(format->flags, '.') && format->precision == 0))
		ft_putlnbr_base((unsigned long long)n, BASE_DECIMAL, count);
	print_back_padding(len, count, format);
}

static void	print_sign(long long *n, int *count, t_format *format)
{
	if (*n < 0)
	{
		ft_putlchar('-', count, NULL);
		*n = -(*n);
	}
	else
	{
		if (ft_strchr(format->flags, '+'))
			ft_putlchar('+', count, NULL);
		else if (ft_strchr(format->flags, ' '))
			ft_putlchar(' ', count, NULL);
	}
}

static int	total_len(int num, t_format *format)
{
	int			len;
	long long	n;

	n = num;
	len = 0;
	if (num < 0)
	{
		len++;
		n = -n;
		format->precision += 1;
	}
	else if (ft_strchr(format->flags, '+') || ft_strchr(format->flags, ' '))
	{
		len++;
		if (num != 0)
			format->precision += 1;
	}
	len += ft_nbrlen_base((unsigned long long)n, BASE_DECIMAL);
	if (ft_strchr(format->flags, '.') && format->precision == 0 && n == 0)
		len--;
	return (len);
}
