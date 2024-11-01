/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/18 16:42:26 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/06/22 15:28:49 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static int	ft_ptrlen(uintptr_t a)
{
	int	count;

	count = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		count++;
		a /= 16;
	}
	return (count);
}

static void	ft_ptrs(uintptr_t a)
{
	ft_printex(a, 'x');
}

int	ft_ptr(long long a)
{
	if (a == 0)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	else
	{
		ft_putstr_fd("0x", 1);
		ft_ptrs((uintptr_t)a);
	}
	return (ft_ptrlen((uintptr_t)a) + 2);
}
