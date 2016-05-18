/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 16:34:59 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

int		*ft_init_tab(int ant)
{
	int		*nbr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	!(nbr = (int *)malloc(sizeof(int) * ant)) ? exit(1) : 0;
	while (i < ant)
	{
		nbr[i] = j;
		j--;
		i++;
	}
	return (nbr);
}

//NOTE : J = Id de la fourmie
//NOTE : nbr[j] = id de la salle

void	ft_print_moves(t_env *env, int *nbr, char **str)
{
	int		i;
	int		j;
	int		v;

	i = 0;
	while (i < (env->ant * env->ant))
	{
		j = 0;
		v = 0;
		while (j < env->ant)
		{
			if (nbr[j] >= 1 && nbr[j] < ft_dbstrlen(str))
			{
				// ft_printf("L%d-%s (%d) ", j + 1, str[nbr[j]], nbr[j]);
				// ft_display_move(j + 1, str[nbr[j]]);
				ft_display_move_color(j + 1, str[nbr[j]], nbr[j], env->f_color);
				v++;
			}
			nbr[j] += 1;
			j++;
		}
		v != 0 ? ft_putchar('\n') : 0;
		i++;
	}
}
