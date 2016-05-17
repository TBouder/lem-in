/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_specific_room.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:51:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/17 18:23:12 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

t_rooms	*ft_find_start(t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->pos == 1)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_rooms	*ft_find_end(t_rooms *rooms)
{
	t_rooms	*tmp;

	tmp = rooms;
	while (tmp)
	{
		if (tmp->pos == 2)
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

t_rooms	*ft_find_room(t_rooms *rooms, char *datas)
{
	t_rooms	*tmp;
	char	**str;
	char	*s;

	str = ft_strsplit(datas, ' ');
	s = ft_strinit(str[ft_dbstrlen(str) - 1]);
	ft_dbstrdel(str);
	tmp = rooms;
	while (tmp)
	{
		if (!ft_strcmp(tmp->name, s))
		{
			ft_strdel(&s);
			return (tmp);
		}
		tmp = tmp->next;
	}
	ft_strdel(&s);
	return (NULL);
}
