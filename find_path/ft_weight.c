/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/05 14:00:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 19:45:34 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

static int		ft_pipeslen_w(t_rooms *origin, t_pipes *pipes, int id)
{
	t_pipes	*tmp;
	int		prev_id;
	int		i;

	id = 0;
	i = 0;
	tmp = pipes;
	while (tmp)
	{
		prev_id = ft_find_room(origin, tmp->id)->weight;
		if (prev_id == -1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static t_rooms	*ft_pipesgo_w(t_rooms *origin, t_pipes *pipes)
{
	t_pipes	*tmp;
	int		prev_id;

	tmp = pipes;
	while (tmp)
	{
		prev_id = ft_find_room(origin, tmp->id)->weight;
		if (prev_id == -1)
			return (ft_find_room(origin, tmp->id));
		tmp = tmp->next;
	}
	return (NULL);
}

static void		ft_apply_pipes(t_pipes *pipes, t_rooms *origin, int id)
{
	while (pipes)
	{
		if (ft_find_room(origin, pipes->id)->weight == -1
			|| ft_find_room(origin, pipes->id)->weight > id)
			ft_find_room(origin, pipes->id)->weight = id + 1;
		pipes = pipes->next;
	}
}

int				ft_weight(t_rooms *origin, t_rooms *rooms, int id)
{
	t_pipes		*pipes;
	int			prev_id;

	if (rooms == NULL)
		return (0);
	if (ft_pipeslen_w(origin, rooms->pipes, id) == 1)
	{
		rooms->weight = id;
		ft_weight(origin, ft_pipesgo_w(origin, rooms->pipes), id + 1);
	}
	else
	{
		rooms->weight = id;
		pipes = rooms->pipes;
		ft_apply_pipes(pipes, origin, id);
		while (pipes)
		{
			prev_id = ft_find_room(origin, pipes->id)->weight;
			if (prev_id == id + 1)
				ft_weight(origin, ft_find_room(origin, pipes->id), id + 1);
			pipes = pipes->next;
		}
	}
	return (1);
}
