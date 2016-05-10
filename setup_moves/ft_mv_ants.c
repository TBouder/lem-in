/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 22:20:08 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

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
	t_rooms	*n;
	t_rooms	*n_plus;

	n = ft_find_last_ant(ROOMS, str);
	n_plus = ft_find_alast_ant(ROOMS, str);
	n->ant -= 1;
	n_plus->ant_id = (n->ant_id == 0 ? 1 : n->ant_id);
	n->ant_id = 0;
	n_plus->ant += 1;
	ft_display_move(n_plus->ant_id, n_plus->name);
}
