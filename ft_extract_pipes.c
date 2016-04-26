/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:27:41 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 15:45:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static int		ft_pipes_push(t_datas datas, t_rooms **rooms)
{
	t_rooms		*tmp_next;
	t_rooms		*tmp_prev;

	tmp_next = *rooms;
	tmp_prev = *rooms;
	while (tmp_next && ft_strcmp(datas.name, tmp_next->name))
		tmp_next = tmp_next->next;
	while (tmp_prev && ft_strcmp(datas.name_two, tmp_prev->name))
		tmp_prev = tmp_prev->next;
	if (ft_verif_duplicates_pipes(*tmp_next, datas) ||
		ft_verif_duplicates_pipes(*tmp_prev, datas))
		return (1);
	ft_pipesend(&tmp_next->pipes_next, datas);
	ft_pipesend(&tmp_prev->pipes_prev, datas);
	return (0);
}

void			ft_verif_pipes(t_rooms rooms)
{
	int		i;
	int		start;
	int		end;

	i = 0;
	start = 0;
	end = 0;
	while (1)
	{
		if (rooms.pos == 1 && !rooms.pipes_next && !rooms.pipes_prev)
			start = 1;
		if (rooms.pos == 2 && !rooms.pipes_prev && !rooms.pipes_next)
			end = 1;
		if (rooms.pipes_next || rooms.pipes_prev)
			i = 1;
		if (!(rooms.next))
			break ;
		rooms = (*rooms.next);
	}
	i == 0 ? ft_error("Pipe {r}error{0} : no pipes") : 0;
	start == 1 ? ft_error("Pipe {r}error{0} : start room is a dead-end") : 0;
	end == 1 ? ft_error("Pipe {r}error{0} : no access to end room") : 0;
}

void			ft_extract_pipes(t_datas *datas, char **str)
{
	datas->name = ft_strnew(ft_strlen(str[0]));
	ft_strcpy(datas->name, str[0]);
	datas->name_two = ft_strnew(ft_strlen(str[1]));
	ft_strcpy(datas->name_two, str[1]);
}

int				ft_put_pipes(t_datas datas, t_rooms **rooms)
{
	t_rooms		*tmp;
	int			i;
	int			j;

	tmp = *rooms;
	i = 0;
	j = 0;
	if (*rooms == NULL)
		ft_error("Room {r}error{0} : no room");
	while (tmp && (!i || !j) && (ft_strcmp(datas.name, tmp->name)
		|| ft_strcmp(datas.name_two, tmp->name)))
	{
		if (!ft_strcmp(datas.name, datas.name_two))
			return (1);
		!ft_strcmp(datas.name, tmp->name) ? i++ : 0;
		!ft_strcmp(datas.name_two, tmp->name) ? j++ : 0;
		if (i == 1 && j == 1 && ft_pipes_push(datas, rooms))
			return (1);
		tmp = tmp->next;
	}
	if (i == 0 || j == 0)
		return (1);
	return (0);
}

int				ft_pipes(t_env *env, char *buff)
{
	char	**str;
	int		verif;

	verif = 0;
	if (buff[0] == '\0')
		return (1);
	str = ft_strsplit(buff, '-');
	if (ft_dbtablelen(str) == 2)
		verif = ft_launch_extract(env, str, NULL, 2);
	else if (str[0][0] == '#' && str[0][1] != '#') // COMMENTAIRES
		ft_putendl(buff);
	while (get_next_line(env->fd, &buff) == 1 && !verif)
	{
		if (buff[0] == '\0')
			return (1);
		ft_strdel(str);
		str = ft_strsplit(buff, '-');
		if (ft_dbtablelen(str) == 2)
			verif = ft_launch_extract(env, str, NULL, 2);
		else if (str[0][0] == '#' && str[0][1] != '#') // COMMENTAIRES
			ft_putendl(buff);
		ft_strdel(str);
	}
	return (verif);
}
