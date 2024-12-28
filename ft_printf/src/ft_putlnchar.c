/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlnchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 17:27:02 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/28 17:27:26 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlnchar(int c, int num, int *count)
{
	int	i;

	i = 0;
	while (i < num)
	{
		ft_putlchar(c, count, NULL);
		i++;
	}
}
