/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/24 19:22:12 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/24 21:16:11 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000000
# endif

# include <stddef.h>

char	*get_next_line(int fd);
char	*get_line(int fd, char (*stash)[BUFFER_SIZE], char **line);
size_t	check_stash(char *stash);
char	*extract_line(char *stash);
void	shift_stash(char *stash, int start);
size_t	ft_strlen(char *str);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_strndup(char *str, size_t len);

#endif
