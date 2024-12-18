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

t_list	*save_stash_to_list(t_list **head, char *stash)
{
	t_list	*node;
	t_list	*buffer;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->content = ft_str_extract(stash, BUFFER_SIZE);
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

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	char		*line;
	t_list		*head;

	if (fd <= 0)
		return (NULL);
	head = NULL;
	line = check_stash(stash, head);
	if (line != NULL)
		return (line);
	if (ft_strlen(stash) != 0)
		if (save_stash_to_list(&head, stash) == NULL)
			return (NULL);
	while (read(fd, stash, BUFFER_SIZE) != 0)
	{
		line = check_stash(stash, head);
		if (line != NULL)
			return (line);
		save_stash_to_list(&head, stash);
	}
	return (process_list(head, NULL));
}
