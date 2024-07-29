/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 13:30:30 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/28 21:28:35 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_str_chr(char *s, int c)
{
	while (*s != '\0')
	{
		if (*s == c)
		{
			return ((char *)s);
		}
		s++;
	}
	return (NULL);
}

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 < *s2)
			return (-1);
		else if (*s1 > *s2)
			return (1);
		s1++;
		s2++;
	}
	if (*s1 == *s2)
		return (0);
	else if ((*s1 == '\0') && (*s2 != '\0'))
		return (-1);
	else
		return (1);
}

void	ft_print_sep(int n)
{
	if (n == 1)
		ft_putstr(" ");
	else if (n == 2)
		ft_putstr("-");
	else if (n == 3)
		ft_putstr(", ");
	else if (n == 4)
		ft_putstr("\n");
}

char	*ft_gen_buff(int n)
{
	char	*buff;
	int		i;

	buff = (char *)malloc(n + 1);
	if (!buff)
		return (NULL);
	i = 0;
	while (i < n)
	{
		buff[i] = '0';
		i++;
	}
	buff[i] = 0;
	return (buff);
}

int	ft_adjust_index(int n)
{
	int	i;

	i = n % 3;
	if (i == 2)
		i--;
	else if (i == 1)
		i++;
	return (i);
}
