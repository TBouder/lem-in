/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:12:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/17 12:36:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

void	ft_moves(t_env *env)
{
	char	**str;
	int		*nbr;

	if (env->paths && env->paths->next == NULL)
	{
		str = ft_strsplit(env->paths->path, ' ');
		if (ft_strequ(str[1], env->end->name))
			nbr = ft_nbrnew(env->ant);
		else
			nbr = ft_init_tab(env);
		ft_print_moves(env, nbr, str);
		ft_dbstrdel(str);
		free(nbr);
	}
	ft_clear_gnl(env);
	ft_free_env(&env, 1);

}
