/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 16:54:44 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/07/16 17:51:53 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*ss;
	size_t			i;

	i = 0;
	ss = malloc(nmemb * size);
	if (!ss)
		return (NULL);
	while (i < size * nmemb)
	{
		ss[i] = '\0';
		i++;
	}
	return (ss);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	char	*c;
	int		i;

	i = 0;
	c = ft_calloc(ft_strlen(s) + 1, sizeof(char));
	if (!c)
		return (NULL);
	while (s[i])
	{
		c[i] = s[i];
		i++;
	}
	c[i] = '\0';
	return (c);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*ss;
	int		i;
	int		j;

	i = 0;
	j = 0;
	ss = ft_calloc((ft_strlen(s1) + ft_strlen(s2) + 1), (sizeof(char)));
	if (!ss)
		return (NULL);
	while (s1[i])
	{
		ss[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		ss[i + j] = s2[j];
		j++;
	}
	ss[i + j] = '\0';
	return (ss);
}
