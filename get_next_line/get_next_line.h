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
#  define BUFFER_SIZE 1
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

char				*get_next_line(int fd);
char				*check_stash(char *stash, t_list *head);
int					save_stash(t_list **head, char *stash);
char				*process_list(t_list *head, char *last_line);
void				shift_stash(char *stash, int start);
t_list				*create_node(char *content);
void				free_list(t_list **head);
size_t				ft_strlen(char *str);
char				*ft_strjoin(char *s1, char *s2);
char				*ft_strldup(char *str, size_t len);

#endif
