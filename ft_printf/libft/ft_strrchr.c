/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:12:42 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/21 21:22:08 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	char	*last_occurence;

	i = 0;
	last_occurence = NULL;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			last_occurence = (char *)&str[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (last_occurence);
}
