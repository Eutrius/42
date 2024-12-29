/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlhex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:22:42 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/27 18:22:50 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_max(int a, int b);
static void	assign_flags(int *minus, int *zero, int *dot, t_format *format);

void	ft_putlhex(unsigned int num, int is_upper, int *count, t_format *fmt)
{
	unsigned long long	n;
	int					len;
	int					minus_flag;
	int					zero_flag;
	int					dot_flag;

	n = num;
	assign_flags(&minus_flag, &zero_flag, &dot_flag, fmt);
	len = ft_nbrlen_base(n, BASE_HEX_UPPER);
	if (ft_strchr(fmt->flags, '#') && num != 0)
	{
		if (is_upper)
			ft_putlstr("0X", count, NULL);
		else
			ft_putlstr("0x", count, NULL);
		len += 2;
		fmt->precision += 2;
	}
	if ((!minus_flag && !zero_flag) || (dot_flag && zero_flag && !minus_flag))
		ft_putlnchar(' ', fmt->width - int_max(len, fmt->precision), count);
	if (zero_flag && !minus_flag && !dot_flag)
		ft_putlnchar('0', fmt->width - len, count);
	if (dot_flag)
		ft_putlnchar('0', fmt->precision - len, count);
	if (!(n == 0 && dot_flag && fmt->precision == 0))
	{
		if (is_upper)
			ft_putlnbr_base(n, BASE_HEX_UPPER, count);
		else
			ft_putlnbr_base(n, BASE_HEX_LOWER, count);
	}
	if (minus_flag)
		ft_putlnchar(' ', fmt->width - int_max(len, fmt->precision), count);
}

static int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

static void	assign_flags(int *minus, int *zero, int *dot, t_format *format)
{
	*minus = ft_strchr(format->flags, '-');
	*dot = ft_strchr(format->flags, '.');
	*zero = ft_strchr(format->flags, '0');
}
