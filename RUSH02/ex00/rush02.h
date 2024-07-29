/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 10:32:22 by jyriarte          #+#    #+#             */
/*   Updated: 2024/07/28 22:18:02 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH02_H
# define RUSH02_H
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# define BUFFER_SIZE 4096

typedef struct s_dict
{
	char			*number;
	char			*word;
	struct s_dict	*next;
	struct s_dict	*prev;
}	t_dict;

void	ft_putstr(char *s);
void	check_mall(char *buff, t_dict *dict);
void	ft_error(char *msg);
int		ft_ch_is_numeric(char c);
int		parse_dictionary(char *filename, t_dict *head);
int		ft_str_len(char *str);
char	*ft_strcpy(char *dest, char *src);
char	*ft_strdup(char *src);
char	*ft_str_chr(char *s, int c);
char	*ft_trim(char *str);
void	*ft_mem_cpy(void *dest, void *src, size_t n);
int		ft_input_len(char *str);
void	ft_get_value(char *dest, char *str);
char	*ft_validate_input(char *str);
int		get_number(char *number, t_dict *dict, int sep);
int		ft_strcmp(char *s1, char *s2);
void	print_number(char *number, t_dict *dict);
char	*tens(int n);
void	print(char *number, t_dict *dict);
void	ft_print_sep(int n);
char	*ft_gen_buff(int n);
void	print2(char *buff, t_dict *dict, int len, char *number);
int		ft_adjust_index(int n);
int		ft_str_space_len(char *str);
void	ft_mid_space_trim(char *str);
char	*ft_gen_tens(int len);
int		ft_str_is_numeric(char *str);
void	ft_free_list(t_dict *dict);
void	ft_rfree_list(t_dict *dict);

#endif
