/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:39:12 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/19 17:22:49 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	intlen(long n)
{
	int		count;
	long	nb;

	if (n == 0)
		return (1);
	count = 0;
	nb = n;
	if (nb < 0)
		count++;
	while (nb != 0)
	{
		count++;
		nb /= 10;
	}
	return (count);
}

int	ft_putnbr_fd(int n, int fd)
{
	int		count;
	long	nb;

	nb = n;
	count = intlen(n);
	if (n == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return (count);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", fd);
			nb = -nb;
		}
		if (nb >= 10)
			ft_putnbr_fd(nb / 10, fd);
		ft_putchar_fd((nb % 10) + '0', fd);
	}
	return (count);
}
