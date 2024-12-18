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

void	ft_lstadd_back(t_list *head, t_list *new_node)
{
	t_list	*buffer;

	buffer = head;
	while (buffer->next != NULL)
	{
		buffer = buffer->next;
	}
	buffer->next = new_node;
}

t_list	*create_node(char *stash)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = ft_str_extract(stash, BUFFER_SIZE, 0);
	return (node);
}

char	*get_next_line(int fd)
{
	static char	stash[BUFFER_SIZE + 1];
	int			stash_len;
	char		*line;
	int			read_line;
	t_list		*head;

	if (fd <= 0)
		return (NULL);
	head = NULL;
	line = check_stash(stash, head);
	stash_len = ft_strlen(stash);
	if (line != NULL)
		return (line);
	if (stash_len != 0)
	{
		head = create_node(stash);
		if (!head)
			return (NULL);
	}
	while (1)
	{
		read_line = read(fd, stash, BUFFER_SIZE);
		if (read_line == 0)
			return (process_list(head, NULL));
		line = check_stash(stash, head);
		if (line != NULL)
			return (line);
		if (head)
			ft_lstadd_back(head, create_node(stash));
		else
			head = create_node(stash);
	}
	return (line);
}
