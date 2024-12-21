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

void	free_list(t_list **head)
{
	t_list	*buff;

	while (*head != NULL)
	{
		buff = *head;
		*head = buff->next;
		free(buff->content);
		free(buff);
	}
}

t_list	*create_node(char *content)
{
	t_list	*node;

	if (!content)
		return (NULL);
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->next = NULL;
	node->content = content;
	return (node);
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

char	*check_stash(char *stash, t_list *head)
{
	size_t	i;
	char	*line;

	i = 0;
	while (i < BUFFER_SIZE)
	{
		if (stash[i] == '\n')
		{
			line = ft_strldup(stash, i + 1);
			if (head != NULL)
			{
				line = process_list(head, line);
				free_list(&head);
			}
			if (i != BUFFER_SIZE - 1)
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
			if (head == NULL)
				return (NULL);
			else
			{
				line = process_list(head, "");
				free_list(&head);
				return (line);
			}
		}
	}
}

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

char	*ft_strldup(char *str, size_t len)
{
	char	*dup;
	size_t	i;

	i = 0;
	dup = malloc(len + 1);
	if (!dup)
		return (NULL);
	while (i < len && str[i] != '\0')
	{
		dup[i] = str[i];
		str[i] = '\0';
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*process_list(t_list *head, char *last_line)
{
	char	*line;

	line = NULL;
	while (head != NULL)
	{
		line = ft_strjoin(line, head->content);
		if (!line)
			return (NULL);
		head = head->next;
	}
	line = ft_strjoin(line, last_line);
	if (!last_line)
		free(last_line);
	if (!line)
		return (NULL);
	return (line);
}

char	*get_next(int fd)
{
	static char	stash[BUFFER_SIZE];
	char		*line;
	t_list		*head;

	if (fd <= 0)
		return (NULL);
	head = NULL;
	line = check_stash(stash, head);
	if (line != NULL)
		return (line);
	if (ft_strlen(stash) != 0)
		if (!save_stash(&head, stash))
			return (NULL);
	while (read(fd, stash, BUFFER_SIZE) == BUFFER_SIZE)
	{
		line = check_stash(stash, head);
		if (line != NULL)
			return (line);
		if (!save_stash(&head, stash))
			free_list(&head);
	}
	return (check_stash(stash, head));
}
