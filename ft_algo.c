/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/03 11:00:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

char	*ft_push_path(char **s1, char *s2)
{
	char	*str;

	if (s1 != NULL)
	{
		str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 2);
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

void	ft_find_path(t_env *env, t_path *path, t_rooms *r, int i)
{
	t_pipes *tmp;
	char	**str;
	int		nb;


	while (1)
	{
		nb = 1;
		str = ft_strsplit(path->path, ' ');
		if (!ft_strcmp(str[ft_dbstrlen(str) - 1], ft_find_end(env->rooms)->name))
			break ;
		else
		{
			tmp = r->pipes_next;
			while (i-- > 0)
				tmp = tmp->next;
			if (!tmp || ft_strstr(path->path, ft_find_room(env->rooms, tmp)->name))
				break ;
			else if (ft_pipeslen(tmp) == 1)
			{
				// if (ft_strstr(path->path, ft_find_room(env->rooms, tmp)->name))
					// break ;
				path->path = ft_push_path(&path->path, ft_find_room(env->rooms, tmp)->name);
				r = ft_find_room(env->rooms, tmp);
			}
			else
			{
				while (nb++ < ft_pipeslen(tmp))
					ft_pathsend(&path, path->path);
				r = ft_find_room(env->rooms, tmp);
				path->path = ft_push_path(&path->path, ft_find_room(env->rooms, tmp)->name);
			}

		}
		ft_dbstrdel(str);
	}
}


void	ft_find_path_2(t_env *env, t_path *path, t_rooms *r, int i)
{
	t_pipes *tmp;
	char	**str;
	int		nb;


	while (1)
	{
		nb = 1;
		str = ft_strsplit(path->path, ' ');
		if (!ft_strcmp(str[ft_dbstrlen(str) - 1], ft_find_end(env->rooms)->name))
			break ;
		else
		{
			tmp = r->pipes_next;
			while (i-- > 0)
				tmp = tmp->next;
			if (!tmp || ft_strstr(path->path, ft_find_room(env->rooms, tmp)->name))
				break ;
			else if (ft_pipeslen(tmp) == 1)
			{
				// if (ft_strstr(path->path, ft_find_room(env->rooms, tmp)->name))
					// break ;
				path->path = ft_push_path(&path->path, ft_find_room(env->rooms, tmp)->name);
				r = ft_find_room(env->rooms, tmp);
			}
			else
			{
				while (nb++ < ft_pipeslen(tmp))
					ft_pathsend(&path, path->path);
				r = ft_find_room(env->rooms, tmp);
				path->path = ft_push_path(&path->path, ft_find_room(env->rooms, tmp)->name);
			}

		}
		ft_dbstrdel(str);
	}
}

void	ft_algo(t_env *env)
{
	ft_putendl("\n");

	t_path	*path;
	t_path	*tmp;
	// char	*best;

	path = NULL;
	ft_pathsend(&path, ft_find_start(env->rooms)->name);
	tmp = path;
	int	j = 0;
	while (tmp)
	{
		j = ft_pipeslen(ft_find_room_s(env->rooms, tmp->path)->pipes_next) - 1;
		ft_find_path_2(env, tmp, ft_find_room_s(env->rooms, tmp->path), j);
		// ft_find_path(env, tmp, ft_find_room(env->rooms, );
		tmp = tmp->next;
	}


	ft_print_path(path);
}
