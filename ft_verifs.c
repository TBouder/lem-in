/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/27 17:58:34 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/05 16:09:45 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_verif_pipes(t_env *env)
{
	t_rooms	*rooms;
	int		i;
	int		st;
	int		end;

	i = 0;
	st = 0;
	end = 0;
	rooms = env->rooms;
	while (rooms)
	{
		rooms->pos == 1 && !rooms->pipes && !rooms->pipes_prev ? st = 1 : 0;
		rooms->pos == 2 && !rooms->pipes_prev && !rooms->pipes ? end = 1 : 0;
		rooms->pipes || rooms->pipes_prev ? i = 1 : 0;
		rooms = rooms->next;
	}
	i == 0 ? ft_error(env, "Pipe {r}error{0} : no pipes") : 0;
	st == 1 ? ft_error(env, "Pipe {r}error{0} : start room is a dead-end") : 0;
	end == 1 ? ft_error(env, "Pipe {r}error{0} : no access to end room") : 0;
}

static void	ft_verif_rooms(t_env *env)
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

void		ft_verif_launcher(t_env *env)
{
	if (ROOMS)
	{
		ft_verif_pipes(env);
		ft_verif_rooms(env);
	}
	else
	ft_error(env, "Room {r}error{0} : No rooms");

}
