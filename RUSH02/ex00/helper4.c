/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 17:08:17 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/28 21:36:14 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_mid_space_trim(char *str)
{
	int	i;
	int	j;
	int	space_flag;

	i = 0;
	j = 0;
	space_flag = 0;
	while (str[i] != '\0')
	{
		if (str[i] != ' ')
		{
			if (space_flag && j > 0)
				str[j++] = ' ';
			str[j++] = str[i];
			space_flag = 0;
		}
		else if (!space_flag)
			space_flag = 1;
		i++;
	}
	str[j] = '\0';
}

char	*ft_gen_tens(int len)
{
	char	*num;

	while (len % 3 != 1)
		len--;
	num = ft_gen_buff(len);
	if (!num)
		return (NULL);
	num[0] = '1';
	return (num);
}

void	ft_error(char *msg)
{
	ft_putstr(msg);
	exit(1);
}

int	ft_str_is_numeric(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < 47 || str[i] > 58)
		{
			return (0);
		}
		i++;
	}
	return (1);
}
