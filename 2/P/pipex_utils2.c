/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:32:19 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/10/31 14:15:49 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./lib/libft.h"
#include "pipex.h"

void	ex(char *args, char **env)
{
	char	**paths;
	char	**argss;
	int		i;
	char	*cmd;
	char	*tmp;

	i = -1;
	paths = findpath(env);
	argss = ft_split(args, ' ');
	cas(args, env);
	while (paths && paths[++i])
	{
		tmp = ft_strjoin(paths[i], "/");
		cmd = ft_strjoin(tmp, argss[0]);
		free(tmp);
		if (access(cmd, X_OK | F_OK) == 0)
		{
			free_tab(paths);
			execve(cmd, argss, env);
		}
		free(cmd);
	}
	free_tab(paths);
	free_tab(argss);
}

void	cas(char *ar, char **env)
{
	char	**argss;

	if (*ar == '/')
	{
		argss = ft_split(ar, ' ');
		if (access(ar, X_OK | F_OK) == 0)
			execve(argss[0], argss, env);
		free_tab(argss);
	}
}

char	**findpath(char **env)
{
	int		i;
	char	**paths;
	char	*line;

	i = 0;
	while (env[i])
	{
		if (ft_strnstri(env[i], "PATH", 4) == 1)
		{
			line = ft_substr(env[i], 5, ft_strlen(env[i]));
			free(line);
			paths = ft_split(env[i], ':');
			return (paths);
		}
		i++;
	}
	return (NULL);
}
