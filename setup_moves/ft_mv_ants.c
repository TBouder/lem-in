/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/12 18:38:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"
#define CURRENT ft_find_room(ROOMS, str[i])
#define NEXT ft_find_room(ROOMS, str[i + 1])

t_rooms	*ft_find_last_ant(t_rooms *rooms, char **str)
{
	t_rooms	*tmp;
	int		i;

	tmp = ft_find_end(rooms);
	i = ft_dbstrlen(str) - 1;
	while (tmp && tmp->ant == 0 && i >= 0)
	{
		tmp = ft_find_room(rooms, str[i]);
		i--;
	}
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
		tmp = ft_find_room(rooms, str[i]);
		i--;
	}
	tmp = ft_find_room(rooms, str[i + 2]);
	return (tmp);
}

void	ft_mv_ants(t_env *env, char **str)
{
	int		i;
	int		id;

	i = 0;
	id = 1;
	while (str[i])
	{
		if (str[i + 1] && CURRENT->ant >= 1 && NEXT->ant == 0)
		{
			ft_display_move(id, NEXT->name);
			CURRENT->ant -= 1;
			NEXT->ant += 1;
		}
		i++;
	}
}
