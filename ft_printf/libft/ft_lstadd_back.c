/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 20:38:23 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/25 16:12:35 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new_node)
{
	t_list	*last_node;

	if (!new_node)
		return ;
	last_node = ft_lstlast(*lst);
	if (!last_node)
	{
		*lst = new_node;
		return ;
	}
	last_node->next = new_node;
}
