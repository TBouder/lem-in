/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:51:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 11:48:23 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_error(t_env *env, char *str)
{
	ft_printf("%s\n", str);
	ft_clear_gnl(env);
	ft_free_env(&env, 0);
	exit(EXIT_FAILURE);
}

void		ft_err_nopath(t_env *env, char *str)
{
	ft_printf("%s\n", str);
	ft_clear_gnl(env);
	ft_free_env(&env, 2);
	exit(EXIT_FAILURE);
}

void		ft_err_noenv(t_env *env, char *str)
{
	ft_printf("%s\n", str);
	ft_clear_gnl(env);
	exit(EXIT_FAILURE);
}

void		ft_err_clr(char **err, t_env *env, char *str)
{
	ft_dbstrdel(err);
	ft_err_nopath(env, str);
}
