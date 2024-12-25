/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:09:45 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/19 22:09:46 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*buff;

	i = 0;
	buff = (unsigned char *)s;
	while (i < n)
	{
		buff[i] = (unsigned char)c;
		i++;
	}
	return (s);
}
