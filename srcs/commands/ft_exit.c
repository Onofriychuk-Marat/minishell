/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:13:13 by utoomey           #+#    #+#             */
/*   Updated: 2020/11/08 17:33:01 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

int		check_two(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (i > 18 ? 1 : 0);
}

void	ft_exitfunc(t_env *env, char **option)
{
	int i;

	i = -1;
	env->flag_exit = 1;
	if (option[0])
	{
		if (check(option[0], ft_isdigit, '\0') || check_two(option[0]))
		{
			ft_error("exit", option[0], ERROR_NUMERIC_ARGV, env->fd_write);
			return ;
		}
		else if (option[1])
		{
			env->flag_exit = 0;
			ft_error("exit", NULL, ERROR_MANY_ARGV, env->fd_write);
			return ;
		}
		else
			errno = ft_atoi(option[0]);
	}
	if (env->count_pipe == 1)
		ft_putendl_fd("exit", env->fd_write);
}
