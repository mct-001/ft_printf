#ifndef FT_PRİNTF_H
#define FT_PRİNTF_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int	ft_printf(const char *str, ...);
void	ft_putnbr(int n);
void	ft_arg(char c, va_list *ag);

#endif
