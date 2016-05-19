/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:34:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 18:09:39 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

////
void		ft_print_infos(t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		ft_printf("{g}%s (%d) {0} : {145}%d{0}\n", tmp->name, tmp->id, tmp->weight);
		while (tmp->pipes)
		{
			ft_printf("\t{100}Next pipe{0} : %s\n", tmp->pipes->id);
			tmp->pipes = tmp->pipes->next;
		}
		tmp = tmp->next;
	}
}


void		ft_find(t_env *env)
{
	env->start = ft_find_start(ROOMS);
	END = ft_find_end(ROOMS);
	ft_weight(ROOMS, env->start, 0);
	// ft_print_infos(env->rooms);
	ft_purge_rooms(&ROOMS, &ROOMS);
	if (END->weight == -1)
		ft_error(env, "Pipe {r}error{0} : no access to end room");
	ft_algo(env, NULL);
	ft_print_map(env->map);
	if (env->f_path == 1)
		ft_display_paths(env->paths, env->f_color);
}
