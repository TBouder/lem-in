/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 19:11:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/09 22:02:00 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** Free env, free GNL
*/

static void	ft_destroy(t_path *path)
{
	if (path->next != NULL)
	{
		ft_strdel(&path->path);
		ft_destroy(path->next);
	}
	free(path);
}

static void	ft_free_env_pipes(t_pipes **pipes)
{
	t_pipes	*free_list;
	t_pipes	*temp;

	if (pipes != NULL)
	{
		free_list = *pipes;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			ft_strdel(&temp->id);
			free(temp);
		}
		*pipes = NULL;
	}
	pipes = NULL;
}

void		ft_free_env(t_env **env, int i)
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
			ft_free_env_pipes(&temp->pipes);
			ft_free_env_pipes(&temp->pipes_prev);
			free(temp);
		}
		(*env)->rooms = NULL;
	}
	(*env)->rooms = NULL;
	free(*env);
}

void		ft_clear_gnl(t_env *env)
{
	if (env && env->map)
	{
		ft_strdel(&env->buff);
		while (get_next_line(env->fd, &env->buff) == 1)
			ft_strdel(&env->buff);
		ft_strdel(&env->buff);
	}
}

void		ft_path_clear(t_path **begin_path)
{
	if (begin_path && *begin_path)
	{
		ft_strdel(&(*begin_path)->path);
		ft_destroy(*begin_path);
		*begin_path = NULL;
	}
}
