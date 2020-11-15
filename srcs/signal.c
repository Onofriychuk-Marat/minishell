/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.21-school.ru>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:13:53 by utoomey           #+#    #+#             */
/*   Updated: 2020/10/13 13:41:21 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	ctrl_c(int sig)
{
	write(1, "\b\b  \b\b", 6);
	if (g_flag_start)
	{
		g_flag_errno = 130;
	}
	else
	{
		errno = 1;
		ft_putstr_fd("\n︻┻┳══━一 ", 1);
	}
}

void	ctrl_slash(int sig)
{
	write(1, "\b\b  \b\b", 6);
	if (g_flag_start)
	{
		g_flag_errno = 131;
		ft_putendl_fd("^\\Quit: 3", 1);
	}
}
