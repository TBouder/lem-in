/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:31:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/02 17:13:49 by tbouder          ###   ########.fr       */
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
	ft_putchar('\n');
}

void		ft_print_infos(t_env *env)
{
	t_env	*tmp;

	tmp = env;
	ft_printf("Number of ant(s) : %d\n", tmp->ant);
	while (tmp->rooms)
	{
		if (tmp->rooms->pos == 1)
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", tmp->rooms->name, tmp->rooms->id, tmp->rooms->x, tmp->rooms->y);
		else if (tmp->rooms->pos == 2)
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", tmp->rooms->name, tmp->rooms->id, tmp->rooms->x, tmp->rooms->y);
		else
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", tmp->rooms->name, tmp->rooms->id, tmp->rooms->x, tmp->rooms->y);
		while (tmp->rooms->pipes_prev)
		{
			ft_printf("\t{p}Prev pipe{0} : %s\n", tmp->rooms->pipes_prev->id);
			tmp->rooms->pipes_prev = tmp->rooms->pipes_prev->next;
		}
		while (tmp->rooms->pipes_next)
		{
			ft_printf("\t{b}Next pipe{0} : %s\n", tmp->rooms->pipes_next->id);
			tmp->rooms->pipes_next = tmp->rooms->pipes_next->next;
		}
		tmp->rooms = tmp->rooms->next;
	}
}

void		ft_print_path(t_path *path)
{
	char	**str;

	while (path)
	{
		str = ft_strsplit(path->path, ' ');
		ft_printf("%s : %d moves\n", path->path, ft_dbstrlen(str));
		path = path->next;
		ft_dbstrdel(str);
	}
}
