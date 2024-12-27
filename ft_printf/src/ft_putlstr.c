/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putlstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 18:21:31 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/27 18:35:22 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putlstr(char *str, int *count)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putlstr("(null)", count);
		return ;
	}
	while (str[i] != '\0')
	{
		ft_putlchar(str[i], count);
		i++;
	}
}
