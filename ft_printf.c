#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putstr(char *str)
{
	int	i;

	i = 0;
	if (!str)
	{
		ft_putstr("(null)");
		return (6);
	}
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

int	ft_choice(va_list ag,const char c)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += ft_putchar(va_arg((ag), int));
	else if (c == 's')
		j += ft_putstr(va_arg((ag), char *));
	else if (c == 'i' || c == 'd')
		j += ft_putnbr(va_arg(ag, int));
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int	i;
	int	j;
	va_list	ag;

	i = 0;
	j = 0;
	va_start(ag, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			j += ft_choice(ag, str[i + 1]);
			i++;
		}
		else
		{
			j += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(ag);
	return (j);
}
