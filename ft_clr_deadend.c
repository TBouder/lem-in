/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clr_deadend.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/04 22:29:54 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/05 19:37:33 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static int	ft_dead_end(t_rooms *rooms)
{
	if (rooms->pos == 0 && ft_pipeslen(rooms->pipes) <= 1)
		return (1);
	return (0);
}

static void ft_useless_pipe_remove_if(t_pipes **begin_pipes, char *str)
{
	t_pipes		*to_free;

	if (begin_pipes && *begin_pipes)
	{
		if (ft_strequ((*begin_pipes)->id, str))
		{
			to_free = *begin_pipes;
			*begin_pipes = (*begin_pipes)->next;
			ft_strdel(&to_free->id);
			free(to_free);
			ft_useless_pipe_remove_if(begin_pipes, str);
		}
		else
		{
			ft_useless_pipe_remove_if(&(*begin_pipes)->next, str);
		}
	}
}

void	ft_free_allddddp(t_pipes **pipes)
{
	t_pipes	*free_list;
	t_pipes	*temp;

	if (pipes != NULL)
	{
		free_list = *pipes;
		while (free_list)
		{
			temp = free_list;
			free_list = free_list->next;
			ft_strdel(&temp->id);
			free(temp);
		}
		*pipes = NULL;
	}
	pipes = NULL;
}

static void	ft_rooms_remove_if(t_rooms **begin_rooms, t_rooms **origin, int *i)
{
	t_rooms		*to_free;

	if (*begin_rooms)
	{

		if (ft_dead_end(*begin_rooms))
		{
			if (ft_pipeslen((*begin_rooms)->pipes) == 1)
			{
				ft_useless_pipe_remove_if(&ft_find_room_s(*origin, (*begin_rooms)->pipes->id)->pipes, (*begin_rooms)->name);
				// free((*begin_rooms)->pipes);
				ft_putendl(ft_pipeslen((*begin_rooms)->pipes));
				free((*begin_rooms)->pipes);
				to_free = *begin_rooms;
				*begin_rooms = (*begin_rooms)->next;
				ft_strdel(&to_free->name);
				free(to_free);
				*i += 1;
				ft_rooms_remove_if(begin_rooms, origin, i);
			}
			free((*begin_rooms)->pipes);
			to_free = *begin_rooms;
			*begin_rooms = (*begin_rooms)->next;
			ft_strdel(&to_free->name);
			free(to_free);
			*i += 1;
			ft_rooms_remove_if(begin_rooms, origin, i);
		}
		else
			ft_rooms_remove_if(&(*begin_rooms)->next, origin, i);
	}
}

void		ft_purge_useless_rooms(t_rooms **begin_rooms, t_rooms **origin)
{
	int		i;

	i = 1;
	while (i != 0)
	{
		i = 0;
		ft_rooms_remove_if(begin_rooms, origin, &i);
	}
}
