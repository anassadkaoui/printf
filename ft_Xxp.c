/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_Xxp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:24:02 by hkaddour          #+#    #+#             */
/*   Updated: 2024/11/23 15:20:25 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_Xxp(unsigned long value, char convension_specifier)
{
	char	hex[16];
	int		i;
	int		total;
	char const *hexDigits = "0123456789abcdef";

	if (convension_specifier == 'X')
		hexDigits = "0123456789ABCDEF";
	if (value == 0)
		return (write(1, "0", 1));
	total = 0;
	i = 0;
	while (value > 0)
	{
		int remainder = value % 16;
		hex[i++] = hexDigits[remainder];
		value /= 16;
	}
	i--;
	while (i >= 0)
		total += write(1, &hex[i--], 1);
	return (total);
}
