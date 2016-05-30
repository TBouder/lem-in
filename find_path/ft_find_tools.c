/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 19:02:42 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 13:03:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

int			ft_hpipelen(t_hroom *hash)
{
	int		i;
	t_hpipe	*tmp;

	i = 0;
	tmp = hash->pipe;
	while (tmp)
	{
		if (tmp->room->weight > hash->weight)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

t_hroom		*ft_find_room(t_env *env, char *datas)
{
	t_hroom	*ret;
	char	**str;
	char	*s;

	ret = NULL;
	str = ft_strsplit(datas, ' ');
	s = ft_strinit(str[ft_dbstrlen(str) - 1]);
	ft_dbstrdel(str);
	ret = env->hash[ft_hash_djbtwo(s, env->room_len)];
	while (CMP(s, ret->id))
		ret = ret->next;
	ft_strdel(&s);
	return (ret);
}

t_hroom		*ft_find_good_pipe(t_hroom *room)
{
	t_hpipe	*pipe;

	pipe = room->pipe;
	while (pipe)
	{
		if (pipe->room->weight > room->weight)
			break ;
		pipe = pipe->next;
	}
	return (pipe->room);
}
