/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 12:07:02 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/03 16:01:00 by tbouder          ###   ########.fr       */
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

int	ft_finish_path(t_env *env, t_path *path)
{
	char	**str;

	str = ft_strsplit(path->path, ' ');
	if (!ft_strcmp(str[ft_dbstrlen(str) - 1], "ERROR"))
		return (0);
	else if (ft_strcmp(str[ft_dbstrlen(str) - 1], ft_find_end(env->rooms)->name))
		return (1);
	else
		return (2);
	ft_dbstrdel(str);
}

void	ft_algo(t_env *env)
{
	ft_putendl("\n");

	t_path	*path;
	int		nb;

	path = NULL;
	ft_pathsend(&path, ft_find_start(env->rooms)->name);
	ft_find_path(env, path);
	ft_putendl(path->path);
	while (path)
	{
		ft_putendl(path->path);
		nb = ft_finish_path(env, path);
		if (nb == 1)
			ft_printf("{y}A Completer{0}\n");
		if (nb == 2)
			ft_printf("{g}FINIIIIIIIIIIIT{0}\n");
		if (nb == 0)
			ft_printf("{r}Terminate him{0}\n");
		path = path->next;
	}
	// ft_print_path(path);
}
