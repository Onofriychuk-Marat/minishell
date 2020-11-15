/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:20:33 by qmarowak          #+#    #+#             */
/*   Updated: 2020/11/08 16:33:20 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	ft_putenv(t_env *env, int *sort, int k)
{
	int		size_key;
	char	*equally;

	ft_putstr_fd("declare -x ", 1);
	if ((equally = ft_strchr(env->envp[sort[k]], '=')))
	{
		size_key = equally - env->envp[sort[k]] + 1;
		write(1, env->envp[sort[k]], size_key);
		write(1, "\"", 1);
		ft_putstr_fd(env->envp[sort[k]] + size_key, 1);
		ft_putendl_fd("\"", 1);
	}
	else
		ft_putendl_fd(env->envp[sort[k]], 1);
}

void	ft_export(t_env *env, char **option)
{
	int		k;
	int		*sort;

	k = 0;
	if (*option)
		add_env(env, option);
	else
	{
		sort = (int*)malloc(sizeof(int) * env->size_envp);
		sort_env(env, sort);
		while (k < env->size_envp)
			ft_putenv(env, sort, k++);
		free(sort);
	}
}
