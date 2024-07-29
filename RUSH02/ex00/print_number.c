/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btsegaye <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:30:07 by btsegaye          #+#    #+#             */
/*   Updated: 2024/07/28 21:35:26 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	get_number(char *number, t_dict *dict, int sep)
{
	t_dict	*temp;

	temp = dict;
	while (temp->next != NULL)
	{
		if (ft_strcmp(temp->number, number) == 0)
		{
			ft_putstr(temp->word);
			ft_print_sep(sep);
			return (1);
		}
		temp = temp->next;
	}
	return (0);
}

void	process_number_segment(char *number, t_dict *dict, int len)
{
	char	*buff;

	buff = ft_gen_buff(2);
	check_mall(buff, dict);
	if (len == 3)
	{
		buff[1] = *number;
		get_number(&buff[1], dict, 1);
		get_number("100", dict, (number[2] != '0' || number[1] != '0'));
	}
	else if (len == 2)
	{
		buff[0] = *number;
		get_number(buff, dict, (number[2] != '0') + 1);
	}
	else
		get_number(number, dict, 0);
	free(buff);
}

void	print_number(char *number, t_dict *dict)
{
	int	len;

	len = ft_str_len(number);
	if (len < 3)
	{
		if ((number[0] >= '2' && number[1] == '0' && get_number(number, dict,
					0)) || (number[0] == '1' && get_number(number, dict, 0)))
			return ;
	}
	process_number_segment(number, dict, len);
	number++;
	while (*number == '0')
		number++;
	if (*number)
		print_number(number, dict);
}

void	print(char *number, t_dict *dict)
{
	char	*buff;
	int		len;
	int		i;

	if (!ft_strcmp(number, "0") && get_number(number, dict, 4))
		return ;
	buff = ft_gen_buff(3);
	check_mall(buff, dict);
	while (*number)
	{
		while (*number == '0')
			number++;
		if (!*number)
			break ;
		len = ft_str_len(number);
		i = ft_adjust_index(len);
		while (i < 3)
		{
			buff[i++] = *number;
			number++;
		}
		print2(&buff[ft_adjust_index(len)], dict, len, number);
	}
	free(buff);
	ft_putstr("\n");
}

void	print2(char *buff, t_dict *dict, int len, char *number)
{
	char	*tens;

	print_number(buff, dict);
	tens = ft_gen_tens(len);
	check_mall(tens, dict);
	if (len > 3)
	{
		while (*number == '0')
			number++;
		ft_putstr(" ");
		get_number(tens, dict, 3 - 3 * (*number == 0));
	}
	free(tens);
}
