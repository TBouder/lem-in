/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:46:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 11:37:03 by tbouder          ###   ########.fr       */
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

static void	ft_free_env_hash(t_hroom **hash)
{
	t_hroom	*free_hash;
	t_hroom	*temp;
	t_hpipe	*free_pipe;
	t_hpipe	*pipe;

	if (hash != NULL)
	{
		free_hash = *hash;
		while (free_hash)
		{
			temp = free_hash;
			ft_strdel(&temp->id);
			pipe = temp->pipe;
			while (pipe)
			{
				free_pipe = pipe;
				pipe = pipe->next;
				free(free_pipe);
			}
			free_hash = free_hash->next;
			free(temp);
		}
		*hash = NULL;
	}
	hash = NULL;
}

static void	ft_free_hash(t_hroom **hash, int len)
{
	int		i;

	i = 0;
	if (hash)
	{
		while (i < len * 50)
		{
			if (hash[i])
			{
				ft_free_env_hash(&hash[i]);
				hash[i] = NULL;
				free(hash[i]);
			}
			i++;
		}
		free(hash);
	}
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
