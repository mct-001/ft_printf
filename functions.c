/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutopal <mutopal@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:58:53 by mutopal           #+#    #+#             */
/*   Updated: 2025/07/19 13:45:50 by mutopal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		n /= 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int n)
{
	int	i;

	i = n;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (i < 0)
	{
		ft_putchar('-');
		i = i * -1;
	}
	if (10 <= i)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + '0');
	return (ft_len(n));
}

int	ft_put_u(unsigned int n)
{
	int	i;

	i = 0;
	if (9 < n)
		i = i + ft_put_u(n / 10);
	i = i + ft_putchar(n % 10 + '0');
	return (i);
}

int	ft_put_x(unsigned int n)
{
	char	*hex;
	int		len;

	len = 0;
	hex = "0123456789abcdef";
	if (16 <= n)
		len += ft_put_x(n / 16);
	len += ft_putchar(hex[n % 16]);
	return (len);
}

int	ft_put_x_upper(unsigned int n)
{
	char	*hex;
	int		len;

	len = 0;
	hex = "0123456789ABCDEF";
	if (16 <= n)
		len += ft_put_x_upper(n / 16);
	len += ft_putchar(hex[n % 16]);
	return (len);
}
