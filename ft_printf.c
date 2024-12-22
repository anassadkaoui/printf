/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 11:14:45 by hkaddour          #+#    #+#             */
/*   Updated: 2024/11/23 15:49:56 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_params(char convension_specifier, va_list args)
{
	int char_printed;

	char_printed = 0;
	if (convension_specifier == 'X')
		char_printed += ft_Xxp(va_arg(args, unsigned int), convension_specifier);
	else if (convension_specifier == 'x')
		char_printed += ft_Xxp(va_arg(args, unsigned int), convension_specifier);
	else if (convension_specifier == 'p')
	{
		char_printed += ft_s("0x", 1);
		char_printed += ft_Xxp(va_arg(args, unsigned long), convension_specifier);
	}
	else if (convension_specifier == 'd' || convension_specifier == 'i')
		char_printed += ft_id(va_arg(args, int), 1);
	else if (convension_specifier == 'u')
		char_printed += ft_u(va_arg(args, unsigned int), 1);
	else if (convension_specifier == 's')
		char_printed += ft_s(va_arg(args, char *), 1);
	else if (convension_specifier == 'c')
		char_printed += ft_c(va_arg(args, int));
	else if (convension_specifier == '%')
		char_printed += ft_c(convension_specifier);
	else
		char_printed += ft_c(convension_specifier);
	return (char_printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		char_printed;
	
	if (write(1, "", 0) == -1)
		return (-1);
	char_printed = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) == '\0')
			return (char_printed);
		if (*str == '%')
		{
			str++;
			char_printed += ft_params(*str, args);
		}
		else
			char_printed += write(1, str, 1);
		str++;
	}
	va_end(args);
	return (char_printed);
}
