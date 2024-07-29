/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_dict.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 15:20:33 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/29 11:05:30 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

t_dict	*ft_append_list(t_dict *tail, char *number, char *word)
{
	t_dict	*temp;

	temp = (t_dict *)malloc(sizeof(t_dict));
	tail->number = ft_strdup(number);
	tail->word = ft_strdup(word);
	if (!temp || !tail->number || !tail->word)
	{
		ft_rfree_list(tail);
		ft_error("Malloc Error\n");
	}
	temp->next = NULL;
	temp->prev = tail;
	tail->next = temp;
	return (temp);
}

void	process_line(char *line, t_dict **tail)
{
	char	*colon;
	char	*number_str;
	char	*word;

	colon = ft_str_chr(line, ':');
	if (colon != NULL)
	{
		*colon = '\0';
		number_str = ft_trim(line);
		ft_get_value(number_str, number_str);
		word = ft_trim(colon + 1);
		ft_mid_space_trim(word);
		if (ft_str_len(number_str) > 0 && ft_str_len(word) > 0)
		{
			*tail = ft_append_list(*tail, number_str, word);
		}
	}
}

void	process_buffer(char *buffer, int bytes_read, int *line_start,
		t_dict **tail)
{
	int	i;
	int	total_length;

	i = 0;
	total_length = bytes_read + *line_start;
	while (i < total_length)
	{
		if (buffer[i] == '\n')
		{
			buffer[i] = '\0';
			process_line(buffer + *line_start, tail);
			*line_start = i + 1;
		}
		i++;
	}
}

void	handle_remaining(char *buffer, int *line_start, int i)
{
	int	remaining;

	if (*line_start < i)
	{
		remaining = i - *line_start;
		ft_mem_cpy(buffer, buffer + *line_start, remaining);
		*line_start = remaining;
	}
}

int	parse_dictionary(char *filename, t_dict *head)
{
	int		fd;
	char	buffer[BUFFER_SIZE];
	int		line_start;
	t_dict	*tail;
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		return (1);
	line_start = 0;
	tail = head;
	bytes_read = read(fd, buffer + line_start, BUFFER_SIZE - line_start);
	while (bytes_read > 0)
	{
		process_buffer(buffer, bytes_read, &line_start, &tail);
		handle_remaining(buffer, &line_start, bytes_read + line_start);
		bytes_read = read(fd, buffer + line_start, BUFFER_SIZE - line_start);
	}
	close(fd);
	return (0);
}
