/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:20:47 by qmarowak          #+#    #+#             */
/*   Updated: 2020/11/09 12:14:08 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	ft_unset(t_env *env, char **option)
{
	int		i;

	i = 0;
	while (option[i])
	{
		if (check_value_env(option[i]) || option[i][0] == '=')
		{
			ft_error(option[i], "unset", ERROR_EXPORT, env->fd_write);
			i++;
			continue ;
		}
		if (presence_env(env, option[i]) != -1)
		{
			env->envp =
			delete_element_mas(env->envp, --env->size_envp, option[i]);
		}
		i++;
	}
}
