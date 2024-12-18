/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 12:51:50 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/17 15:40:57 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4
# endif

# include <fcntl.h>
# include <stddef.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}					t_list;

t_list				*save_stash_to_list(t_list **head, char *stash);
char				*get_next_line(int fd);
char				*check_stash(char *stash, t_list *head);
void				move_stash(char *dest, char *src, size_t n);
size_t				ft_strlen(char *str);
char				*ft_str_extract(char *s, int end);
char				*process_list(t_list *head, char *last_line);
#endif
