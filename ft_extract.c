/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:28:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/27 15:08:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_verif_rooms(t_env *env)
{
	t_rooms	*rooms;
	int		start;
	int		end;

	start = 0;
	end = 0;
	rooms = env->rooms;
	while (rooms)
	{
		rooms->pos == 1 ? start++ : 0;
		rooms->pos == 2 ? end++ : 0;
		rooms = rooms->next;
	}
	start > 1 ? ft_error(env, "Room {r}error{0} : multiple start room") : 0;
	end > 1 ? ft_error(env, "Room {r}error{0} : multiple end room") : 0;
	start < 1 ? ft_error(env, "Room {r}error{0} : no start room") : 0;
	end < 1 ? ft_error(env, "Room {r}error{0} : no end room") : 0;
}

static void	ft_extract_rooms(t_datas *datas, char **str, t_env *env, int pos)
{
	datas->name = ft_strnew(ft_strlen(str[0]));
	ft_strcpy(datas->name, str[0]);
	if (datas->name[0] == 'L')
		ft_error(env, "Room {r}error{0} : room name cannot start with 'L'");
	datas->id = env->id;
	datas->pos = pos;
	datas->x = ft_atoi(str[1]); //verif le ft_atoi
	datas->y = ft_atoi(str[2]); //verif le ft_atoi
}

static void	ft_extract_cmd(t_env *env, char *status)
{
	char	*buff;
	char	**str;
	t_datas	datas;

	if (get_next_line(env->fd, &buff) >= 0)
	{
		str = ft_strsplit(buff, ' ');
		if (ft_dbtablelen(str) != 3)
			ft_error(env, "Map {r}error{0} : Start or End room not well formated");
		if (!ft_strcmp("##start", status))
			ft_extract_rooms(&datas, str, env, 1);
		else
			ft_extract_rooms(&datas, str, env, 2);
		ft_roomsend(&(ROOMS), datas);
		ft_strdel(&datas.name);
		ft_strdel(&buff);
		ft_freesplit(str);
	}
}

int			ft_launch_extract(t_env *env, char **str, char *buff, int part)
{
	t_datas	datas;

	if (part == 0)
		ft_extract_cmd(env, buff);
	if (part == 1)
	{
		ft_extract_rooms(&datas, str, env, 0);
		ft_verif_duplicates_rooms(env, datas);
		ft_roomsend(&(ROOMS), datas);
		ft_strdel(&datas.name);
	}
	if (part == 2)
	{
		ft_extract_pipes(&datas, str);
		if (ft_put_pipes(datas, env) == 1)
		{
			ft_strdel(&datas.name);
			ft_strdel(&datas.name_two);
			return (1);
		}
		ft_strdel(&datas.name);
		ft_strdel(&datas.name_two);
	}
	return (0);
}

void		ft_extract_map(t_env *env, char *buff, char **str)
{
	int		verif;

	verif = 0;
	env->id = 0;
	ROOMS = NULL;
	while (get_next_line(env->fd, &buff) == 1 && !verif)
	{
		// env->map = ft_strjoin_endl(env->map, buff);
		if (buff[0] == '\0')
			ft_error(env,"Map {r}error{0} : empty line");
		str = ft_strsplit(buff, ' ');
		if (ft_strcmp("##start", buff) == 0 || ft_strcmp("##end", buff) == 0)
			ft_launch_extract(env, str, buff, 0);
		else if (ft_dbtablelen(str) == 3)
			ft_launch_extract(env, str, NULL, 1);
		else if (str[0][0] == '#' && str[0][1] != '#')
			ft_putendl(buff);
		else
			verif = ft_pipes(env, buff);
		env->id++;
		ft_strdel(&buff);
		ft_freesplit(str);
	}
	ft_strdel(&buff);
	ft_verif_rooms(env);
	ft_verif_pipes(env);
}
