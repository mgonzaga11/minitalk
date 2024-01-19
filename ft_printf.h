/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgonzaga <mgonzaga@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 16:06:20 by mgonzaga          #+#    #+#             */
/*   Updated: 2023/11/08 15:04:07 by mgonzaga         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <string.h>

int		ft_putstr(char *s);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putnbr_unsigned(unsigned int nb);
int		hex_base_up(unsigned int nb);
int		ft_printf(const char *var, ...);
int		hex_base_low(unsigned int nb);
int		hex_code_p(size_t nb);
int		ft_print_function(char *var, va_list ap, int i);
int		hex_base_p(size_t nb);

#endif