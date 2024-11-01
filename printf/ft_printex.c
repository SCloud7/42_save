/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 18:40:16 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/21 16:20:40 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"ft_printf.h"

static int	hexlen(unsigned long nb)
{
	int	count;

	count = 0;
	if (nb == 0)
		return (1);
	while (nb)
	{
		count++;
		nb /= 16;
	}
	return (count);
}

int	ft_printex(unsigned long nb, char symbol)
{
	int	count;

	count = hexlen(nb);
	if (nb >= 16)
	{
		ft_printex(nb / 16, symbol);
		ft_printex(nb % 16, symbol);
	}
	else
	{
		if (nb <= 9)
		{
			ft_putchar_fd((nb + '0'), 1);
		}
		else
		{
			if (symbol == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
			if (symbol == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
		}
	}
	return (count);
}
