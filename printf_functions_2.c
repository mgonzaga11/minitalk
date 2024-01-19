/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_functions_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:13:11 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/07/12 13:10:34 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	hex_base_low(unsigned int nb)
{
	char	a;
	int		count;

	a = 0;
	count = 0;
	if (nb > 15)
	{
		count += hex_base_low(nb / 16);
		count += hex_base_low(nb % 16);
	}
	else
	{
		if (nb < 10)
			a = '0' + nb % 16;
		if (nb >= 10)
			a = 'a' + (nb - 10);
		count += ft_putchar(a);
	}
	return (count);
}

int	hex_code_p(size_t nb)
{
	char	*a;
	int		count;

	count = 0;
	a = "0x";
	if (!nb)
	{
		write(1, "(nil)", 5);
		return (5);
	}
	count += ft_putstr (a);
	count += hex_base_p (nb);
	return (count);
}

int	hex_base_p(size_t nb)
{
	char	a;
	int		count;

	a = 0;
	count = 0;
	if (nb > 15)
	{
		count += hex_base_p(nb / 16);
		count += hex_base_p(nb % 16);
	}
	else
	{
		if (nb < 10)
			a = '0' + nb % 16;
		if (nb >= 10)
			a = 'a' + (nb - 10);
		count += ft_putchar(a);
	}
	return (count);
}
