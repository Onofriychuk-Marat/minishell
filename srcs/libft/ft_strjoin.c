/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/03 12:32:42 by utoomey           #+#    #+#             */
/*   Updated: 2020/11/09 12:31:25 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_strjoin(char *s1, char *s)
{
	int		i;
	int		k;
	char	*new;

	i = 0;
	k = 0;
	if (!(new = (char*)malloc(sizeof(char) *
	(ft_strlen((char*)s1) + ft_strlen((char*)s) + 1))))
		return (NULL);
	while (s1 && *(s1 + i))
	{
		*(new + i) = *(s1 + i);
		i++;
	}
	while (s && *(s + k))
	{
		*(new + i + k) = *(s + k);
		k++;
	}
	*(new + i + k) = '\0';
	if (s1 != NULL)
		free(s1);
	if (s != NULL)
		free(s);
	return (new);
}
