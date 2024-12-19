#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

void	ft_printf(const char *str, ...);
void	ft_putstr(char *str);
void	ft_putchr(int c);

int	main(void)
{
	ft_printf("hello");
}

void	ft_putchr(int c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	size_t	i;

	if (!str)
		return ;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchr(str[i]);
		i++;
	}
}

void	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;

	i = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
		}
		else
		{
			ft_putchr(str[i]);
			i++;
		}
	}
}
