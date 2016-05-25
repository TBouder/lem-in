/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FT_TEMP.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:36:46 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 18:26:33 by tbouder          ###   ########.fr       */
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

void	ft_print_map_pipes(t_env *env)
{
	int		j;
	t_hroom	*room;
	t_hpipe	*pipe;

	j = 0;
	while (j < env->room_len * 50)
	{
		if (env->hash[j] == NULL)
			j++;
		else
		{
			room = env->hash[j];
			while (room)
			{
				ft_printf("Room : [{154}%s{0}]", room->id);
				if (room->pipe)
					ft_printf("\t =>");
				pipe = room->pipe;
				while (pipe)
				{
					ft_putstr("\t");
					ft_printf("[{141}%s{0}]", pipe->room->id);
					pipe = pipe->next;
				}
				ft_putchar('\n');
				room = room->next;
			}
			j++;
		}
	}
}

void	ft_print_map_weight(t_env *env)
{
	int		j = 0;
	// ft_printf("Room : [{154}%s{0}] [{122}%d{0}]\n", env->r_end->id, env->r_end->weight);

	while (j < env->room_len * 50)
	{
		if (env->hash[j] == NULL)
			j++;
		else
		{
			while (env->hash[j] && env->hash[j]->weight != -1)
			{
				ft_printf("Room : [{154}%s{0}] [{122}%d{0}]", env->hash[j]->id, env->hash[j]->weight);
				if (env->hash[j]->pipe)
					ft_printf("\t =>");
				while (env->hash[j]->pipe)
				{
					ft_putstr("\t");
					ft_printf("[{141}%s{0}] [{122}%d{0}]", env->hash[j]->pipe->room->id, env->hash[j]->pipe->room->weight);
					env->hash[j]->pipe = env->hash[j]->pipe->next;
				}
				ft_putchar('\n');
				env->hash[j] = env->hash[j]->next;
			}
			j++;
		}
	}
}

void	ft_print_path(t_env *env)
{
	t_path	*path;

	path = env->paths;
	while (path)
	{
		if (!ft_strstr(path->path, "LERR") && ft_strstr(path->path, env->r_end->id))
			ft_putendl(path->path);
		path = path->next;
	}
	ft_putchar('\n');
}
