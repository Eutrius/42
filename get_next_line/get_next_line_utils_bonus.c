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
#include <stdint.h>
#include <stdlib.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t			i;
	unsigned char	*buffer;

	if (nmemb != 0 && size > SIZE_MAX / nmemb)
		return (NULL);
	buffer = malloc(nmemb * size);
	if (!buffer)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		buffer[i] = '\0';
		i++;
	}
	return ((void *)buffer);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strndup(char *str, size_t nmemb)
{
	char	*duplicate;
	size_t	i;

	i = 0;
	duplicate = malloc(nmemb + 1);
	if (!duplicate)
		return (NULL);
	while (i < nmemb)
	{
		duplicate[i] = str[i];
		str[i] = '\0';
		i++;
	}
	duplicate[i] = '\0';
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
	new_str[str1_index + str2_index] = '\0';
	free(str1);
	free(str2);
	return (new_str);
}
