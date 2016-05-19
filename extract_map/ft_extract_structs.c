/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 11:23:22 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 14:28:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static t_rooms	*ft_roomsnew(t_rooms *prev, t_datas datas)
{
	t_rooms	*rooms;

	if (!(rooms = (t_rooms *)malloc(sizeof(t_rooms))))
		return (NULL);
	rooms->id = datas.id;
	rooms->name = ft_strinit(datas.name);
	rooms->pos = datas.pos;
	rooms->weight = -1;
	rooms->ant = 0;
	rooms->x = datas.x;
	rooms->y = datas.y;
	rooms->pipes = NULL;
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
	str = ft_strinit(datas.name_two);
	pipes->id = ft_strinit(str);
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

void			ft_init_env(t_env *env)
{
	env->ant = 0;
	env->buff = NULL;
	env->map = NULL;
	env->paths = NULL;
	env->id = 0;
	env->f_soft = 0;
	env->f_path = 0;
	env->f_color = 0;
	ROOMS = NULL;
}
