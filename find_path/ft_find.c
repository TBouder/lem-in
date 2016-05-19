/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:34:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 17:24:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

void		ft_find(t_env *env)
{
	env->start = ft_find_start(ROOMS);
	END = ft_find_end(ROOMS);
	ft_weight(ROOMS, env->start, 0);
	ft_purge_rooms(&ROOMS, &ROOMS);
	if (END->weight == -1)
		ft_error(env, "Pipe {r}error{0} : no access to end room");
	ft_algo(env, NULL);
	ft_print_map(env->map);
	if (env->f_path == 1)
		ft_display_paths(env->paths, env->f_color);
}
