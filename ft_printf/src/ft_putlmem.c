/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:18:10 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/29 15:31:58 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlmem(void *mem, int *count, t_format *format)
{
	unsigned long long	address;
	int					len;

	if (!mem)
	{
		format->precision = 5;
		ft_putlstr("(nil)", count, format);
		return ;
	}
	address = (unsigned long long)mem;
	len = ft_nbrlen_base(address, BASE_HEX_LOWER) + 2;
	format->precision += 2;
	print_front_padding(len, count, format);
	ft_putlstr("0x", count, NULL);
	print_middle_padding(len, count, format);
	ft_putlnbr_base(address, BASE_HEX_LOWER, count);
	print_back_padding(len, count, format);
}
