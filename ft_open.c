/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:25:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/27 12:54:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_open_stdin(t_env *env)
{
	char	*str;

	env->fd = 0;
	if (get_next_line(env->fd, &env->buff) == 1)
	{
		str = ft_strnew(ft_strlen(env->buff));
		env->map = ft_strjoin_endl(str, env->buff);
		env->ant = ft_atoi_onum(env->buff);
		ft_strdel(&str);
		if (env->ant == -1)
		{
			ft_free_all(&env, 0);
			ft_error(env, "Ant {r}error{0} : number of ant must be a number > to 0");
		}
	}
	else
		ft_error(env, "File {r}error{0} : arg must be a file");
	ft_extract_map(env, NULL, NULL);
}

void		ft_open_file(t_env *env, char *map)
{
	char	*str;

	if ((env->fd = open(map, O_RDONLY)) == -1)
		ft_error(env, "Opening {r}error{0} : wrong map");
	if (get_next_line(env->fd, &env->buff) == 1)
	{
		str = ft_strnew(ft_strlen(env->buff));
		env->map = ft_strjoin_endl(str, env->buff);
		env->ant = ft_atoi_onum(env->buff);
		ft_strdel(&str);
		if (env->ant == -1)
		{
			ft_free_all(&env, 0);
			ft_error(env, "Ant {r}error{0} : number of ant must be a number > to 0");
		}
	}
	else
		ft_error(env, "File {r}error{0} : arg must be a file");
	ft_extract_map(env, NULL, NULL);
}
