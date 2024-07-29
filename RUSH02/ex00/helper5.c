/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper5.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 21:35:58 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/28 21:36:31 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	check_mall(char *buff, t_dict *dict)
{
	if (!buff)
	{
		ft_free_list(dict);
		ft_error("Malloc Error\n");
	}
}

void	ft_free_list(t_dict *dict)
{
	if (dict->next == NULL)
	{
		free(dict);
		return ;
	}
	ft_free_list(dict->next);
	free(dict->word);
	free(dict->number);
	free(dict);
}

void	ft_rfree_list(t_dict *dict)
{
	if (dict->prev == NULL)
	{
		free(dict);
		return ;
	}
	ft_free_list(dict->prev);
	free(dict->word);
	free(dict->number);
	free(dict);
}
