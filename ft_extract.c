/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:28:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/24 18:28:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_verif_pipes(t_datas datas, t_rooms **rooms)
{
	t_rooms		*tmp;
	int			i;
	int			j;

	tmp = *rooms;
	i = 0;
	j = 0;
	while (tmp && (!i || !j) && (ft_strcmp(datas.name, tmp->name) || ft_strcmp(datas.name_two, tmp->name)))
	{
		if (!ft_strcmp(datas.name, datas.name_two))
			ft_error("Error pipes : One room cannot have a pipe to itself");
		else if (!ft_strcmp(datas.name, tmp->name))
			i++;
		else if (!ft_strcmp(datas.name_two, tmp->name))
			j++;
		if (i == 1 && j == 1)
		{
			tmp = *rooms;
			while (tmp && ft_strcmp(datas.name, tmp->name))
				tmp = tmp->next;
			ft_pipesend(&tmp->pipes_next, datas);
			tmp = *rooms;
			while (tmp && ft_strcmp(datas.name_two, tmp->name))
				tmp = tmp->next;
			ft_pipesend(&tmp->pipes_next, datas);
		}
		tmp = tmp->next;
	}
	if (i == 0 || j == 0)
		ft_error("Error pipes : Room for pipe not found");
}

static void	ft_extract_rooms(t_datas *datas, char **str, int id, int pos)
{
	datas->name = ft_strnew(ft_strlen(str[0]));
	ft_strcpy(datas->name, str[0]); //verif commence pas par L et ?
	datas->id = id;
	datas->pos = pos;
	datas->x = ft_atoi(str[1]); //verif le ft_atoi
	datas->y = ft_atoi(str[2]); //verif le ft_atoi
}

static void	ft_extract_pipes(t_datas *datas, char **str, int id)
{
	datas->name = ft_strnew(ft_strlen(str[0]));
	ft_strcpy(datas->name, str[0]); //verif commence pas par L et ?
	datas->name_two = ft_strnew(ft_strlen(str[1]));
	ft_strcpy(datas->name_two, str[1]); //verif commence pas par L et ?
	datas->id = id;
}

static void	ft_extract_cmd(t_env *env, int fd, int id, char *status)
{
	char	*buff;
	char	**str;
	t_datas	datas;

	if (get_next_line(fd, &buff) >= 0)
	{
		str = ft_strsplit(buff, ' ');
		if (ft_dbtablelen(str) != 3)
			ft_error("Error map : Start or End room not well formated");
		if (!ft_strcmp("##start", status))
			ft_extract_rooms(&datas, str, id, 1);
		else
			ft_extract_rooms(&datas, str, id, 2);
		ft_roomsend(&(ROOMS), datas);
	}
}

void		ft_extract_map(t_env *env, int fd, char *buff, char **str)
{
	int		id;
	t_datas	datas;

	id = 0;
	ROOMS = NULL;
	while (get_next_line(fd, &buff) == 1)
	{
		str = ft_strsplit(buff, ' ');
		if (ft_strcmp("##start", buff) == 0 || ft_strcmp("##end", buff) == 0)
			ft_extract_cmd(env, fd, id, buff);
		else if (ft_dbtablelen(str) == 3)
		{
			ft_extract_rooms(&datas, str, id, 0);
			ft_roomsend(&(ROOMS), datas);
		}
		else
		{
			ft_strdel(str);
			str = ft_strsplit(buff, '-');
			if (ft_dbtablelen(str) == 2)
			{
				ft_extract_pipes(&datas, str, id);
				ft_verif_pipes(datas, &(ROOMS));
			}
		}
		ft_strdel(str);
		id++;
	}
}
