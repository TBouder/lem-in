/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_mult.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/31 14:11:48 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

int			*ft_init_mult_tab(int ant, int len)
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

static int	ft_print_mult_helper(t_env *env, ULL *j, int *nbr, char ***str)
{
	int		k;
	int		x;
	int		v;

	v = 0;
	k = 0;
	while (k < env->path_len)
	{
		x = 0;
		if (nbr[*j] >= 1 && nbr[*j] < ft_dbstrlen(str[k]))
		{
			ft_display(env, *j + 1, str[k][nbr[*j]], env->flag.f_color);
			v++;
			x++;
		}
		nbr[*j] += 1;
		if (++*j == env->ant)
			break ;
		x && *j < env->ant && (long long)nbr[*j] > 0 ? ft_putchar(' ') : 0;
		k++;
	}
	return (v);
}

void		ft_print_mult_moves(t_env *env, int *nbr, char ***str)
{
	ULL		i;
	ULL		j;
	int		v;
	int		mv_number;
	int		mv_rounds;

	i = -1;
	mv_number = 0;
	mv_rounds = 0;
	while (++i < (env->ant * env->ant))
	{
		j = 0;
		v = 0;
		while (j < env->ant)
			v += ft_print_mult_helper(env, &j, nbr, str);
		v != 0 ? ft_putchar('\n') : 0;
		v != 0 ? mv_rounds++ : 0;
		mv_number += v;
	}
	if (env->flag.f_info)
	{
		ft_printf("\n[{155}%ld{0} ants have moved with {168}%d{0} moves in \
{172}%d{0} rounds]\n", env->ant, mv_number, mv_rounds);
	}
}
