/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:18:10 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/29 00:05:10 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	int_max(int a, int b);
static void	assign_flags(int *minus, int *zero, int *dot, t_format *format);

void	ft_putlmem(void *mem, int *count, t_format *fmt)
{
	unsigned long long	address;
	int					len;
	int					minus_flag;
	int					zero_flag;
	int					dot_flag;

	if (!mem)
	{
		fmt->precision = 5;
		ft_putlstr("(nil)", count, fmt);
		return ;
	}
	assign_flags(&minus_flag, &zero_flag, &dot_flag, fmt);
	address = (unsigned long long)mem;
	len = ft_nbrlen_base(address, BASE_HEX_LOWER) + 2;
	if ((!minus_flag && !zero_flag) || (dot_flag && zero_flag && !minus_flag))
		ft_putlnchar(' ', fmt->width - int_max(len, fmt->precision + 2), count);
	ft_putlstr("0x", count, NULL);
	if (zero_flag && !minus_flag && !dot_flag)
		ft_putlnchar('0', fmt->width - len, count);
	if (dot_flag)
		ft_putlnchar('0', fmt->precision - len + 2, count);
	ft_putlnbr_base(address, BASE_HEX_LOWER, count);
	if (minus_flag)
		ft_putlnchar(' ', fmt->width - int_max(len, fmt->precision + 2), count);
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
