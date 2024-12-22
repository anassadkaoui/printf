/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asadkaou <asadkaou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 18:52:54 by asadkaou          #+#    #+#             */
/*   Updated: 2024/11/23 15:23:19 by asadkaou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <string.h>

int	ft_printf(const char *str, ...);
int	ft_params(char convension_specifier, va_list args);
int	ft_Xxp(unsigned long value, char convension_specifier);
int	ft_id(int n, int fd);
int	ft_u(unsigned int n, int fd);
int	ft_s(char *s, int fd);
int	ft_c(char s);

#endif
