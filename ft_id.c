/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_id.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 13:02:29 by asadkaou          #+#    #+#             */
/*   Updated: 2024/11/23 15:17:05 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	cpy_digits(int n, int i, char *buffer)
{
	while (n != 0)
	{
		buffer[i++] = (n % 10) + '0';
		n /= 10;
	}
	return (i);
}

int	ft_id(int n, int fd)
{
	int		i;
	int		total;
	char	buffer[11];

	if (fd < 0)
		return (0);
	if (n == 0)
		return (write(fd, "0", 1));
	if (n == -2147483648)
		return (write(fd, "-2147483648", 11));
	total = 0;
	if (n < 0)
	{
		total += write(fd, "-", 1);
		n = -n;
	}
	i = 0;
	i = cpy_digits(n, i, buffer);
	while (i > 0)
		total += write(fd, &buffer[--i], 1);
	return (total);
}
