/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:19:23 by qmarowak          #+#    #+#             */
/*   Updated: 2020/10/13 19:05:18 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	init_env(t_env *env, char **envp)
{
	int	i;

	i = -1;
	signal(SIGINT, ctrl_c);
	signal(SIGQUIT, ctrl_slash);
	while (envp[++i])
	{
		if (!ft_strncmp(envp[i], "HOME=", 5))
			env->home = ft_strdup(envp[i] + 5);
		else if (!ft_strncmp(envp[i], "PATH=", 5))
			env->path = ft_split(envp[i] + 5, ':');
		else if (!ft_strncmp(envp[i], "OLDPWD=", 7))
			envp[i][6] = '\0';
	}
	env->size_envp = i;
	env->envp = copy_mas(envp, env->size_envp, NULL);
	env->fd_write = dup(1);
	env->fd_read = dup(0);
}
