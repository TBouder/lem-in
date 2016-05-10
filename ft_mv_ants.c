/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 16:35:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_display_move(int ant_id, char *room_name, t_rooms *rooms, t_rooms *o)
{
	ft_putchar('L');
	ft_putnbr(ant_id);
	ft_putchar('-');
	ft_putstr(room_name);
	ft_putchar(' ');
	rooms->ant -= 1;
	ft_find_room_s(o, room_name)->ant += 1;
}

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
	rooms = ROOMS;
	ROOMS->ant = env->ant;
	while (ft_find_end(ROOMS)->ant != env->ant && i++ != 20)
	{
		ant_next_id = ant_id;
		ft_printf("%d, %d\n", ant_next_id, ant_id);
		while (ant_next_id <= rooms->ant)
		{
			if (ft_find_room_s(ROOMS, str[room_id])->ant == 0 || ft_strequ(str[room_id], ft_find_end(ROOMS)->name))
				ft_display_move(ant_id, str[room_id], rooms, ROOMS);
			ant_next_id++;
		}
		if (ft_strcmp(str[room_id], ft_find_end(ROOMS)->name))
			room_id++;
		ant_id++;
	}
	ft_dbstrdel(str);
}

void	ft_mv_ants1(t_env *env)
{
	int i = 0; ///////////////////
	int		room_id;
	int		ant_id;
	int		ant_room;
	char	**str;
	t_rooms	*rooms;

	ROOMS->ant = env->ant;
	str = ft_strsplit(env->path, ' ');
	while (ft_find_end(ROOMS)->ant != env->ant && i++ != 20)
	{
		rooms = ROOMS;
		room_id = 0;
		ant_id = 0;
		while (ft_strcmp(rooms->name, ft_find_end(ROOMS)->name))
		{
			ant_room = rooms->ant;
			while (ant_room != 0)
			{
				if (ft_find_room_s(ROOMS, str[room_id])->ant == 0)
				{
					ft_display_move(ant_id, str[room_id], rooms, ROOMS);
					if (ft_strequ(str[room_id], ft_find_end(ROOMS)->name))
						room_id++;
					break ;
				}
				ant_room--;
			}
			rooms = ft_find_room_s(ROOMS, str[room_id]);
			ant_id++;
			room_id++;
		}
		ft_putchar('\n');
	}
	ft_dbstrdel(str);
}

t_rooms	*ft_find_last_ant(t_rooms *rooms, char **str)
{
	t_rooms	*tmp;
	int		i;

	tmp = ft_find_end(rooms);
	i = ft_dbstrlen(str) - 1;
	while (tmp && tmp->ant == 0 && i >= 0)
	{
		tmp = ft_find_room_s(rooms, str[i]);
		i--;
	}
	// tmp = ft_find_room_s(rooms, str[i + 2]);
	return (tmp);
}

t_rooms	*ft_find_alast_ant(t_rooms *rooms, char **str)
{
	t_rooms	*tmp;
	int		i;

	tmp = ft_find_end(rooms);
	i = ft_dbstrlen(str) - 1;
	while (tmp && tmp->ant == 0 && i >= 0)
	{
		tmp = ft_find_room_s(rooms, str[i]);
		i--;
	}
	tmp = ft_find_room_s(rooms, str[i + 2]);
	return (tmp);
}

void	ft_mv_ants(t_env *env, char **str, int part)
{
	// int		i = 0;//

part = 0;

	if (ft_find_end(ROOMS)->ant == env->ant)
		exit(0);

	t_rooms	*n;
	t_rooms	*n_plus;

	n = ft_find_last_ant(ROOMS, str);
	n_plus = ft_find_alast_ant(ROOMS, str);
	n->ant -= 1;
	n_plus->ant_id = (n->ant_id == 0 ? 1 : n->ant_id);
	n->ant_id = 0;
	n_plus->ant += 1;
	ft_putchar('L');
	ft_putnbr(n_plus->ant_id);
	ft_putchar('-');
	ft_putstr(n_plus->name);
	ft_putchar('\n');


	// ft_printf("%d, %d\n", part, ft_dbstrlen(str + 1));
		ft_mv_ants(env, str, 0);

}
