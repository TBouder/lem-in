/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 11:47:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"


char	*ft_push_path(char **s1, char *s2)
{
	char	*str;

	if (s1 != NULL)
	{
		str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1);
		ft_strcpy(str, *s1);
		ft_strcat(str, " ");
		ft_strcat(str, s2);
		ft_strdel(s1);
	}
	else
	{
		str = ft_strinit(s2);
		ft_strdel(s1);
	}
	return (str);
}

void	ft_finish_path(t_env *env, t_path *path)
{
	char	**str;

	str = ft_strsplit(path->path, ' ');
	if (ft_strcmp(str[ft_dbstrlen(str) - 1], ft_find_end(ROOMS)->name))
		ft_find_path(env, path);
	ft_dbstrdel(str);
}

void	ft_verif_same_path(t_path *path)
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
			if (ft_strcmp(start->path, mv->path) == 0)
				mv->path = ft_push_path(&mv->path, "ERROR");
			mv = mv->next;
		}
		start = start->next;
	}
}

void	ft_put_max_path(t_path *begin_path, int i)
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

int		ft_found_less_path(t_path *path, t_env *env)
{
	t_path	*tmp;
	int		i;

	tmp = path;
	i = 0;
	while (tmp)
	{
		if (tmp->moves < i || i == 0)
		{
			if (ft_isstrstr(tmp->path, ft_find_end(ROOMS)->name))
				i = tmp->moves;
		}
		tmp = tmp->next;
	}
	return (i);
}

void	ft_algo(t_env *env)
{
	t_path	*path;
	t_path	*origin;

	path = NULL;
	ft_pathsend(&path, ft_find_start(ROOMS)->name); // on met la premiere salle dans la liste
	origin = path;

	while (path)
	{
		ft_find_path(env, path); //On cherche le meilleur chemin
		ft_put_max_path(origin, ft_found_less_path(origin, env)); // On met la len max partout
		path = path->next;
	}
	path = origin;
	ft_verif_same_path(path);
	ft_path_remove_if_error(&path, "ERROR");
	// ft_print_path(path);
	env->path = ft_strinit(path->path);
	ft_path_clear(&path);
}
