/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:51:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 16:57:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"
#define SROOMS static t_rooms
#define SAME ft_isstrstr
#define PATH path->path

SROOMS	*ft_error_pipe(t_path *path)
{
	PATH = ft_push_path(&PATH, "LERR");
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
		PATH = ft_push_path(&PATH,
			ft_find_room(ROOMS, pipe->id)->name);
		path->moves += 1;
		str = ft_strsplit(PATH, ' ');
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
	t_pipes	*p;
	char	*tmp;

	p = NULL;
	while (pipes)
	{
		if (rooms->weight < ft_find_room(ROOMS, pipes->id)->weight
			|| SAME(ft_find_room(ROOMS, pipes->id)->name, END->name))
		{
			if ((!SAME(PATH, pipes->id) && path->moves_max < path->moves + 1)
				|| (!SAME(PATH, END->name) && path->moves_max > path->moves))
			{
				tmp = ft_strinit(PATH);
				tmp = ft_push_path(&tmp, ft_find_room(ROOMS, pipes->id)->name);
				ft_pathsend(&path, tmp);
				!p ? p = pipes : 0;
				ft_strdel(&tmp);
			}
		}
		pipes = pipes->next;
	}
	p ? end_room = ft_one_pipe(env, path, p, rooms) : 0;
	return (p ? end_room : ft_error_pipe(path));
}

void	ft_find_path(t_env *env, t_path *path)
{
	t_rooms *rooms;
	t_pipes *pipes;
	char	*end;

	rooms = ft_find_room(ROOMS, PATH);
	end = ft_strinit(END->name);
	while (rooms && !SAME(PATH, end))
	{
		pipes = rooms->pipes;
		if (ft_pipeslen(pipes) == 1)
			rooms = ft_one_pipe(env, path, rooms->pipes, rooms);
		else if (ft_pipeslen(pipes) > 1)
			rooms = ft_mult_pipe(env, path, rooms->pipes, rooms);
	}
	ft_strdel(&end);
}
