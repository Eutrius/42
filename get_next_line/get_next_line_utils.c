/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 11:25:55 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/17 15:57:16 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (s1 == NULL)
		return (ft_strldup(s2, ft_strlen(s2)));
	str = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!str)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
	{
		str[i + j] = s2[j];
		j++;
	}
	str[i + j] = 0;
	free(s1);
	return (str);
}

void	move_stash(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		src[i] = '\0';
		i++;
	}
	while (i < BUFFER_SIZE)
	{
		dest[i] = '\0';
		i++;
	}
}

char	*ft_strldup(char *s, size_t len)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len)
	{
		dup[i] = s[i];
		s[i] = '\0';
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*process_list(t_list *head, char *last_line)
{
	char	*line;

	if (last_line == NULL)
		return (NULL);
	line = NULL;
	while (head != NULL)
	{
		line = ft_strjoin(line, head->content);
		if (!line)
			return (NULL);
		head = head->next;
	}
	line = ft_strjoin(line, last_line);
	free(last_line);
	if (!line)
		return (NULL);
	return (line);
}
