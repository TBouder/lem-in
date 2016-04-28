/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:11:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/28 15:19:35 by tbouder          ###   ########.fr       */
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

void		ft_free_all(t_env **env, int i)
{
	t_rooms	*free_list;
	t_rooms	*temp;

	ft_strdel(&(*env)->map);
	if (*env && i && (*env)->rooms != NULL)
	{
		free_list = (*env)->rooms;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			ft_strdel(&temp->name);
			ft_free_allp(&temp->pipes_next);
			ft_free_allp(&temp->pipes_prev);
			free(temp);
		}
		(*env)->rooms = NULL;
	}
	(*env)->rooms = NULL;
	free(*env);
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

void		ft_clear_gnl(t_env *env)
{
	ft_strdel(&env->buff);
	while (get_next_line(env->fd, &env->buff) == 1)
		ft_strdel(&env->buff);
	ft_strdel(&env->buff);
}
