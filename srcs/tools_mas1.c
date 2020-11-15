/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_mas1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: utoomey <utoomey@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 10:20:04 by qmarowak          #+#    #+#             */
/*   Updated: 2020/10/29 20:41:31 by utoomey          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void	free_mas(char **mas)
{
	int i;

	i = -1;
	while (mas[++i])
	{
		free(mas[i]);
	}
	free(mas);
}

char	**copy_mas(char **mas, int count_add, char *str)
{
	int		i;
	char	**new;

	i = -1;
	new = (char**)malloc(sizeof(char*) * (count_add + 1));
	while (++i < count_add)
		new[i] = ft_strdup(mas[i]);
	new[i] = NULL;
	return (new);
}

char	**add_element_mas(char **mas, int count_add, char *str)
{
	char	**new;
	int		i;

	i = -1;
	new = (char**)malloc(sizeof(char*) * (count_add + 1));
	while (++i < count_add - 1)
		new[i] = ft_strdup(mas[i]);
	new[count_add - 1] = ft_strdup(str);
	new[count_add] = NULL;
	free_mas(mas);
	return (new);
}

char	*replace_element(char *str, char *new)
{
	free(str);
	return (ft_strdup(new));
}

char	**delete_element_mas(char **mas, int count_add, char *str)
{
	char	**new;
	int		i;
	int		k;

	i = 0;
	k = 0;
	new = (char**)malloc(sizeof(char*) * (count_add + 1));
	while (i < count_add)
	{
		if (!ft_strcmp_env(mas[k], str))
			i--;
		else
			new[i] = ft_strdup(mas[k]);
		k++;
		i++;
	}
	new[count_add] = NULL;
	free_mas(mas);
	return (new);
}
