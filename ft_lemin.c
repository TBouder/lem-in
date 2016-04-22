/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/22 17:30:44 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois
** - Lecture entree standard
*/

int		main(int ac, char **av)
{
	int		i;
	t_env	*env;

	i = 0;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac == 1)
	{
		ft_open_stdin(env);
		
		ft_nbrendl(env->ant);
		ft_putstr(env->rooms->name);

	}
	else if (ac == 2)
	{
		ft_open_one(env, av);
		ft_nbrendl(env->ant);
		ft_putstr(env->rooms->name);

	}
	else if (ac > 2)
	{
		while (++i < ac)
		{
			ft_open_mult(env, av[i]);
			ft_nbrendl(env->ant);
			ft_putstr(env->rooms->name);

			ft_putchar(' ');
		}
	}
	ft_putchar('\n');
	return (0);
}
