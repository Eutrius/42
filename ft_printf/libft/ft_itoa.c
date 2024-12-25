/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:11:04 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/19 22:11:05 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static int	count_digits(int n);

char	*ft_itoa(int n)
{
	int		n_digits;
	char	*res;
	long	nb;

	n_digits = count_digits(n);
	nb = (long)n;
	res = ft_calloc(n_digits + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (nb < 0)
		nb = -nb;
	while (n_digits > 0)
	{
		res[n_digits - 1] = (nb % 10) + '0';
		n_digits--;
		nb = nb / 10;
	}
	if (n < 0)
		res[0] = '-';
	return (res);
}

static int	count_digits(int n)
{
	int	count;

	count = 0;
	if (n == 0)
		return (1);
	if (n == INT_MIN)
		return (11);
	if (n < 0)
	{
		count++;
		n = -n;
	}
	while (n > 0)
	{
		count++;
		n = n / 10;
	}
	return (count);
}
