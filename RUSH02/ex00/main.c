/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 11:31:44 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/28 21:49:49 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	ft_valid_length(char *input, t_dict *list)
{
	int		input_len;
	t_dict	*temp;
	int		max_len;
	int		temp_len;

	input_len = ft_str_len(input);
	max_len = 0;
	temp = list;
	while (temp->next != NULL)
	{
		temp_len = ft_str_len(temp->number);
		if (max_len < temp_len)
			max_len = temp_len;
		temp = temp->next;
	}
	return (input_len <= max_len + 2);
}

void	main2(char *input, char *filename, t_dict *list)
{
	if (!input)
	{
		free(list);
		ft_error("Error\n");
	}
	if (parse_dictionary(filename, list))
	{
		free(list);
		ft_error("Dict Error\n");
	}
	if (!ft_valid_length(input, list))
	{
		ft_free_list(list);
		ft_error("Dict Error\n");
	}
	print(input, list);
}

int	main(int argc, char **argv)
{
	char	*input;
	t_dict	*list;
	char	*filename;

	if (argc < 2 || argc > 3)
		ft_error("Error\n");
	list = (t_dict *)malloc(sizeof(t_dict));
	list->prev = NULL;
	if (!list)
		ft_error("Malloc Error\n");
	filename = "numbers.dict";
	input = ft_validate_input(argv[1]);
	if (argc == 3)
	{
		filename = argv[1];
		input = ft_validate_input(argv[2]);
	}
	main2(input, filename, list);
	ft_free_list(list);
	return (0);
}
