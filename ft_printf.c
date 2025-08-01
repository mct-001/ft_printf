/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutopal <mutopal@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:58:08 by mutopal           #+#    #+#             */
/*   Updated: 2025/07/19 14:47:47 by mutopal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_choice(va_list ag, const char c)
{
	int	j;

	j = 0;
	if (c == 'c')
		j += ft_putchar(va_arg((ag), int));
	else if (c == 's')
		j += ft_putstr(va_arg((ag), char *));
	else if (c == 'i' || c == 'd')
		j += ft_putnbr(va_arg(ag, int));
	else if (c == 'u')
		j += ft_put_u(va_arg((ag), unsigned int));
	else if (c == '%')
		j += ft_putchar('%');
	else if (c == 'x')
		j += ft_put_x(va_arg(ag, unsigned int));
	else if (c == 'X')
		j += ft_put_x_upper(va_arg(ag, unsigned int));
	else if (c == 'p')
		j += ft_putptr((void *)va_arg(ag, unsigned long));
	return (j);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		j;
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
