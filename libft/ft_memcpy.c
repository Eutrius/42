/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:10:03 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/19 22:10:04 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	const unsigned char	*buff_src;
	unsigned char		*buff_dest;

	if (dest == NULL && src == NULL)
		return (dest);
	i = 0;
	buff_src = (const unsigned char *)src;
	buff_dest = (unsigned char *)dest;
	while (i < n)
	{
		buff_dest[i] = buff_src[i];
		i++;
	}
	return (dest);
}
