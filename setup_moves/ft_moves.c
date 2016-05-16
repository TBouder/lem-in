/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:12:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/16 15:52:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

void	ft_moves(t_env *env)
{
	char	**str;
	int		*nbr;

	nbr = ft_init_tab(env);
	str = ft_strsplit(env->paths->path, ' ');
	ft_print_moves(env, nbr, str);
	ft_dbstrdel(str);
	free(nbr);
	ft_clear_gnl(env);
	ft_free_env(&env, 1);
}
