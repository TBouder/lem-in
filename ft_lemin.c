/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 19:21:35 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
*/

void		ft_print_infos(t_env *env)
{
	ft_printf("Number of ant(s) : %d\n", env->ant);
	while (ROOMS)
	{
		if (ROOMS->pos == 1)
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", ROOMS->name, ROOMS->id, ROOMS->x, ROOMS->y);
		else if (ROOMS->pos == 2)
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", ROOMS->name, ROOMS->id, ROOMS->x, ROOMS->y);
		else
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", ROOMS->name, ROOMS->id, ROOMS->x, ROOMS->y);
		while (ROOMS->pipes_prev)
		{
			ft_printf("\t{p}Prev pipe{0} : %s\n", ROOMS->pipes_prev->id);
			ROOMS->pipes_prev = ROOMS->pipes_prev->next;
		}
		while (ROOMS->pipes_next)
		{
			ft_printf("\t{b}Next pipe{0} : %s\n", ROOMS->pipes_next->id);
			ROOMS->pipes_next = ROOMS->pipes_next->next;
		}
		ROOMS = ROOMS->next;
	}
}

static int	ft_zero(t_env *env)
{
	ft_open_stdin(env);
	ft_putstr(env->map);
	ft_strdel(&env->map);
	// ft_print_infos(env);
	return (1);
}

static int	ft_more(t_env *env, int ac, char **av)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		ft_open_file(env, av[i]);
		ft_putstr(env->map);
		ft_strdel(&env->map);
		// ft_print_infos(env);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		i;
	t_env	*env;

	i = 0;
	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	if (ac == 1)
		ft_zero(env);
	else if (ac >= 2)
		ft_more(env, ac, av);
	ft_putchar('\n');

	ft_free_all(&ROOMS);
	ft_strdel(&env->map);
	free(env);
	return (0);
}
