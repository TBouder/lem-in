/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs_duplicates.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:06:13 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 21:56:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static int	ft_verifdup_pipe(t_rooms pipes, char *str)
{
	while (pipes.pipes)
	{
		if (!ft_strcmp(pipes.pipes->id, str))
			return (1);
		pipes.pipes = pipes.pipes->next;
	}
	return (0);
}

int			ft_dup_pipes(t_rooms pipes, t_datas datas)
{
	char *str;

	str = ft_strinit(datas.name_two);
	if (ft_verifdup_pipe(pipes, str))
	{
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	return (0);
}

void		ft_verif_duplicates_rooms(t_env *env, t_datas datas)
{
	t_rooms	*rooms;

	rooms = ROOMS;
	while (rooms)
	{
		if (!ft_strcmp(datas.name, rooms->name))
			ft_error(env, "Room {r}error{0} : duplicate");
		if (datas.x == rooms->x && datas.y == rooms->y)
			ft_error(env, "Coo {r}error{0} : duplicate");
		rooms = rooms->next;
	}
}