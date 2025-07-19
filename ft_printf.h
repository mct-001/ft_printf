/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mutopal <mutopal@student.42istanbul.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/17 23:03:04 by mutopal           #+#    #+#             */
/*   Updated: 2025/07/17 23:06:46 by mutopal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_put_u(unsigned int n);
int		ft_put_x_upper(unsigned int n);
int		ft_put_x(unsigned int n);
int		ft_putptr(void *ptr);
int		ft_puthex_p(unsigned long n);
int		ft_choice(va_list ag, const char c);
void	ft_arg(char c, va_list *ag);

#endif
