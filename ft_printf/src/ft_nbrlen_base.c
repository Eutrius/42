/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nbrlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 22:38:26 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/28 22:38:39 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_nbrlen_base(unsigned long long nbr, char *base)
{
	int	count;
	int	base_len;

	count = 0;
	if (nbr == 0)
		return (1);
	base_len = ft_strlen(base);
	while (nbr > 0)
	{
		nbr /= base_len;
		count++;
	}
	return (count);
}
