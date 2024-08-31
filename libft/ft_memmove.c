/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:12:11 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/19 22:25:36 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				i;
	int					to_left;
	const unsigned char	*buff_src;
	unsigned char		*buff_dest;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	buff_src = (const unsigned char *)src;
	buff_dest = (unsigned char *)dest;
	to_left = (buff_dest < buff_src);
	while (i < n)
	{
		if (to_left)
			buff_dest[i] = buff_src[i];
		else
			buff_dest[n - i - 1] = buff_src[n - i - 1];
		i++;
	}
	return (dest);
}
