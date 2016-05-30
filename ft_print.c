/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:36:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 14:44:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_print_map(t_env *env)
{
	int		i;

	i = 0;
	while (i < env->map_id)
	{
		ft_putendl(env->map[i]);
		i++;
	}
	ft_putchar('\n');
}

void	ft_print_path(t_env *env)
{
	t_path	*path;

	path = env->paths;
	while (path)
	{
		if (!ft_strstr(path->path, "LERR")
			&& ft_strstr(path->path, env->r_end->id))
			ft_putendl(path->path);
		path = path->next;
	}
	ft_putchar('\n');
}

void	ft_print_path_dist(t_env *env, int *dist)
{
	t_path	*path;
	int		i;

	path = env->paths;
	i = 0;
	while (path)
	{
		if (dist[i] == -42)
			i++;
		if (!ft_strstr(path->path, "LERR")
			&& ft_strstr(path->path, env->r_end->id))
		{
			ft_printf("%s : %d units\n", path->path, dist[i]);
			i++;
		}
		path = path->next;
	}
	ft_putchar('\n');
}
