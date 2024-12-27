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

void	ft_putluint(unsigned int num, int *count)
{
	unsigned long long	n;

	n = num;
	ft_putlnbr_base(n, BASE_DECIMAL, count);
}
