/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/24 18:23:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois
** - Lecture entree standard
*/

static void		ft_print_infos(t_env *env)
{
	ft_printf("Number of ant(s) : %d\n", env->ant);
	while (env->rooms)
	{
		if (env->rooms->pos == 1)
			ft_printf("{g}Start room (%d) name {0}: %s (%d, %d)\n", env->rooms->id, env->rooms->name, env->rooms->x, env->rooms->y);
		else if (env->rooms->pos == 2)
			ft_printf("{g}End room (%d) name {0}: %s (%d, %d)\n", env->rooms->id, env->rooms->name, env->rooms->x, env->rooms->y);
		else
			ft_printf("{g}Room %d {0}: %s (%d, %d)\n", env->rooms->id, env->rooms->name, env->rooms->x, env->rooms->y);
		while (ROOMS->pipes_next)
		{
			ft_printf("{c}Pipe{0} : %s\n", ROOMS->pipes_next->id);
			ROOMS->pipes_next = ROOMS->pipes_next->next;
		}
		env->rooms = env->rooms->next;
	}
}

static int		ft_zero(t_env *env)
{
	ft_open_stdin(env);

	ft_print_infos(env);
	return (1);
}

static int		ft_one(t_env *env, char **av)
{
	ft_open_file(env, av[1]);

	ft_print_infos(env);
	return (1);
}

static int		ft_more(t_env *env, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		ft_open_file(env, av[i]);

		ft_print_infos(env);
	}
	return (1);
}

int		main(int ac, char **av)
{
	int		i;
	t_env	*env;

	i = 0;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac == 1)
		ft_zero(env);
	else if (ac == 2)
		ft_one(env, av);
	else if (ac > 2)
		ft_more(env, ac, av);
	ft_putchar('\n');
	return (0);
}
