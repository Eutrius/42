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
#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_str_extract(char *s, int end, int flag)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(ft_strlen(s) + 1 + flag);
	if (!str)
		return (NULL);
	while (i < end)
	{
		str[i] = s[i];
		s[i] = '\0';
		i++;
	}
	if (flag)
		str[i] = '\n';
	str[i + 1] = '\0';
	return (str);
}

void	*ft_memmove(void *dest, void *src, size_t n)
{
	size_t			i;
	int				to_left;
	unsigned char	*buff_src;
	unsigned char	*buff_dest;

	if (src == NULL && dest == NULL)
		return (NULL);
	i = 0;
	buff_src = (unsigned char *)src;
	buff_dest = (unsigned char *)dest;
	to_left = (buff_dest < buff_src);
	while (i < n)
	{
		if (to_left)
		{
			buff_dest[i] = buff_src[i];
			buff_src[i] = 0;
		}
		else
		{
			buff_dest[n - i - 1] = buff_src[n - i - 1];
			buff_src[n - i - 1] = 0;
		}
		i++;
	}
	return (dest);
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
			stash[i] = '\0';
			line = ft_str_extract(stash, i, 1);
			ft_memmove(stash, &stash[i + 1], BUFFER_SIZE - i - 1);
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
