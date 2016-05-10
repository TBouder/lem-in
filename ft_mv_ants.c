/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 14:38:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_mv_ants2(t_env *env)
{
	char	**str;
	t_rooms	*rooms;
	int		room_id;
	int		ant_id;
	int		ant_next_id;
	int	i = 0;

	room_id = 1;
	ant_id = 1;
	str = ft_strsplit(env->path, ' ');
	rooms = env->rooms;
	env->rooms->ant = env->ant;
	while (ft_find_end(env->rooms)->ant != env->ant && i++ != 20)
	{
		ant_next_id = ant_id;
		ft_printf("%d, %d\n", ant_next_id, ant_id);
		while (ant_next_id <= rooms->ant)
		{
			if (ft_find_room_s(env->rooms, str[room_id])->ant == 0 || ft_strequ(str[room_id], ft_find_end(env->rooms)->name))
			{
				ft_putchar('L');
				ft_putchar(ant_next_id);
				ft_putchar('-');
				ft_putendl(str[room_id]);
				ft_find_room_s(env->rooms, str[room_id])->ant = 1;
			}
			ant_next_id++;
		}
		if (ft_strcmp(str[room_id], ft_find_end(env->rooms)->name))
			room_id++;
		ant_id++;
	}
	ft_dbstrdel(str);
}

void	ft_mv_ants(t_env *env)
{
	int i = 0; ///////////////////
	int		room_id;
	int		ant_id;
	int		ant_room;
	char	**str;
	t_rooms	*rooms;

	env->rooms->ant = env->ant;
	str = ft_strsplit(env->path, ' ');
	while (ft_find_end(env->rooms)->ant != env->ant && i++ != 20)
	{
		rooms = env->rooms;
		room_id = 0;
		ant_id = 0;
		while (ft_strcmp(rooms->name, ft_find_end(env->rooms)->name))
		{
			ant_room = rooms->ant;
			while (ant_room != 0)
			{
				if (ft_find_room_s(env->rooms, str[room_id])->ant == 0)
				{
					ft_putchar('L');
					ft_putnbr(ant_id);
					ft_putchar('-');
					ft_putstr(str[room_id]);
					ft_putchar(' ');
					rooms->ant -= 1;
					ft_find_room_s(env->rooms, str[room_id])->ant += 1;
				}
				ant_room--;
			}
			rooms = ft_find_room_s(env->rooms, str[room_id]);
			ant_id++;
			room_id++;
		}
		ft_putchar('\n');
	}
	ft_dbstrdel(str);
}
