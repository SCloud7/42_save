/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:04:00 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/27 17:04:26 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int	ft_printformat(char spe, va_list arg)
{
	int	counts;

	counts = 0;
	if (spe == 'c')
		counts = ft_putchar_fd(va_arg(arg, int), 1);
	else if (spe == 's')
		counts = ft_putstr_fd(va_arg(arg, const char *), 1);
	else if (spe == 'u')
		counts = ft_putunsnbr_fd(va_arg(arg, unsigned int), 1);
	else if (spe == 'i' || spe == 'd')
		counts = ft_putnbr_fd(va_arg(arg, int), 1);
	else if (spe == 'x' || spe == 'X')
		counts = ft_printex(va_arg(arg, unsigned int), spe);
	else if (spe == '%')
		counts = ft_putchar_fd('%', 1);
	else if (spe == 'p')
		counts = ft_ptr(va_arg(arg, long long));
	else
		counts = ft_putchar_fd(spe, 1);
	return (counts);
}

int	ft_isalpho(int c)
{
	if ((c >= 'A') && c <= 'Z')
		return (1);
	else if ((c >= 'a') && c <= 'z')
		return (1);
	else
		return (0);
}

int	ft_strnostr(char *haystack, char needle)
{
	int	i;

	i = 0;
	while (haystack[i])
	{
		if (haystack[i] == needle)
			return (1);
		i++;
	}
	return (-1);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		count;

	count = 0;
	va_start(arg, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			if (ft_strnostr("cspduxXi%", *str) == 1)
				count += ft_printformat(*str, arg);
			else if (*str && ft_isalpho(*str) == 1)
				return (count += ft_putchar_fd('%', 1) + ft_putstr_fd(str, 1));
			else
				return (-1);
		}
		else
			count += ft_putchar_fd(*str, 1);
		str++;
	}
	va_end(arg);
	return (count);
}
