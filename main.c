/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:22:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 18:14:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
** - Explicits errors
** - Possibility to use -s for soft mode (for the map extract) (Ok same pipe)
** - Possibility to use -p for path mode (Display the differents paths used)
** - Possibility to use -c for color mode
*/

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	ft_extract(ac, av, &env);
	ft_find(env);
	ft_moves(env);
	return (0);
}
