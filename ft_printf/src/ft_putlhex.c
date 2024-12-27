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

void	ft_putlhex(unsigned int num, int is_upper, int *count)
{
	unsigned long long	n;

	n = num;
	if (is_upper)
		ft_putlnbr_base(n, BASE_HEX_UPPER, count);
	else
		ft_putlnbr_base(n, BASE_HEX_LOWER, count);
}
