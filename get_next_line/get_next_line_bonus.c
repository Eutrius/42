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
#include <stdlib.h>
#include <unistd.h>

char	*get_next_line(int fd)
{
	static char	*stashes[FD_LIMIT];
	char		**stash;
	char		*line;

	if (fd < 0 || fd >= FD_LIMIT || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	stash = &stashes[fd];
	if (!*stash)
	{
		*stash = (char *)ft_calloc(BUFFER_SIZE, 1);
		if (!*stash)
			return (NULL);
	}
	return (get_line(fd, stash, &line));
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
			if (ft_strlen(*line) == 0)
				break ;
			free(*stash);
			*stash = NULL;
			return (*line);
		}
	}
	free(*stash);
	free(*line);
	*stash = NULL;
	return (NULL);
}

size_t	check_stash(char *stash)
{
	size_t	i;

	i = 0;
	while (i < BUFFER_SIZE && stash[i] != '\0')
	{
		if (stash[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*extract_line(char *stash)
{
	int		i;
	char	*line;

	i = 0;
	while (i < BUFFER_SIZE && stash[i] != '\0')
	{
		if (stash[i] == '\n')
		{
			line = ft_strndup(stash, i + 1);
			shift_stash(stash, i + 1);
			return (line);
		}
		i++;
	}
	return (ft_strndup(stash, i));
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
