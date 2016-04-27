/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:58:34 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/27 18:00:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void			ft_verif_pipes(t_env *env)
{
	t_rooms	rooms;
	int		i;
	int		st;
	int		end;

	i = 0;
	st = 0;
	end = 0;
	rooms = *env->rooms;
	while (1)
	{
		rooms.pos == 1 && !rooms.pipes_next && !rooms.pipes_prev ? st = 1 : 0;
		rooms.pos == 2 && !rooms.pipes_prev && !rooms.pipes_next ? end = 1 : 0;
		rooms.pipes_next || rooms.pipes_prev ? i = 1 : 0;
		if (!(rooms.next))
			break ;
		rooms = (*rooms.next);
	}
	i == 0 ? ft_error(env, "Pipe {r}error{0} : no pipes") : 0;
	st == 1 ? ft_error(env, "Pipe {r}error{0} : start room is a dead-end") : 0;
	end == 1 ? ft_error(env, "Pipe {r}error{0} : no access to end room") : 0;
}

void	ft_verif_rooms(t_env *env)
{
	t_rooms	*rooms;
	int		start;
	int		end;

	start = 0;
	end = 0;
	rooms = env->rooms;
	while (rooms)
	{
		rooms->pos == 1 ? start++ : 0;
		rooms->pos == 2 ? end++ : 0;
		rooms = rooms->next;
	}
	start > 1 ? ft_error(env, "Room {r}error{0} : multiple start room") : 0;
	end > 1 ? ft_error(env, "Room {r}error{0} : multiple end room") : 0;
	start < 1 ? ft_error(env, "Room {r}error{0} : no start room") : 0;
	end < 1 ? ft_error(env, "Room {r}error{0} : no end room") : 0;
}
