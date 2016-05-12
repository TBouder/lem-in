/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:22:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/12 11:52:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
** - Explicits errors
** - Possibility to use -s for soft mode (for the map extract) (Allows same pipe)
*/

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	ft_extract(ac, av, &env);
	ft_find(env);
	// ft_clear_gnl(env);
	// ft_free_env(&env, 1);
	ft_moves(env);
	return (0);
}
