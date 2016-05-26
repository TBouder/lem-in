/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 18:22:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 18:37:08 by tbouder          ###   ########.fr       */
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

int			main(int ac, char **av)
{
	t_env	*env;

	env = NULL;
	ft_extract(ac, av, &env);
	ft_find(env);
	ft_print_map(env);
	env->f_path ? ft_print_path(env) : 0;
	ft_moves(env);
	// ft_print_map_weight(env);
	ft_free_env(&env, 0);
	return (0);
}
