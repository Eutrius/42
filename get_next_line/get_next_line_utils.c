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
	while (str[i] != '\0' && str[i] != '\n')
		i++;
	return (i);
}

char	*ft_str_extract(char *s, int end)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (i < end)
	{
		str[i] = s[i];
		s[i] = '\0';
		i++;
	}
	str[i] = '\0';
	return (str);
}

void	move_stash(char *dest, char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		dest[i] = src[i];
		src[i] = 0;
		i++;
	}
}

char	*ft_strcat(char *dest, char *src)
{
	int	dest_len;
	int	i;

	dest_len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[dest_len + i] = src[i];
		i++;
	}
	dest[dest_len + i] = '\0';
	return (dest);
}

char	*process_list(t_list *head, char *last_line)
{
	char	*line;
	int		list_len;
	t_list	*buff;

	list_len = 0;
	buff = head;
	if (last_line == NULL)
		return (NULL);
	while (buff != NULL)
	{
		list_len++;
		buff = buff->next;
	}
	line = malloc((list_len * BUFFER_SIZE) + ft_strlen(last_line) + 1);
	if (!line)
		return (NULL);
	line[0] = '\0';
	while (head != NULL)
	{
		ft_strcat(line, head->content);
		buff = head->next;
		free(head->content);
		free(head);
		head = buff;
	}
	ft_strcat(line, last_line);
	return (line);
}

char	*check_stash(char *stash, t_list *head)
{
	int		i;
	char	*line;

	i = 0;
	while (i <= BUFFER_SIZE)
	{
		if (stash[i] == '\n')
		{
			line = ft_str_extract(stash, i + 1);
			move_stash(stash, &stash[i + 1], BUFFER_SIZE - i - 1);
			if (head != NULL)
			{
				line = process_list(head, line);
			}
			return (line);
		}
		i++;
	}
	return (NULL);
}
