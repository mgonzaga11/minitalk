/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:01:13 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/07/12 15:55:32 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		return (6);
	}
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	ft_putchar(char c)
{
	int	count;

	count = 0;
	count += write(1, &c, 1);
	return (count);
}

int	ft_putnbr(int nb)
{
	char	a;
	int		count;

	a = 0;
	count = 0;
	if (nb == -2147483648)
		count += ft_putstr("-2147483648");
	else if (nb < 0)
	{
		nb = nb * (-1);
		count += ft_putchar('-');
		count += ft_putnbr(nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		a = '0' + nb % 10;
		count += ft_putchar(a);
	}
	return (count);
}

int	ft_putnbr_unsigned(unsigned int nb)
{
	char	a;
	int		count;

	a = 0;
	count = 0;
	if (nb > 9)
	{
		count += ft_putnbr_unsigned(nb / 10);
		count += ft_putnbr_unsigned(nb % 10);
	}
	else
	{
		a = '0' + nb % 10;
		count += ft_putchar(a);
	}
	return (count);
}

int	hex_base_up(unsigned int nb)
{
	char	a;
	int		count;

	a = 0;
	count = 0;
	if (nb > 15)
	{
		count += hex_base_up(nb / 16);
		count += hex_base_up(nb % 16);
	}
	else
	{
		if (nb < 10)
			a = '0' + nb % 16;
		if (nb >= 10)
			a = 'A' + (nb - 10);
		count += ft_putchar(a);
	}
	return (count);
}
