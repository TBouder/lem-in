/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_weight.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 14:10:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 18:52:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

static int		ft_pipelen(t_hroom *hash)
{
	int		i;
	t_hpipe	*tmp;

	i = 0;
	tmp = hash->pipe;
	while (tmp)
	{
		if (tmp->room->weight == -1)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static void		ft_apply_to_empty(t_hpipe *pipe, int id)
{
	t_hpipe	*tmp;

	tmp = pipe;
	while (tmp)
	{
		if (tmp->room->weight == -1 || tmp->room->weight > id)
			tmp->room->weight = id + 1;
		tmp = tmp->next;
	}
}

int				ft_weight(t_env *env, t_hroom *start, int id, t_hroom *room)
{
	t_hpipe *pipe;

	room = start;
	if (ft_pipelen(room) == 1)
	{
		pipe = room->pipe;
		while (pipe->room->weight != -1)
			pipe = pipe->next;
		ft_apply_to_empty(pipe, id);
		ft_weight(env, pipe->room, id + 1, NULL);
	}
	else
	{
		pipe = room->pipe;
		ft_apply_to_empty(pipe, id);
		while (pipe)
		{
			if (pipe->room->weight == id + 1
				&& (env->r_end->weight != -1 ? id <= env->r_end->weight : 1))
				ft_weight(env, pipe->room, id + 1, NULL);
			pipe = pipe->next;
		}
		room = room->next;
	}
	return (1);
}
