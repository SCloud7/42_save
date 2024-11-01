/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssoukoun <ssoukoun@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 10:52:55 by ssoukoun          #+#    #+#             */
/*   Updated: 2024/10/31 11:48:03 by ssoukoun         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H
# include "./lib/libft.h"

char	**findpath(char **env);
void	cas(char *ar, char **env);
void	ex(char *args, char **env);
int		ft_strnstri(const char *haystack, const char *needle, size_t len);
void	free_tab(char **tab);
int		lefork(void);
int		c_and_w(int *pipefd, int *id, int status);

#endif