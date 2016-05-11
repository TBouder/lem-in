/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:34:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/11 12:17:22 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

void		ft_find(t_env *env)
{
	env->end = ft_find_end(ROOMS);
	ft_weight(ROOMS, ft_find_start(ROOMS), 0);
	ft_purge_rooms(&ROOMS, &ROOMS);
	if (env->end->weight == -1)
		ft_error(env, "Pipe {r}error{0} : no access to end room");
	ft_algo(env);
	ft_print_map(env->map);
	// ft_print_infos(env);
	ft_putendl(env->path);
}
