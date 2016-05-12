/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_ants.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 11:47:18 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/12 13:27:03 by tbouder          ###   ########.fr       */
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
	int		j;
	int		verif;

	i = 0;
	verif = 0;
	while (str[i])
	{
		ft_putstr(CURRENT->name); ft_putchar(' ');
		ft_putnbr(CURRENT->ant); ft_putchar('\n');
		i++;
	}

ft_putchar('\n');

	i = 0;
	j = 0;
	verif = 0;
	while (str[i])
	{
		if (str[i] != NULL && CURRENT->ant >= 1)
		{
			if (str[i + 1] && NEXT->ant == 0)
			{
				NEXT->ant += 1;
				CURRENT->ant -= 1;
				// i = 0;
			}
			ft_putstr(CURRENT->name); ft_putchar(' ');
			ft_putnbr(CURRENT->ant); ft_putchar('\n');
		}
		// if (str[i + 1] && NEXT->ant == 0 && CURRENT->ant >= 1 && verif == 0)
		// {
		// 	NEXT->ant += 1;
		// 	CURRENT->ant -= 1;
		// 	verif++;
		// }
		// ft_putstr(CURRENT->name); ft_putchar(' ');
		// ft_putnbr(CURRENT->ant); ft_putchar(' ');
		// ft_nbrendl(CURRENT->ant_id);
		i++;
	}
	if (0)
		env->ant = 0;
}
