/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_path.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/03 11:51:37 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 22:35:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"
#define SAME ft_isstrstr
#define PATH path->path

static t_hroom	*ft_error_pipe(t_path *path)
{
	PATH = ft_push_path(&PATH, "LERR");
	return (NULL);
}

static t_hroom	*ft_one_pipe(t_env *env, t_path *path, t_hpipe *pipe, t_hroom *room)
{
	t_hroom	*tmp;
	t_hroom	*end_room;
	char	*r;
	char	**str;

	end_room = NULL;
	pipe = NULL;
	// tmp = ft_find_room(env, pipe->room->id);
	tmp = ft_find_good_pipe(room);
	// ft_putendl(tmp->id);
	if (EQU(tmp->id, env->r_end->id))
		return (env->r_end);
	if (room->weight < tmp->weight)
	{
		PATH = ft_push_path(&PATH, tmp->id);
		path->moves += 1;
		str = ft_strsplit(PATH, ' ');
		r = ft_strinit(str[ft_dbstrlen(str) - 1]);
		end_room = env->hash[ft_hash_djbtwo(r, env->room_len)];
		// ft_printf("{32}%s{0} vs {49}%s{0}\n", end_room->id, r);
		while (CMP(end_room->id, r))
		{
			// ft_putendl("YEYGUWFGHUREGHFJK\n\n\n\ndyuewgfgheuj");
			// ft_printf("{32}%s{0} vs {49}%s{0}\n", end_room->id, r);
			end_room = end_room->next;
		}
		// if (end_room->next)
		ft_strdel(&r);
		ft_dbstrdel(str);
	}
	return (end_room ? end_room : ft_error_pipe(path));
}

static t_hroom	*ft_mult_pipe(t_env *env, t_path *path, t_hpipe *pipe,
	t_hroom *room)
{
	t_hroom	*tmp;
	t_hroom	*end_room;
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (pipe)
	{
		tmp = ft_find_room(env, pipe->room->id);
		if (EQU(tmp->id, env->r_end->id))
			return (env->r_end);
		// if ((room->weight < tmp->weight || SAME(tmp->id, env->r_end->id)) && (!SAME(PATH, pipe->room->id) || !SAME(PATH, env->r_end->id)))
		if (room->weight < tmp->weight)
		{
			str = ft_strinit(PATH);
			str = ft_push_path(&str, tmp->id);
			i ? ft_pathsend(&path, str) : 0;
			!j ? j++ : 0;
			ft_strdel(&str);
			end_room = ft_find_room(env, room->id);
		}
		i++;
		pipe = pipe->next;
	}
	j ? end_room = ft_one_pipe(env, path, pipe, room) : 0;
	// ft_printf("{9}%s{0} : ", room->id);
	// ft_printf("{155}%s{0} OR ", end_room->id);
	// ft_printf("{155}%s{0}\n", PATH);

	return (j ? end_room : ft_error_pipe(path));
}

void			ft_find_path(t_env *env, t_path *path)
{
	t_hroom *current;
	t_hpipe *pipe;

	current = ft_find_room(env, PATH);
	while (current && CMP(current->id, env->r_end->id))
	{
		current = ft_find_room(env, PATH);
		pipe = current->pipe;
		while (pipe && pipe->room->weight < current->weight)
			pipe = pipe->next;
		// if (ft_hpipelen(current) == 1)
		// 	current = ft_one_pipe(env, path, pipe, current);
		// else
		if (ft_hpipelen(current) >= 1)
			current = ft_mult_pipe(env, path, pipe, current);
		else
			current = ft_error_pipe(path);
	}
	if (current && EQU(current->id, env->r_end->id))
		PATH = ft_push_path(&PATH, env->r_end->id);
}
