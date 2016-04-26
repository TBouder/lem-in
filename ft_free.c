/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:11:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 19:13:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_free_allp(t_pipes **env)
{
	t_pipes	*free_list;
	t_pipes	*temp;

	if (env != NULL)
	{
		free_list = *env;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			ft_strdel(&temp->id);
			free(temp);
		}
		*env = NULL;
	}
	env = NULL;
}

void		ft_free_all(t_rooms **env)
{
	t_rooms	*free_list;
	t_rooms	*temp;

	if (env != NULL)
	{
		free_list = *env;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			ft_strdel(&temp->name);
			ft_free_allp(&temp->pipes_next);
			ft_free_allp(&temp->pipes_prev);
			free(temp);
		}
		*env = NULL;
	}
	env = NULL;
}

void		ft_freesplit(char **str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
}
