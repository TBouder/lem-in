/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parts_1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/23 13:31:57 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/27 14:15:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

void	ft_get_ant(t_env *env)
{
	env->get_ant = 1;
	env->ant = ft_atoi_onum(BUFF);
	ft_put_map(env, BUFF);
}

void	ft_get_diaiz(t_env *env, int *lines)
{
	if (ft_strequ(BUFF, "##start"))
	{
		if (env->start >= 1)
		{
			free(lines);
			ft_err_nopath(env, ERR02);
		}
		env->start += 1;
		ft_put_map(env, BUFF);
	}
	if (ft_strequ(BUFF, "##end"))
	{
		if (env->end >= 1)
		{
			free(lines);
			ft_err_nopath(env, ERR03);
		}
		env->end += 1;
		ft_put_map(env, BUFF);
	}
	if (BUFF[1] != '#' || (BUFF[1] == '#' && BUFF[2] == '#'))
		ft_put_map(env, BUFF);
}
