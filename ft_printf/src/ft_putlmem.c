/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlmem.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:18:10 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/27 18:35:56 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlmem(void *mem, int *count)
{
	unsigned long long	address;

	if (!mem)
	{
		ft_putlstr("(nil)", count);
		return ;
	}
	address = (unsigned long long)mem;
	ft_putlstr("0x", count);
	ft_putlnbr_base(address, BASE_HEX_LOWER, count);
}
