/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves_tools.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:13:10 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 13:15:56 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

void	ft_display_move(int ant_id, char *room_name)
{
	ft_printf("L%d-%s ", ant_id, room_name);
}

void	ft_display_move_color(int ant_id, char *room_name, int room, int color)
{
	if (color && room % 8 == 0)
		ft_printf("L%d-{27}%s{0} ", ant_id, room_name);
	else if (color && room % 6 == 0)
		ft_printf("L%d-{39}%s{0} ", ant_id, room_name);
	else if (color && room % 5 == 0)
		ft_printf("L%d-{51}%s{0} ", ant_id, room_name);
	else if (color && room % 4 == 0)
		ft_printf("L%d-{75}%s{0} ", ant_id, room_name);
	else if (color && room % 3 == 0)
		ft_printf("L%d-{81}%s{0} ", ant_id, room_name);
	else if (color && room % 2 == 0)
		ft_printf("L%d-{105}%s{0} ", ant_id, room_name);
	else if (color && room % 1 == 0)
		ft_printf("L%d-{123}%s{0} ", ant_id, room_name);
	else if (color)
		ft_printf("L%d-{147}%s{0} ", ant_id, room_name);
	else
		ft_printf("L%d-%s ", ant_id, room_name);
}

int		ft_path_len(t_path *path)
{
	t_path	*tmp;
	int		i;

	tmp = path;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}
