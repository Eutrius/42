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

void	free_list(t_list *head)
{
	t_list	*buff;

	while (head != NULL)
	{
		free(head->content);
		buff = head->next;
		free(head);
		head = buff;
	}
}

t_list	*save_stash(t_list **head, char *stash)
{
	t_list	*node;
	t_list	*buffer;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
	{
		free_list(*head);
		return (NULL);
	}
	node->next = NULL;
	node->content = ft_strldup(stash, BUFFER_SIZE);
	if (*head == NULL)
		*head = node;
	else
	{
		buffer = *head;
		while (buffer->next != NULL)
		{
			buffer = buffer->next;
		}
		buffer->next = node;
	}
	return (*head);
}

char	*check_stash(char *stash, t_list *head, int c)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < BUFFER_SIZE && stash[i])
	{
		if (stash[i] == c)
		{
			line = ft_strldup(stash, i + 1);
			if (head != NULL)
			{
				line = process_list(head, line);
				free_list(head);
			}
			move_stash(stash, &stash[i + 1], BUFFER_SIZE - i - 1);
			return (line);
		}
		i++;
	}
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*line;
	t_list		*head;

	if (fd <= 0)
		return (NULL);
	head = NULL;
	line = check_stash(stash, head, '\n');
	if (line != NULL)
		return (line);
	if (ft_strlen(stash) != 0)
		if (save_stash(&head, stash) == NULL)
			return (NULL);
	while (read(fd, stash, BUFFER_SIZE) == BUFFER_SIZE)
	{
		line = check_stash(stash, head, '\n');
		if (line != NULL)
			return (line);
		if (!save_stash(&head, stash))
			free_list(head);
	}
	return (check_stash(stash, head, '\0'));
}
