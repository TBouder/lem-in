/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:12:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/12 12:17:17 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

void	ft_moves(t_env *env)
{
	ft_putendl("\n");

	// ft_putendl(env->paths->path);
	char	**str;

	env->start->ant = env->ant;

	str = ft_strsplit(env->paths->path, ' ');
	ft_mv_ants(env, str);
	ft_dbstrdel(str);
	ft_clear_gnl(env);
	ft_free_env(&env, 1);
}
