/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/26 15:29:32 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"
#define SAME ft_isstrstr

ULL			*ft_init_tab(ULL ant)
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

static void	ft_print_moves_helper(t_env *env, ULL *nbr, char **str, ULL *v)
{
	ULL		i;

	i = 0;
	while (i < env->ant)
	{
		if (nbr[i] >= 1 && nbr[i] < (ULL)ft_dbstrlen(str))
		{
			ft_display(env, i + 1, str[nbr[i]], env->flag.f_color);
			SAME(str[nbr[i]], env->r_end->id) ? env->r_end->ant++ : 0;
			*v += 1;
		}
		nbr[i++] += 1;
		*v && i < env->ant && (long long)nbr[i] > 0 ? ft_putchar(' ') : 0;
	}
}

void		ft_print_moves(t_env *env, ULL *nbr, char **str)
{
	ULL		v;
	int		mv_number;
	int		mv_rounds;

	mv_number = 0;
	mv_rounds = 0;
	while (env->r_end->ant != env->ant)
	{
		v = 0;
		ft_print_moves_helper(env, nbr, str, &v);
		if (env->r_end->ant == env->ant)
			break ;
		v != 0 ? ft_putchar('\n') : 0;
		v != 0 ? mv_rounds++ : 0;
		mv_number += v;
	}
	ft_putchar('\n');
	if (env->flag.f_info)
		ft_printf("[{155}%ld{0} ants have moved with {168}%d{0} moves in \
{172}%d{0} rounds]\n", env->ant, mv_number, mv_rounds);
}
