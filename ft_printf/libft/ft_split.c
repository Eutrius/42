/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/19 22:11:09 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/21 21:20:53 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	count_words(char const *s, char c);
static void		append_word(char **arr, char *s, size_t arr_len);
static char		*shift_to_c(char const *s, size_t *start, char c);
static void		*free_words(char **strs);

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	word_count;
	char	*str;
	char	**strs;

	if (!s)
		return (NULL);
	i = 0;
	word_count = count_words(s, c);
	strs = ft_calloc(word_count + 1, sizeof(char *));
	if (!strs)
		return (NULL);
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			str = shift_to_c(s, &i, c);
			if (!str)
				return (free_words(strs));
			append_word(strs, str, word_count + 1);
		}
		i++;
	}
	return (strs);
}

static char	*shift_to_c(char const *s, size_t *start, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[*start + i] != c && s[*start + i] != '\0')
		i++;
	str = ft_substr(s, *start, i);
	if (!str)
		return (NULL);
	*start += i - 1;
	return (str);
}

static void	append_word(char **arr, char *s, size_t arr_len)
{
	size_t	i;

	i = 0;
	while (arr[i] != NULL && i < arr_len)
		i++;
	arr[i] = s;
}

static size_t	count_words(char const *s, char c)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] != c && s[i] != '\0')
				i++;
		}
		else
			i++;
	}
	return (count);
}

static void	*free_words(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i] != NULL)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}
