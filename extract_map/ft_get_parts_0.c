/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parts_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:51:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 00:18:51 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static void		ft_extract_s_e(t_env *env, int hash, char *str)
{
	if (env->start == 1)
	{
		env->start = 2;
		env->r_start = ft_find_elem(env->hash[hash], str);
	}
	else if (env->end == 1)
	{
		env->end = 2;
		env->r_end = ft_find_elem(env->hash[hash], str);
	}
}

static void		ft_get_coo(t_env *env, char **s, int *lines)
{
	char	*coo;
	int		hash;

	coo = ft_join(s);
	hash = ft_hash_djbtwo(coo, env->room_len);
	if (env->hash_coo[hash] != NULL)
	{
		if (ft_find_elem(env->hash_coo[hash], coo))
		{
			free(lines);
			ft_strdel(&coo);
			ft_err_clr(s, env, ERR04);
		}
	}
	ft_hcooend(&env->hash_coo[hash], s);
	ft_strdel(&coo);
}

void			ft_get_room(t_env *env, int *lines)
{
	char	**s;
	int		hash;

	env->get_room = 1;
	s = ft_strsplit(BUFF, ' ');
	if (ft_dbstrlen(s) == 3)
	{
		if (s[0][0] == 'L')
			ft_err_clr(s, env, ERR12);
		if (!ft_isstrnum(s[1]) || !ft_isstrnum(s[2]))
			ft_err_clr(s, env, ERR09);
		hash = ft_hash_djbtwo(s[0], env->room_len);
		if (env->hash[hash] != NULL)
			ft_find_elem(env->hash[hash], s[0]) ? ft_err_clr(s, env, ERR04) : 0;
		ft_get_coo(env, s, lines);
		ft_hroomend(env, &env->hash[hash], s[0], s);
		env->start == 1 || env->end == 1 ? ft_extract_s_e(env, hash, s[0]) : 0;
		ft_put_map(env, BUFF);
	}
	else
	{
		free(lines);
		ft_err_clr(s, env, ERR07);
	}
	ft_dbstrdel(s);
}

int				ft_get_pipe(t_env *env, int v)
{
	char	**s;
	int		hash[2];

	if (ft_strstr(BUFF, " "))
		return (1);
	s = ft_strsplit(BUFF, '-');
	if (!v && ft_dbstrlen(s) == 2)
	{
		!env->flag.f_soft && EQU(s[0], s[1]) ? v++ : 0;
		!v ? hash[0] = ft_hash_djbtwo(s[0], env->room_len) : 0;
		!v ? hash[1] = ft_hash_djbtwo(s[1], env->room_len) : 0;
		!v && (!env->hash[hash[0]] || !env->hash[hash[1]]) ? v++ : 0;
		!env->flag.f_soft && !v ? v = ft_check_if_already_exist(env, hash, s) : 0;
		!v ? ft_hpipesend(&ft_find_elem(env->hash[hash[0]], s[0])->pipe,
			ft_find_elem(env->hash[hash[1]], s[1])) : 0;
		!v ? ft_hpipesend(&ft_find_elem(env->hash[hash[1]], s[1])->pipe,
			ft_find_elem(env->hash[hash[0]], s[0])) : 0;
		!v ? ft_put_map(env, BUFF) : 0;
	}
	else
		v++;
	ft_dbstrdel(s);
	!v ? env->get_pipe = 1 : 0;
	!v ? env->if_pipe = 1 : 0;
	return (v);
}
