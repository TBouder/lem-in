/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/03 16:57:23 by tbouder          ###   ########.fr       */
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

void	ft_finish_path(t_env *env, t_path *path)
{
	char	**str;

	str = ft_strsplit(path->path, ' ');
	if (!ft_strcmp(str[ft_dbstrlen(str) - 1], "ERROR"))
		;
	else if (ft_strcmp(str[ft_dbstrlen(str) - 1], ft_find_end(env->rooms)->name))
		ft_find_path(env, path);
	else
		;
	ft_dbstrdel(str);
}

void	ft_algo(t_env *env)
{
	ft_putendl("\n");

	t_path	*path;
	t_path	*origin;

	path = NULL;
	ft_pathsend(&path, ft_find_start(env->rooms)->name);
	origin = path;
	ft_find_path(env, path);
	ft_putendl(path->path);
	ft_putendl("-----------------------------------------------------------------");
	ft_putendl("-----------------------------------------------------------------");
	ft_putendl("-----------------------------------------------------------------");
	path = path->next;

	while (path)
	{
		ft_finish_path(env, path);
		path = path->next;
	}
	path = origin;
	ft_putendl("-----------------------------------------------------------------");
	ft_putendl("-----------------------------------------------------------------");
	ft_putendl("-----------------------------------------------------------------");
	ft_print_path(path);
}
