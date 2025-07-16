#ifndef FT_PRİNTF_H
#define FT_PRİNTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
int ft_putchar(char c);
int	ft_putnbr(int n);
int	ft_put_u(unsigned long n);
int	ft_put_x_upper(unsigned int n);
int	ft_put_x(unsigned int n);
int	ft_choice(va_list ag,const char c);
void	ft_arg(char c, va_list *ag);

#endif
