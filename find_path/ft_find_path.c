/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:51:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/11 12:47:57 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

#define SROOMS static t_rooms

// void ft_remove_path_one(t_path *begin_path)
// {
// 	t_path		*to_free;
// 	//
// 	// if (begin_path && *begin_path && (*begin_path)->next)
// 	// 	ft_remove_path_one(&(*begin_path)->next);
// 	// else
// 	// {
// 		to_free = *begin_path;
// 		*begin_path = (*begin_path)->next;
// 		ft_strdel(&to_free->path);
// 		free(to_free);
// 	// }
// }

SROOMS	*ft_error_pipe(t_path *path)
{
	path->path = ft_push_path(&path->path, "ERROR");
	return (NULL);
}

SROOMS	*ft_one_pipe(t_env *env, t_path *path, t_pipes *pipe, t_rooms *rooms)
{
	t_rooms	*end_room;
	char	*r;
	char	**str;

	r = NULL;
	if (rooms->weight < ft_find_room(ROOMS, pipe->id)->weight)
	{
		path->path = ft_push_path(&path->path, ft_find_room(ROOMS, pipe->id)->name);
		path->moves += 1;
		str = ft_strsplit(path->path, ' ');
		r = ft_strinit(str[ft_dbstrlen(str) - 1]);
		ft_dbstrdel(str);
	}
	if (r)
	{
		end_room = ft_find_room(ROOMS, r);
		ft_strdel(&r);
		return (end_room);
	}
	else
		return (ft_error_pipe(path));
}

SROOMS	*ft_mult_pipe(t_env *env, t_path *path, t_pipes *pipes, t_rooms *rooms)
{
	t_rooms	*end_room;
	t_pipes	*r;
	char	*tmp;

	r = NULL;
	while (pipes)
	{
		if (rooms->weight < ft_find_room(ROOMS, pipes->id)->weight)
		{
			ft_printf("{r}%d{0} vs {b}%d{0}\n", path->moves_max, path->moves + 1);
			if ((ft_isstrstr(path->path, pipes->id) == 0 && path->moves_max < path->moves + 1) || (!ft_isstrstr(path->path, env->end->name) && path->moves_max > path->moves + 1))
			{
				tmp = ft_strinit(path->path);
				tmp = ft_push_path(&tmp, ft_find_room(ROOMS, pipes->id)->name);
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
		return (end_room);
	}
	else
		return (ft_error_pipe(path));
}

void	ft_find_path(t_env *env, t_path *path, t_path *origin)
{
	t_rooms *rooms;
	t_pipes *pipes;
	char 	*end;

	rooms = ft_find_room(ROOMS, path->path);
	end = ft_strinit(env->end->name);
	while (rooms && !ft_isstrstr(path->path, end))
	{
		pipes = rooms->pipes;
		if (ft_pipeslen(pipes) == 1)
			rooms = ft_one_pipe(env, path, rooms->pipes, rooms);
		else if (ft_pipeslen(pipes) > 1)
			rooms = ft_mult_pipe(env, path, rooms->pipes, rooms);
	}
	ft_strdel(&end);

	ft_path_remove_if_error(&origin, "ERROR");

}
