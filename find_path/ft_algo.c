/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/11 14:50:43 by tbouder          ###   ########.fr       */
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

 void	ft_verif_collision(t_path *path, t_path	*tmp)
{
	int		i;
	char	**s1;
	char	**s2;

	while (path)
	{
		ft_printf("{r}%s{0}\n", path->path);
		tmp = path->next;
		s1 = ft_strsplit(path->path, ' ');
		while (tmp)
		{
			i = 0;
			s2 = ft_strsplit(tmp->path, ' ');
			while (s1[i] && s2[i])
			{
				// while (ft_isstrstr(s1[i], s2[i]))
				if (ft_isstrstr(s1[i], s2[i]))
					tmp->path = ft_push_path(&tmp->path, "ERROR");
				i++;
			}
			tmp = tmp->next;
			ft_dbstrdel(s2);
		}
		ft_dbstrdel(s1);
		path = path->next;
	}
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

	ft_verif_same_path(origin);
	ft_verif_collision(origin, NULL);
	ft_path_remove_if_error(&origin, "ERROR");
	ft_putendl("----------");
	ft_print_path(origin);
	ft_putendl("----------\n");
	env->path = ft_strinit(origin->path);
	path = origin;
	while (path)
	{
		ft_strdel(&path->path);
		path = path->next;
	}
	ft_path_clear(&origin);
}
