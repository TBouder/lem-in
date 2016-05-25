/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 17:49:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

/*
** NOTE : J = Id de la fourmie
** NOTE : nbr[j] = id de la salle
*/

int		*ft_init_mult_tab(int ant, int len)
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
		if ((i + 1) % len == 0)
			j--;
		i++;
	}
	return (nbr);
}

void	ft_print_mult_moves(t_env *env, int *nbr, char ***str)
{
	int		len;
	ULL		i;
	ULL		j;
	int		k;
	int		v;
	int		x;

	i = -1;
	len = ft_path_len(env->paths);
	while (++i < (env->ant * env->ant))
	{
		j = 0;
		v = 0;
		while (j < env->ant)
		{
			k = -1;
			while (++k < len)
			{
				x = 0;
				if (nbr[j] >= 1 && nbr[j] < ft_dbstrlen(str[k]) && ++v)
				{
					ft_display(env, j + 1, str[k][nbr[j]], nbr[j], env->f_color);
					x = 1;
				}
				nbr[j] += 1;
				if (++j == env->ant)
					break ;
				x == 1 && j < env->ant && (long long)nbr[j] > 0 ? ft_putchar(' ') : 0;
			}
		}
		v != 0 ? ft_putchar('\n') : 0;

	}
}
