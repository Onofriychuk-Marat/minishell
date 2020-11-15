/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_env.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:13:31 by utoomey           #+#    #+#             */
/*   Updated: 2020/11/11 10:44:31 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int		ft_strcmp_env(char *str, char *key)
{
	int		size_1;
	int		size_2;
	char	*p1;
	char	*p2;

	p1 = ft_strchr(key, '=');
	p2 = ft_strchr(str, '=');
	size_1 = (p1) ? p1 - key : ft_strlen(key);
	size_2 = (p2) ? p2 - str : ft_strlen(str);
	size_1 = size_1 < size_2 ? size_2 : size_1;
	if (!ft_strncmp(str, key, size_1))
		return (0);
	return (1);
}

int		presence_env(t_env *env, char *str)
{
	int		i;

	i = -1;
	while (env->envp[++i])
		if (!ft_strcmp_env(env->envp[i], str))
			return (i);
	return (-1);
}

char	*get_value_env(t_env *env, char *str)
{
	int		i;
	char	*equally;

	i = presence_env(env, str);
	if (i == -1)
		return (NULL);
	else if (i == -1 || !(equally = ft_strchr(env->envp[i], '=')))
		return (ft_strdup(""));
	return (ft_strdup(++equally));
}

void	add_env(t_env *env, char **variables)
{
	int		check;
	int		i;

	i = -1;
	while (variables[++i])
	{
		check = check_env(env, variables[i]);
		if (check == -1)
		{
			ft_error(variables[i], "export", ERROR_EXPORT, env->fd_write);
			continue ;
		}
		else if (check == -2)
			env->envp = add_element_mas(env->envp, ++env->size_envp,
			variables[i]);
		else if (check >= 0 && ft_strchr(variables[i], '='))
			env->envp[check] = replace_element(env->envp[check], variables[i]);
	}
}
