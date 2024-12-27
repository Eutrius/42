/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:21:53 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/27 18:22:09 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlint(int num, int *count)
{
	long long	n;

	n = num;
	if (num < 0)
	{
		ft_putlchar('-', count);
		n = -n;
	}
	ft_putlnbr_base((unsigned long long)n, BASE_DECIMAL, count);
}
