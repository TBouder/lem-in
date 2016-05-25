/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 15:09:41 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 22:20:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

void		ft_path_remove_if_error(t_path **begin_path, char *str)
{
	t_path		*to_free;

	if (begin_path && *begin_path)
	{
		if (ft_isstrstr((*begin_path)->path, str))
		{
			to_free = *begin_path;
			*begin_path = (*begin_path)->next;
			ft_strdel(&to_free->path);
			free(to_free);
			ft_path_remove_if_error(begin_path, str);
		}
		else
			ft_path_remove_if_error(&(*begin_path)->next, str);
	}
}

static void			ft_verif_col_helper(t_env *env, t_path *origin, t_path *tmp)
{
	int		i;
	char	**s1;
	char	**s2;

	tmp = origin->next;
	s1 = ft_strsplit(origin->path, ' ');
	while (tmp)
	{
		i = 1;
		s2 = ft_strsplit(tmp->path, ' ');
		while (s1[i] && s2[i])
		{
			if (EQU(s1[i], s2[i]) && !(EQU(s1[i], env->r_end->id)
				|| EQU(s2[i], env->r_end->id)))
				tmp->path = ft_push_path(&tmp->path, "LERR");
			i++;
		}
		tmp = tmp->next;
		ft_dbstrdel(s2);
	}
	ft_dbstrdel(s1);
}

static void			ft_verif_collision(t_env *env, t_path *path)
{
	t_path	*origin;

	origin = path;
	while (origin)
	{
		if (!ft_strstr(origin->path, "LERR")
			&& ft_strstr(origin->path, env->r_end->id))
			ft_verif_col_helper(env, origin, NULL);
		origin = origin->next;
	}
}

static t_path		*ft_algo(t_env *env)
{
	t_path	*origin;
	t_path	*path;

	path = NULL;
	ft_pathsend(&path, env->r_start->id);
	origin = path;
	while (path)
	{
		ft_find_path(env, path);
		if (path->next == NULL)
			break ;
		path = path->next;
	}
	return (origin);
}

void				ft_find(t_env *env)
{
	env->r_start->weight = 0;
	ft_weight(env, env->r_start, 0, NULL);
	if (env->r_end->weight == -1)
		ft_err_nopath(env, "Pipe {9}error{0} : no access to end room");
	env->paths = ft_algo(env);
	ft_verif_collision(env, env->paths);
	ft_path_remove_if_error(&env->paths, "LERR");
}
