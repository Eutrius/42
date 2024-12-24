/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:45:37 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/24 21:36:42 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			index;
	unsigned char	*buff;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	buff = malloc(nmemb * size);
	if (!buff)
		return (NULL);
	index = 0;
	while (index < nmemb * size)
	{
		buff[index] = '\0';
		index++;
	}
	return ((void *)buff);
}

size_t	ft_strlen(char *str)
{
	size_t	index;

	index = 0;
	if (!str)
		return (0);
	while (str[index] != '\0')
		index++;
	return (index);
}

char	*ft_strndup(char *str, size_t nmemb)
{
	char	*duplicate;
	size_t	index;

	index = 0;
	duplicate = malloc(nmemb + 1);
	if (!duplicate)
		return (NULL);
	while (index < nmemb)
	{
		duplicate[index] = str[index];
		str[index] = '\0';
		index++;
	}
	duplicate[index] = '\0';
	return (duplicate);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*new_str;
	size_t	str1_index;
	size_t	str2_index;

	new_str = malloc(ft_strlen(str1) + ft_strlen(str2) + 1);
	if (!new_str)
		return (NULL);
	str1_index = 0;
	while (str1 && str1[str1_index] != '\0')
	{
		new_str[str1_index] = str1[str1_index];
		str1_index++;
	}
	str2_index = 0;
	while (str2 && str2[str2_index] != '\0')
	{
		new_str[str1_index + str2_index] = str2[str2_index];
		str2_index++;
	}
	new_str[str1_index + str2_index] = 0;
	free(str1);
	free(str2);
	return (new_str);
}
