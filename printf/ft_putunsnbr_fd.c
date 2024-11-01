/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsnbr_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 17:39:12 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/19 17:22:04 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <unistd.h>

static int	intelen(unsigned long n)
{
	int				count;
	unsigned long	nb;

	count = 0;
	nb = n;
	if (n == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		count++;
	}
	return (count);
}

int	ft_putunsnbr_fd(unsigned long n, int fd)
{
	int		count;
	long	nb;

	nb = n;
	count = intelen(nb);
	if (nb > 9)
		ft_putunsnbr_fd(nb / 10, fd);
	ft_putchar_fd((nb % 10) + '0', fd);
	return (count);
}
