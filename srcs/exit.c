/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:19:32 by qmarowak          #+#    #+#             */
/*   Updated: 2020/10/28 11:19:39 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ft_exit(t_env *env, int code_error)
{
	free(env->home);
	if (env->path)
		free_mas(env->path);
	if (env->envp)
		free_mas(env->envp);
	exit(code_error);
}
