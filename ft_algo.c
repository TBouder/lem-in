/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/09 17:31:33 by tbouder          ###   ########.fr       */
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

//------------------------------------------------------------//

void ft_path_remove_if_error(t_path **begin_path, char *str)
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



static void		ft_destroy(t_path *path)
{
	if (path->next != NULL)
	{
		ft_strdel(&path->path);
		ft_destroy(path->next);
	}
	free(path);
}

void			ft_path_clear(t_path **begin_path)
{
	if (begin_path && *begin_path)
	{
		ft_strdel(&(*begin_path)->path);
		ft_destroy(*begin_path);
		*begin_path = NULL;
	}
}

//------------------------------------------------------------//

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
	ft_putendl("\n");

	t_path	*path;
	t_path	*origin;
	int		len;

	path = NULL;
	ft_pathsend(&path, ft_find_start(ROOMS)->name); // on met la premiere salle dans la liste
	origin = path;

	ft_find_path(env, path); //On cherche le meilleur chemin, un passage
	len = ft_found_less_path(origin, env); // On recup la len max
	ft_put_max_path(origin, len); // On met la len max partout

	while (path)
	{
		ft_find_path(env, path);
		len = ft_found_less_path(origin, env); // On recup la len max
		ft_put_max_path(origin, len); // On met la len max partout
		path = path->next;
	}

	path = origin;
	ft_verif_same_path(path);
	ft_path_remove_if_error(&path, "ERROR");
	ft_print_path(path);

	ft_path_clear(&path);
}
