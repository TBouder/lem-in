/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:51:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/09 17:08:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
While on est pas a room_end
	if il y a un seul pipe
		mettre la salle d'arrivee dans le chemin
		aller a la salle d'arrivee
	if il y a plusieurs pipes
		Enregistrer salle d'arrivee du premier pipe
		while il y a des pipes
			mettre la salle d'arrivee du premier pipe dans le chemin courant
			mettre les autres dans d'autres branches de la liste (non finie donc)
		aller a la salle d'arrivee du premier pipe
	if la salle est deja dans le chemin
		declarer le chemin invalide
		break

while il y a des chemins valides mais pas sur room_end
	aller a la premiere salle non finie et valide
	refaire l'operation de la premiere boucle while
*/

t_rooms	*ft_error_pipe(t_path *path)
{
	path->path = ft_push_path(&path->path, "ERROR");
	return (NULL);
}

t_rooms	*ft_one_pipe(t_env *env, t_path *path, t_pipes *pipe, t_rooms *rooms)
{
	t_rooms	*end_room;
	char	*r;
	char	**str;

	r = NULL;
	if (rooms->weight < ft_find_room_s(ROOMS, pipe->id)->weight)
	{
		path->path = ft_push_path(&path->path, ft_find_room(ROOMS, pipe)->name);
		path->moves += 1;
		str = ft_strsplit(path->path, ' ');
		r = ft_strinit(str[ft_dbstrlen(str) - 1]);
		ft_dbstrdel(str);
	}
	if (r)
	{
		end_room = ft_find_room_s(ROOMS, r);
		ft_strdel(&r);
		return (end_room);
	}
	else
		return (ft_error_pipe(path));
}

t_rooms	*ft_mult_pipe(t_env *env, t_path *path, t_pipes *pipes, t_rooms *rooms)
{
	t_rooms	*end_room;
	t_pipes	*r;
	char	*tmp;

	r = NULL;
	while (pipes)
	{
		if (rooms->weight < ft_find_room_s(ROOMS, pipes->id)->weight)
		{
			if (!ft_strstr(path->path, pipes->id) && path->moves_max < path->moves + 1)
			{
				tmp = ft_strinit(path->path);
				tmp = ft_push_path(&tmp, ft_find_room(ROOMS, pipes)->name);
				ft_pathsend(&path, tmp);
				!r ? r = pipes : 0;
				ft_strdel(&tmp);
			}
		}
		pipes = pipes->next;
	}
	if (r)
	{
		end_room = ft_one_pipe(env, path, r, rooms);
		// ft_strdel(&r);
		return (end_room);
	}
	else
		return (ft_error_pipe(path));
	// return (r ? ft_one_pipe(env, path, r, rooms) : ft_error_pipe(path));
}

void	ft_find_path(t_env *env, t_path *path)
{
	t_rooms *rooms;
	t_pipes *pipes;
	char 	*end;

	rooms = ft_find_room_s(ROOMS, path->path);
	end = ft_strinit(ft_find_end(ROOMS)->name);
	while (rooms && !ft_isstrstr(path->path, end))
	{
		pipes = rooms->pipes;
		if (ft_pipeslen(pipes) == 1)
			rooms = ft_one_pipe(env, path, rooms->pipes, rooms);
		else if (ft_pipeslen(pipes) > 1)
			rooms = ft_mult_pipe(env, path, rooms->pipes, rooms);
	}
	ft_strdel(&end);
}
