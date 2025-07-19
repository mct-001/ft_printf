/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutopal <mutopal@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 22:59:52 by mutopal           #+#    #+#             */
/*   Updated: 2025/07/19 14:34:09 by mutopal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex_p(unsigned long n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n >= 16)
		count += ft_puthex_p(n / 16);
	count += write(1, &hex[n % 16], 1);
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == 0)
	{
		write (1, "(nil)", 5);
		count = count + 5;
	}
	else
	{
		count += write(1, "0x", 2);
		count += ft_puthex_p((unsigned long)ptr);
	}
	return (count);
}
