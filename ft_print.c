/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 13:31:12 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 16:59:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_print_pipes(t_pipes *pipes)
{
	t_pipes	*tmp;

	tmp = pipes;
	while (tmp)
	{
		ft_putendl(tmp->id);
		tmp = tmp->next;
	}
}

void		ft_print_map(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			break ;
		ft_putchar(str[i]);
		i++;
	}
	ft_putendl("\n");
}

void		ft_print_path(t_path *path)
{
	while (path)
	{
		ft_printf("%s : %d moves (max : %d)\n", path->path, path->moves,
			path->moves_max);
		path = path->next;
	}
}
