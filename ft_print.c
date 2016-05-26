/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_TEMP.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:36:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 15:52:22 by tbouder          ###   ########.fr       */
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
