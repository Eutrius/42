/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 12:10:17 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/28 20:42:05 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*ft_trim(char *str)
{
	char	*end;

	while (*str == ' ' || *str == '\t')
	{
		str++;
	}
	if (*str == 0)
	{
		return (str);
	}
	end = str + ft_str_len(str) - 1;
	while (end > str && (*end == ' ' || *end == '\t'))
	{
		end--;
	}
	*(end + 1) = '\0';
	return (str);
}

void	*ft_mem_cpy(void *dest, void *src, size_t n)
{
	char	*d;
	char	*s;

	s = src;
	d = dest;
	while (n--)
	{
		*d++ = *s++;
	}
	return (dest);
}

int	ft_input_len(char *str)
{
	int	len;
	int	is_negative;
	int	i;

	i = 0;
	len = 0;
	is_negative = 1;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			is_negative = -is_negative;
		i++;
	}
	while (str[i] == '0' && ft_ch_is_numeric(str[i + 1]))
		i++;
	while (ft_ch_is_numeric(str[i++]))
		len++;
	if (len == 1 && str[i - 1] == '0')
		return (1);
	return (len * is_negative);
}

void	ft_get_value(char *dest, char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
		i++;
	while (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] == '0' && ft_ch_is_numeric(str[i + 1]))
		i++;
	while (ft_ch_is_numeric(str[i]))
	{
		*dest = str[i];
		i++;
		dest++;
	}
	*dest = '\0';
}

char	*ft_validate_input(char *str)
{
	if (*str == '-' || *str == '\0')
		return (NULL);
	if (*str == '+')
		str++;
	if (ft_str_is_numeric(str))
		return (str);
	return (NULL);
}
