/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/11 13:28:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

static void	ft_verif_same_path(t_path *path)
{
	t_path	*o;
	t_path	*start;
	t_path	*mv;

	start = path;
	o = path;
	while (start)
	{
		mv = start->next;
		while (mv)
		{
			if (ft_strequ(start->path, mv->path))
				mv->path = ft_push_path(&mv->path, "ERROR");
			mv = mv->next;
		}
		start = start->next;
	}
}

static void	ft_put_max_path(t_path *begin_path, int i)
{
	t_path	*path;

	path = begin_path;
	while (path && path->next)
	{
		path->moves_max = i;
		if (path->next)
			path = path->next;
	}
}

static int	ft_found_less_path(t_path *path, t_env *env)
{
	t_path	*tmp;
	int		i;

	tmp = path;
	i = 0;
	while (tmp)
	{
		if (tmp->moves < i || i == 0)
		{
			if (ft_isstrstr(tmp->path, env->end->name))
				i = tmp->moves;
		}
		tmp = tmp->next;
	}
	return (i);
}

void		ft_algo(t_env *env)
{
	t_path	*path;
	t_path	*origin;

	path = NULL;
	ft_pathsend(&path, ft_find_start(ROOMS)->name);
	origin = path;
	while (path)
	{
		ft_find_path(env, path);
		ft_put_max_path(origin, ft_found_less_path(origin, env));
		if (path->next == NULL)
			break ;
		path = path->next;
	}
	path = origin;
	ft_verif_same_path(path);
	ft_path_remove_if_error(&path, "ERROR");
	// ft_putendl("----------");
	// ft_print_path(origin);
	// ft_putendl("----------\n");
	env->path = ft_strinit(path->path);
	ft_path_clear(&path);
}
