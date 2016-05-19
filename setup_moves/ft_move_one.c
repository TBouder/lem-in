/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 16:27:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

/*
** NOTE : J = Id de la fourmie
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
	ULL		i;
	ULL		j;
	ULL		v;

	i = 0;
	while (i < (env->ant * 2))
	{
		j = 0;
		v = 0;
		while (j < env->ant)
		{
			if (nbr[j] >= 1 && nbr[j] < (ULL)ft_dbstrlen(str))
			{
				ft_display_move_color(j + 1, str[nbr[j]], nbr[j], env->f_color);
				ft_isstrstr(str[nbr[j]], END->name) ? END->ant++ : 0;
				v++;
			}
			nbr[j++] += 1;
		}
		if (END->ant == env->ant)
			break ;
		v != 0 ? ft_putchar('\n') : 0;
		i++;
	}
	ft_putchar('\n');
}
