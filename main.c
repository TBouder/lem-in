/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:22:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 16:42:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Can read more multiple files one after the other (with open)
** - Explicits errors
** - Possibility to use -s for soft mode (neither same pipes, nor pipe-to-itself
**		room are an error)
** - Possibility to use -p for path mode (Display the differents paths used)
** - Possibility to use -c for color mode
** - Possibility to use -d for distance mode
** - Possibility to use -i for info mode
*/

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	ft_extract(ac, av, &env);
	ft_find(env);
	ft_print_map(env);
	env->flag.f_path && !env->flag.f_dist ? ft_print_path(env) : 0;
	env->flag.f_dist ? ft_find_min_dist(env) : 0;
	ft_moves(env);
	ft_free_env(&env, 0);
	return (0);
}
