/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:23:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/02 15:36:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static t_rooms	*ft_roomsnew(t_rooms *prev, t_datas datas)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	rooms->id = datas.id;
	rooms->name = ft_strinit(datas.name);
	rooms->pos = datas.pos;
	rooms->x = datas.x;
	rooms->y = datas.y;
	rooms->pipes_next = NULL;
	rooms->pipes_prev = NULL;
	rooms->next = NULL;
	rooms->prev = prev;
	return (rooms);
}

void			ft_roomsend(t_rooms **rooms, t_datas datas)
{
	t_rooms	*new_rooms;
	t_rooms	**tmp;

	new_rooms = *rooms;
	if (new_rooms)
	{
		tmp = &new_rooms;
		while (new_rooms->next != NULL)
		{
			tmp = &new_rooms;
			new_rooms = new_rooms->next;
		}
		new_rooms->next = ft_roomsnew(*tmp, datas);
	}
	else
		*rooms = ft_roomsnew(NULL, datas);
}

static t_pipes	*ft_pipesnew(t_pipes *prev, t_datas datas)
{
	t_pipes	*pipes;
	char	*str;

	if (!(pipes = (t_pipes *)malloc(sizeof(t_pipes))))
		return (NULL);
	str = ft_strnew(ft_strlen(datas.name) + ft_strlen(datas.name_two) + 2);
	ft_strcpy(str, datas.name);
	ft_strcat(str, "-");
	ft_strcat(str, datas.name_two);
	pipes->id = ft_strinit(str);
	pipes->ant = 0;
	pipes->occuped = 0;
	pipes->next = NULL;
	pipes->prev = prev;
	ft_strdel(&str);
	return (pipes);
}

void			ft_pipesend(t_pipes **pipes, t_datas datas)
{
	t_pipes	*new_pipes;
	t_pipes	**tmp;

	new_pipes = *pipes;
	if (new_pipes)
	{
		tmp = &new_pipes;
		while (new_pipes->next != NULL)
		{
			tmp = &new_pipes;
			new_pipes = new_pipes->next;
		}
		new_pipes->next = ft_pipesnew(*tmp, datas);
	}
	else
		*pipes = ft_pipesnew(NULL, datas);
}
