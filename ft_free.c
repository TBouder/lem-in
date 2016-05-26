/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:46:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 15:22:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_destroy(t_path *path)
{
	if (path->next != NULL)
	{
		ft_strdel(&path->path);
		ft_destroy(path->next);
	}
	free(path);
}

static void	ft_path_clear(t_path **begin_path)
{
	if (begin_path && *begin_path)
	{
		ft_strdel(&(*begin_path)->path);
		ft_destroy(*begin_path);
		*begin_path = NULL;
	}
}

static void	ft_free_path(t_path *path, t_env **env)
{
	while (path)
	{
		ft_strdel(&path->path);
		path = path->next;
	}
	ft_path_clear(&(*env)->paths);
}

static void	ft_free_map(t_env **env)
{
	int		i;

	i = 0;
	while (i < (*env)->map_id)
	{
		ft_strdel(&(*env)->map[i]);
		i++;
	}
	free((*env)->map);
}

void		ft_free_env(t_env **env, int i)
{
	ft_strdel(&(*env)->buff);
	ft_strdel(&(*env)->null);
	ft_free_map(env);
	ft_free_hash((*env)->hash, (*env)->room_len);
	ft_free_hash((*env)->hash_coo, (*env)->room_len);
	i == 1 || i == 0 ? ft_free_path((*env)->paths, env) : 0;
	free(*env);
}
