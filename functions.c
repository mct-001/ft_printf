#include "ft_printf.h"

void	ft_putnbr(int n)
{
	int	i;

	i = n;
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	if (n < 0)
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
}
