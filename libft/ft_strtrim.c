/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:13:59 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/19 22:14:22 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	i;
	size_t	j;
	char	*str;

	i = 0;
	if (!s1 || !set)
		return (NULL);
	while (s1[i] != '\0')
	{
		if (ft_strchr(set, s1[i]) == NULL)
			break ;
		i++;
	}
	j = ft_strlen(s1) - 1;
	while (j != i)
	{
		if (ft_strchr(set, s1[j]) == NULL)
			break ;
		j--;
	}
	str = ft_substr(s1, (unsigned int)i, j - i + 1);
	if (!str)
		return (NULL);
	return (str);
}
