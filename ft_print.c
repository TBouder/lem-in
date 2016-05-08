/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:31:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/07 16:37:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_print_pipes(t_pipes *pipes)
{
	t_pipes	*tmp;

	tmp = pipes;
	while (tmp)
	{
		ft_putendl(tmp->id);
		tmp = tmp->next;
	}
}

void		ft_putstrr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			break;
		ft_putchar(str[i]);
		i++;
	}
	ft_putendl("\n");
}

void		ft_print_infos(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	ft_printf("Number of ant(s) : %d\n", tmp->ant);
	while (tmp->rooms)
	{
		if (tmp->rooms->pos == 1)
			ft_printf("{g}%s (%d) {0}: (%d, %d) || w : {c}%d{0}\n", tmp->rooms->name, tmp->rooms->id, tmp->rooms->x, tmp->rooms->y, tmp->rooms->weight);
		else if (tmp->rooms->pos == 2)
			ft_printf("{g}%s (%d) {0}: (%d, %d) || w : {c}%d{0}\n", tmp->rooms->name, tmp->rooms->id, tmp->rooms->x, tmp->rooms->y, tmp->rooms->weight);
		else
			ft_printf("{g}%s (%d) {0}: (%d, %d) || w : {c}%d{0}\n", tmp->rooms->name, tmp->rooms->id, tmp->rooms->x, tmp->rooms->y, tmp->rooms->weight);
		while (tmp->rooms->pipes_prev)
		{
			ft_printf("\t{p}Prev pipe{0} : %s\n", tmp->rooms->pipes_prev->id);
			tmp->rooms->pipes_prev = tmp->rooms->pipes_prev->next;
		}
		while (tmp->rooms->pipes)
		{
			ft_printf("\t{b}Next pipe{0} : %s\n", tmp->rooms->pipes->id);
			tmp->rooms->pipes = tmp->rooms->pipes->next;
		}
		tmp->rooms = tmp->rooms->next;
	}
}

void		ft_print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%s : %d moves (max : %d)\n", path->path, path->moves, path->moves_max);
		path = path->next;
	}
}
