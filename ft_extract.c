/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/23 12:28:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/28 17:15:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

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

static void	ft_extract_cmd(t_env *env, char **str, int v, char *status)
{
	t_datas	datas;

	ft_strcpy(status, env->buff);
	ft_strdel(&env->buff);
	while (v == 0 && get_next_line(env->fd, &env->buff) == 1)
	{
		!env->buff[0] ? ft_error(env, "Map {r}error{0} : empty line") : 0;
		str = ft_strsplit(env->buff, ' ');
		if (str[0][0] == '#')
			;
		else if (ft_dbtablelen(str) != 3)
			ft_error(env, "Map {r}error{0} : Start|End room not well formated");
		else
		{
			!CMP("##start", status) ? ft_extract_rooms(&datas, str, env, 1) :
				ft_extract_rooms(&datas, str, env, 2);
			v = 1;
		}
		env->map = ft_strjoin_endl(&env->map, env->buff);
		ft_strdel(&env->buff);
		ft_freesplit(str);
	}
	ft_roomsend(&(ROOMS), datas);
	ft_strdel(&datas.name);
	ft_strdel(&status);
}

int			ft_launch_extract(t_env *env, char **str, int part)
{
	t_datas	datas;

	if (part == 1)
	{
		ft_extract_rooms(&datas, str, env, 0);
		ft_verif_duplicates_rooms(env, datas);
		ft_roomsend(&(ROOMS), datas);
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
		ft_strdel(&datas.name_two);
	}
	ft_strdel(&datas.name);
	return (0);
}

void		ft_extract_map(t_env *env, char **str)
{
	int		verif;

	verif = 0;
	while (get_next_line(env->fd, &env->buff) == 1 && !verif)
	{
		!env->buff[0] ? ft_error(env, "Map {r}error{0} : empty line") : 0;
		str = ft_strsplit(env->buff, ' ');
		if (!ft_is_cmd(env, str))
		{
			env->map = ft_strjoin_endl(&env->map, env->buff);
			if (CMP("##start", env->buff) == 0 || CMP("##end", env->buff) == 0)
				ft_extract_cmd(env, NULL, 0, ft_strnew(ft_strlen(env->buff)));
			else if (ft_dbtablelen(str) == 3)
				ft_launch_extract(env, str, 1);
			else if (str[0][0] == '#' && str[0][1] != '#')
				env->id--;
			else
				verif = ft_pipes(env);
			env->id++;
		}
		ft_strdel(&env->buff);
		ft_freesplit(str);
	}
	ft_strdel(&env->buff);
	ft_verif_launcher(env);
}
