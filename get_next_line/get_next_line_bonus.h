/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 12:44:39 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/24 21:59:18 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# ifndef FD_LIMIT
#  define FD_LIMIT 1024
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*get_line(int fd, char **stash, char **line);
size_t	check_stash(char *stash);
char	*extract_line(char *stash);
void	shift_stash(char *stash, int start);
void	*ft_calloc(size_t nmemb, size_t size);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *str, size_t len);

#endif
