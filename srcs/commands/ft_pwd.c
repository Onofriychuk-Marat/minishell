/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qmarowak <qmarowak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:20:42 by qmarowak          #+#    #+#             */
/*   Updated: 2020/10/13 10:20:43 by qmarowak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./../header.h"

void	ft_pwd(void)
{
	char dir[300];

	getcwd(dir, 300);
	ft_putendl_fd(dir, 1);
}