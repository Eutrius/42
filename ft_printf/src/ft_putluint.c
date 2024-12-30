/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putluint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:22:25 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/27 18:25:22 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putluint(unsigned int num, int *count, t_format *format)
{
	unsigned long long	n;
	int					len;

	n = num;
	len = ft_nbrlen_base(n, BASE_DECIMAL);
	print_front_padding(len, count, format);
	print_middle_padding(len, count, format);
	if (!(n == 0 && ft_strchr(format->flags, '.') && format->precision == 0))
		ft_putlnbr_base(n, BASE_DECIMAL, count);
	print_back_padding(len, count, format);
}
