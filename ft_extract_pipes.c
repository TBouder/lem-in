/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_pipes.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/25 13:27:41 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/09 22:16:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void		ft_rev_datas(t_datas *datas)
{
	char	*s1;
	char	*s2;

	s1 = ft_strinit(datas->name);
	s2 = ft_strinit(datas->name_two);
	datas->name = NULL;
	datas->name_two = NULL;
	datas->name = ft_strinit(s2);
	datas->name_two = ft_strinit(s1);
	ft_strdel(&s1);
	ft_strdel(&s2);
}

static int		ft_pipes_push(t_datas datas, t_rooms **rooms, int mode)
{
	t_rooms		*tmp_one;
	t_rooms		*tmp_two;

	tmp_one = *rooms;
	tmp_two = *rooms;
	while (tmp_one && CMP(datas.name, tmp_one->name))
		tmp_one = tmp_one->next;
	while (tmp_two && CMP(datas.name_two, tmp_two->name))
		tmp_two = tmp_two->next;
	if (!mode && (ft_dup_pipes(*tmp_one, datas)
		|| ft_dup_pipes(*tmp_two, datas)))
		return (1);
	ft_pipesend(&tmp_one->pipes, datas);
	ft_rev_datas(&datas);
	ft_pipesend(&tmp_two->pipes, datas);
	ft_strdel(&datas.name);
	ft_strdel(&datas.name_two);
	return (0);
}

static int		ft_pipe_before(t_env *env)
{
	char	**str;
	int		verif;

	verif = 0;
	if (env->buff[0] == '\0')
		return (1);
	str = ft_strsplit(env->buff, '-');
	if (!ft_cmd(env, str) && ft_dbstrlen(str) == 2)
	{
		if (ft_dbstrlen(str) == 2)
			verif = ft_launch_extract(env, str, 2);
	}
	else
		verif = 1;
	ft_dbstrdel(str);
	ft_strdel(&env->buff);
	return (verif);
}

void			ft_extract_pipes(t_datas *datas, char **str)
{
	datas->name = ft_strinit(str[0]);
	datas->name_two = ft_strinit(str[1]);
}

int				ft_put_pipes(t_datas datas, t_env *env)
{
	t_rooms		*tmp;
	int			i;
	int			j;

	tmp = ROOMS;
	i = 0;
	j = 0;
	if (ROOMS == NULL)
		ft_error(env, "Room {r}error{0} : no room");
	while (tmp && (!i || !j))
	{
		if (!CMP(datas.name, datas.name_two))
			return (1);
		!CMP(datas.name, tmp->name) ? i++ : 0;
		!CMP(datas.name_two, tmp->name) ? j++ : 0;
		if (i == 1 && j == 1 && ft_pipes_push(datas, &ROOMS, env->mode) == 1)
			return (1);
		tmp = tmp->next;
	}
	if (i == 0 || j == 0)
		return (1);
	return (0);
}

int				ft_pipes(t_env *env)
{
	char	**str;
	int		verif;

	verif = 0;
	verif = ft_pipe_before(env);
	while (get_next_line(env->fd, &env->buff) == 1 && !verif)
	{
		if (!env->buff[0])
			return (1);
		str = ft_strsplit(env->buff, '-');
		if (!ft_cmd(env, str))
		{
			if (env->buff[0] == '#')
				!verif ? env->map = ft_push_map(&env->map, env->buff) : 0;
			else if (ft_dbstrlen(str) == 2)
			{
				verif = ft_launch_extract(env, str, 2);
				!verif ? env->map = ft_push_map(&env->map, env->buff) : 0;
			}
			else
				verif = 1;
		}
		ft_strdel(&env->buff);
		ft_dbstrdel(str);
	}
	ft_strdel(&env->buff);
	return (verif);
}
