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
static void	assign_flags(int *minus, int *zero, int *dot, t_format *format);
static int	int_max(int a, int b);
static void	print_sign(long long *n, int *count, t_format *format);

void	ft_putlint(int num, int *count, t_format *fmt)
{
	long long	n;
	int			len;
	int			minus_flag;
	int			zero_flag;
	int			dot_flag;

	n = num;
	len = total_len(num, fmt);
	assign_flags(&minus_flag, &zero_flag, &dot_flag, fmt);
	if ((!minus_flag && !zero_flag) || (dot_flag && zero_flag && !minus_flag))
		ft_putlnchar(' ', fmt->width - int_max(len, fmt->precision), count);
	print_sign(&n, count, fmt);
	if (zero_flag && !minus_flag && !dot_flag)
		ft_putlnchar('0', fmt->width - len, count);
	if (dot_flag)
		ft_putlnchar('0', fmt->precision - len, count);
	if (!(n == 0 && dot_flag && fmt->precision == 0))
		ft_putlnbr_base((unsigned long long)n, BASE_DECIMAL, count);
	if (minus_flag)
		ft_putlnchar(' ', fmt->width - int_max(len, fmt->precision), count);
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

static void	assign_flags(int *minus, int *zero, int *dot, t_format *format)
{
	*minus = ft_strchr(format->flags, '-');
	*dot = ft_strchr(format->flags, '.');
	*zero = ft_strchr(format->flags, '0');
}

static int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
