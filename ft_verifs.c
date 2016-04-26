/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/26 12:06:13 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 17:45:43 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static int	ft_verif_duplicates_pipes_next(t_rooms pipes, char *str)
{
	while (pipes.pipes_next)
	{
		if (!ft_strcmp(pipes.pipes_next->id, str))
			return (1);
		pipes.pipes_next = pipes.pipes_next->next;
	}
	return (0);
}

static int	ft_verif_duplicates_pipes_prev(t_rooms pipes, char *str)
{
	while (pipes.pipes_prev)
	{
		if (!ft_strcmp(pipes.pipes_prev->id, str))
			return (1);
		pipes.pipes_prev = pipes.pipes_prev->next;
	}
	return (0);
}

int			ft_verif_duplicates_pipes(t_rooms pipes, t_datas datas)
{
	char *str;

	str = ft_strnew(ft_strlen(datas.name) + ft_strlen(datas.name_two) + 4);
	ft_strcpy(str, datas.name);
	ft_strcat(str, " - ");
	ft_strcat(str, datas.name_two);
	if (ft_verif_duplicates_pipes_next(pipes, str) || ft_verif_duplicates_pipes_prev(pipes, str))
	{
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	str = ft_strnew(ft_strlen(datas.name) + ft_strlen(datas.name_two) + 4);
	ft_strcpy(str, datas.name_two);
	ft_strcat(str, " - ");
	ft_strcat(str, datas.name);
	if (ft_verif_duplicates_pipes_next(pipes, str) || ft_verif_duplicates_pipes_prev(pipes, str))
	{
		ft_strdel(&str);
		return (1);
	}
	ft_strdel(&str);
	return (0);
}

void		ft_verif_duplicates_rooms(t_rooms *rooms, t_datas datas)
{
	while (rooms)
	{
		if (!ft_strcmp(datas.name, rooms->name))
			ft_error("Room {r}error{0} : duplicate");
		if (datas.x == rooms->x && datas.y == rooms->y)
			ft_error("Coo {r}error{0} : duplicate");
		rooms = rooms->next;
	}
}
