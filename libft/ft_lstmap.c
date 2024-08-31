/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/21 21:25:13 by jyriarte          #+#    #+#             */
/*   Updated: 2024/08/21 21:37:11 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*head;
	t_list	*current_node;
	t_list	*tmp_node;

	current_node = lst;
	head = NULL;
	while (current_node != NULL)
	{
		tmp_node = ft_lstnew(f(current_node->content));
		if (!tmp_node)
		{
			ft_lstclear(&head, del);
			return (NULL);
		}
		ft_lstadd_back(&head, tmp_node);
		current_node = current_node->next;
	}
	return (head);
}
