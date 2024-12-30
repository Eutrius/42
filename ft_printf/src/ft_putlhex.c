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

void	ft_putlhex(unsigned int num, int is_upper, int *count, t_format *format)
{
	unsigned long long	n;
	int					len;

	n = num;
	len = ft_nbrlen_base(n, BASE_HEX_UPPER);
	if (ft_strchr(format->flags, '#') && num != 0)
	{
		if (is_upper)
			ft_putlstr("0X", count, NULL);
		else
			ft_putlstr("0x", count, NULL);
		len += 2;
		format->precision += 2;
	}
	print_front_padding(len, count, format);
	print_middle_padding(len, count, format);
	if (!(n == 0 && ft_strchr(format->flags, '.') && format->precision == 0))
	{
		if (is_upper)
			ft_putlnbr_base(n, BASE_HEX_UPPER, count);
		else
			ft_putlnbr_base(n, BASE_HEX_LOWER, count);
	}
	print_back_padding(len, count, format);
}
