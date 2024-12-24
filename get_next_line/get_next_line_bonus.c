/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:45:12 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/24 21:57:34 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_next_line(int fd)
{
	static char	*stashes[FD_LIMIT];
	char		*line;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	if (!stashes[fd])
	{
		stashes[fd] = (char *)ft_calloc(BUFFER_SIZE, 1);
		if (!stashes[fd])
			return (NULL);
	}
	return (get_line(fd, &stashes[fd], &line));
}

char	*get_line(int fd, char **stash, char **line)
{
	int	bytes_read;

	while (1)
	{
		if (check_stash(*stash))
			return (ft_strjoin(*line, extract_line(*stash)));
		*line = ft_strjoin(*line, extract_line(*stash));
		if (!line)
			return (NULL);
		bytes_read = read(fd, *stash, BUFFER_SIZE);
		if (bytes_read < 0)
			break ;
		if (bytes_read == 0)
		{
			if (ft_strlen(*line) > 0)
				return (*line);
			free(*line);
			return (NULL);
		}
	}
	free(*stash);
	free(*line);
	return (NULL);
}

size_t	check_stash(char *stash)
{
	size_t	index;

	index = 0;
	while (index < BUFFER_SIZE && stash[index] != '\0')
	{
		if (stash[index] == '\n')
			return (1);
		index++;
	}
	return (0);
}

char	*extract_line(char *stash)
{
	int		index;
	char	*line;

	index = 0;
	while (index < BUFFER_SIZE && stash[index] != '\0')
	{
		if (stash[index] == '\n')
		{
			line = ft_strndup(stash, index + 1);
			shift_stash(stash, index + 1);
			return (line);
		}
		index++;
	}
	return (ft_strndup(stash, index));
}

void	shift_stash(char *stash, int start)
{
	size_t	index;

	index = 0;
	while (start < BUFFER_SIZE && stash[start])
	{
		stash[index] = stash[start];
		stash[start] = '\0';
		index++;
		start++;
	}
}
