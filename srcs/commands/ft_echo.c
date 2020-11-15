/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:13:05 by utoomey           #+#    #+#             */
/*   Updated: 2020/11/07 21:02:01 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

int		is_param(char *str)
{
	int	size;

	size = ft_strlen(str);
	if (size < 2)
		return (0);
	if (str[0] != '-' || str[1] != 'n')
		return (0);
	size -= 2;
	str += 2;
	while (size--)
		if (*str++ != 'n')
			return (0);
	return (1);
}

void	ft_echo(t_env *env, char **option)
{
	int flag;
	int	flag_2;
	int i;

	flag = 1;
	flag_2 = 0;
	i = 0;
	while (option[i])
	{
		if (flag && is_param(option[i]))
			flag_2 = 1;
		else
		{
			flag = 0;
			ft_putstr_fd(option[i], 1);
			if (option[i + 1])
				ft_putchar_fd(' ', 1);
		}
		i++;
	}
	if (!flag_2 && env->fd != -2)
		ft_putchar_fd('\n', 1);
}
