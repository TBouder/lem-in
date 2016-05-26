/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 18:00:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"
#define SAME ft_isstrstr

/*
** NOTE : j = Id de la fourmie
** NOTE : nbr[j] = id de la salle
*/

ULL		*ft_init_tab(ULL ant)
{
	ULL		*nbr;
	ULL		i;
	ULL		j;

	i = 0;
	j = 1;
	!(nbr = (ULL *)malloc(sizeof(ULL) * ant)) ? exit(1) : 0;
	while (i < ant)
	{
		nbr[i] = j;
		j--;
		i++;
	}
	return (nbr);
}

void	ft_print_moves(t_env *env, ULL *nbr, char **str)
{
	ULL		j;
	ULL		v;

	while (env->r_end->ant != env->ant)
	{
		j = 0;
		v = 0;
		while (j < env->ant)
		{
			if (nbr[j] >= 1 && nbr[j] < (ULL)ft_dbstrlen(str))
			{
				ft_display(env, j + 1, str[nbr[j]], env->f_color);
				SAME(str[nbr[j]], env->r_end->id) ? env->r_end->ant++ : 0;
				v++;
			}
			nbr[j++] += 1;
			v && j < env->ant && (long long)nbr[j] > 0 ? ft_putchar(' ') : 0;
		}
		if (env->r_end->ant == env->ant)
			break ;
		v != 0 ? ft_putchar('\n') : 0;
	}
	ft_putchar('\n');
}
