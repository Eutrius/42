/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jyriarte <jyriarte@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/25 16:09:28 by jyriarte          #+#    #+#             */
/*   Updated: 2024/12/26 14:35:06 by jyriarte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

# define BASE_DECIMAL "0123456789"
# define BASE_HEX_LOWER "0123456789abcdef"
# define BASE_HEX_UPPER "0123456789ABCDEF"

int		ft_printf(const char *str, ...);
void	print_format(int c, va_list args, int *count);

void	ft_putlchar(int c, int *count);
void	ft_putlstr(char *str, int *count);
void	ft_putlmem(void *mem, int *count);
void	ft_putlint(int num, int *count);
void	ft_putluint(unsigned int num, int *count);
void	ft_putlhex(unsigned int num, int is_upper, int *count);

void	ft_putlnbr_base(unsigned long long num, char *base, int *count);
#endif
