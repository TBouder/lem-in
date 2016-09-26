/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:13:10 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/26 15:28:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

int		ft_select_color(int id)
{
	int		tmp;

	tmp = id;
	if (tmp > 27 && tmp < 118)
	{
		if (tmp > 51 && tmp < 64)
			tmp += 18;
		if (tmp > 87 && tmp < 100)
			tmp += 18;
	}
	else
	{
		tmp = tmp % 118;
		tmp += 28;
		tmp = ft_select_color(tmp);
	}
	return (tmp);
}

void	ft_display(t_env *env, int ant_id, char *room_name, int color)
{
	int		id;

	id = (ant_id / env->path_len) + 27;
	id = ft_select_color(id);
	if (color && env->ant)
	{
		ft_printf("\e[38;5;%dm", id);
		ft_printf("L%d{0}-", ant_id);
		ft_printf("%s", room_name);
	}
	else
		ft_printf("L%d-%s", ant_id, room_name);
}

int		ft_path_len(t_path *path)
{
	t_path	*tmp;
	int		i;

	tmp = path;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_free_tr(t_env *env, char ***str)
{
	int		k;

	k = 0;
	while (k < env->path_len)
	{
		ft_dbstrdel(str[k]);
		k++;
	}
	free(str);
}

ULL		ft_sqrtt(ULL nb)
{
	ULL	i;
	ULL	sqr;

	sqr = 0;
	i = 1 << 30;
	while (i > nb)
		i >>= 2;
	while (i != 0)
	{
		if (nb >= sqr + i)
		{
			nb -= sqr + i;
			sqr = (sqr >> 1) + i;
		}
		else
			sqr >>= 1;
		i >>= 2;
	}
	return (sqr);
}
