/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/03 19:23:15 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/07/12 15:55:11 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_function(char *var, va_list ap, int i)
{
	int	str_count;

	str_count = 0;
	if (var[i] == '%')
		str_count = ft_putchar('%');
	if (var[i] == 'c')
		str_count = ft_putchar(va_arg(ap, int));
	if (var[i] == 's')
		str_count = ft_putstr(va_arg(ap, char *));
	if (var[i] == 'd' || var[i] == 'i')
		str_count = ft_putnbr(va_arg(ap, int));
	if (var[i] == 'u')
		str_count = ft_putnbr_unsigned(va_arg(ap, unsigned int));
	if (var[i] == 'p')
		str_count = hex_code_p(va_arg(ap, size_t));
	if (var[i] == 'x')
		str_count = hex_base_low(va_arg(ap, unsigned int));
	if (var[i] == 'X')
		str_count = hex_base_up(va_arg(ap, unsigned int));
	return (str_count);
}

int	ft_printf(const char *var, ...)
{
	va_list	ap;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (!var)
		return (-1);
	va_start(ap, var);
	while (var[i] != '\0')
	{
		while (var[i] != '%' && var[i] != '\0')
		{
			count += ft_putchar(var[i]);
			i++;
		}
		if (var[i] == '%')
		{
			i++;
			count += ft_print_function((char *)var, ap, i);
			i++;
		}
	}
	va_end(ap);
	return (count);
}
