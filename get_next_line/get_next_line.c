/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/16 16:10:46 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/17 16:25:25 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*line;
	t_list		*head;
	int			bytes_read;

	if (fd <= 0)
		return (NULL);
	head = NULL;
	while (1)
	{
		line = check_stash(stash, head);
		if (line != NULL)
			return (line);
		if (save_stash(&head, stash) == -1)
			return (NULL);
		bytes_read = read(fd, stash, BUFFER_SIZE);
		if (bytes_read < 0)
			return (NULL);
		if (bytes_read == 0)
		{
			if (head != NULL)
				return (process_list(head, ""));
			return (NULL);
		}
	}
}

char	*check_stash(char *stash, t_list *head)
{
	int		i;
	char	*line;

	i = 0;
	while (i < BUFFER_SIZE && stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			line = ft_strldup(stash, i + 1);
			if (head != NULL)
				line = process_list(head, line);
			shift_stash(stash, i + 1);
			return (line);
		}
		i++;
	}
	return (NULL);
}

int	save_stash(t_list **head, char *stash)
{
	t_list	*node;
	t_list	*buffer;

	if (stash[0] == '\0')
		return (0);
	node = create_node(ft_strldup(stash, BUFFER_SIZE));
	if (!node)
	{
		free_list(head);
		return (-1);
	}
	if (*head == NULL)
	{
		*head = node;
		return (1);
	}
	buffer = *head;
	while (buffer->next != NULL)
		buffer = buffer->next;
	buffer->next = node;
	return (1);
}

char	*process_list(t_list *head, char *last_line)
{
	char	*line;
	t_list	*buff;

	line = NULL;
	buff = head;
	while (buff != NULL)
	{
		line = ft_strjoin(line, buff->content);
		if (!line)
			return (NULL);
		buff = buff->next;
	}
	free_list(&head);
	line = ft_strjoin(line, last_line);
	if (last_line[0] != '\0')
		free(last_line);
	if (!line)
		return (NULL);
	return (line);
}

void	shift_stash(char *stash, int start)
{
	size_t	i;

	i = 0;
	while (start < BUFFER_SIZE && stash[start])
	{
		stash[i] = stash[start];
		stash[start] = '\0';
		i++;
		start++;
	}
}
