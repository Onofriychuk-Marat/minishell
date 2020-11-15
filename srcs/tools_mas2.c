/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mas2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:20:09 by qmarowak          #+#    #+#             */
/*   Updated: 2020/10/29 15:32:24 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	replace_line(char *mas, char old, char ch)
{
	int		k;

	k = -1;
	while (mas[++k])
	{
		if (mas[k] == old)
			mas[k] = ch;
	}
}

void	replace_mas(char **mas, char old, char ch)
{
	int		i;
	int		k;

	i = -1;
	while (mas[++i])
		replace_line(mas[i], old, ch);
}
