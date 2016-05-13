/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/13 10:52:04 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"
#define CURRENT ft_find_room(ROOMS, str[i])
#define NEXT ft_find_room(ROOMS, str[i + 1])

void	ft_mv_ants(t_env *env, char **str)
{
	int		i;
	int		j;
	int		id;
	int		k = 0;

	j = 0;
	id = 1;

while (env->end->ant != env->ant && k++ != 20)
{
	i = j;
	// ft_printf("%s vs %s\n", str[i], str[i + 1]);
	if (i < env->paths->moves && str[i] && str[i + 1] && CURRENT->ant >= 1 && (NEXT->ant == 0 || ft_isstrstr(NEXT->name, env->end->name)))
	{
		ft_display_move(id, NEXT->name);
		CURRENT->ant -= 1;
		NEXT->ant += 1;
	}
	i = j - 1;
	// ft_printf("%s vs %s\n", str[i], str[i + 1]);
	if (i < env->paths->moves && i > 0 && str[i] && str[i + 1] && CURRENT->ant >= 1 && (NEXT->ant == 0 || ft_isstrstr(NEXT->name, env->end->name)))
	{
		ft_display_move(id + j - 1, NEXT->name);
		CURRENT->ant -= 1;
		NEXT->ant += 1;
	}
	i = 0;
	// ft_printf("%s vs %s\n", str[i], str[i + 1]);
	if (str[i] && str[i + 1] && CURRENT->ant >= 1 && (NEXT->ant == 0 || ft_isstrstr(NEXT->name, env->end->name)))
	{
		ft_display_move(id + j, NEXT->name);
		CURRENT->ant -= 1;
		NEXT->ant += 1;
	}
	j++;
	ft_putchar('\n');
}



// ft_putchar('\n');
//
// 	i = j;
// 	if (str[i + 1] && CURRENT->ant >= 1 && (NEXT->ant == 0 || ft_isstrstr(NEXT->name, env->end->name)))
// 	{
// 		ft_display_move(id + j, NEXT->name);
// 		CURRENT->ant -= 1;
// 		NEXT->ant += 1;
// 	}
}

// [0]	[2]	[3]	[1]
//  3	 0	 0	 0
//  2	 1	 0	 0
//  1	 1	 1	 0
//  0	 1	 1	 1
//  0	 0	 1	 2
//  0	 0	 0	 3
