/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/26 11:52:16 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/26 14:44:29 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

void	ft_putlchar(int c, int *count)
{
	ft_putchar_fd(c, 1);
	(*count)++;
}

void	ft_putlstr(char *str, int *count)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putlchar(str[i], count);
		i++;
	}
}

void	ft_putlmem(void *mem, int *count)
{
	unsigned long long	address;

	address = (unsigned long long)mem;
	ft_putlstr("0x", count);
	ft_putlnbr_base(address, BASE_HEX_LOWER, count);
}

void	ft_putlint(int num, int *count)
{
	long long	n;

	n = num;
	if (num < 0)
	{
		ft_putlchar('-', count);
		n = -n;
	}
	ft_putlnbr_base((unsigned long long)n, BASE_DECIMAL, count);
}

void	ft_putluint(unsigned int num, int *count)
{
	unsigned long long	n;

	n = num;
	ft_putlnbr_base(n, BASE_DECIMAL, count);
}

void	ft_putlhex(unsigned int num, int is_upper, int *count)
{
	unsigned long long	n;

	n = num;
	if (is_upper)
		ft_putlnbr_base(n, BASE_HEX_UPPER, count);
	else
		ft_putlnbr_base(n, BASE_HEX_LOWER, count);
}

void	ft_putlnbr_base(unsigned long long num, char *base, int *count)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (num >= base_len)
		ft_putlnbr_base(num / base_len, base, count);
	ft_putlchar(base[num % base_len], count);
}
