/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_parts_0.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 10:51:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/26 19:17:55 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static t_hroom	*ft_find_elem(t_hroom *base, char *data)
{
	t_hroom	*tmp;

	tmp = base;
	while (tmp)
	{
		if (EQU(tmp->id, data))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

 int		ft_check_if_already_exist(t_env *env, int hash[2], char **s)
{
	t_hpipe	*debug;
	int		v;

	v = 0;
	debug = ft_find_elem(env->hash[hash[1]], s[1])->pipe;
	while (debug)
	{
		if (EQU(debug->room->id, ft_find_elem(env->hash[hash[0]], s[0])->id))
		{
			v++;
			break ;
		}
		debug = debug->next;
	}
	return (v);
}

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

	coo = ft_join(s[1], s[2]);
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
	ft_hroomend(&env->hash_coo[hash], coo);
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
		ft_hroomend(&env->hash[hash], s[0]);
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
	if (ft_dbstrlen(s) == 2)
	{
		hash[0] = ft_hash_djbtwo(s[0], env->room_len);
		hash[1] = ft_hash_djbtwo(s[1], env->room_len);
		!env->hash[hash[0]] || !env->hash[hash[1]] ? v++ : 0;
		!v ? v = ft_check_if_already_exist(env, hash, s) : 0;
		!v ? ft_hpipesend(&ft_find_elem(env->hash[hash[0]], s[0])->pipe, ft_find_elem(env->hash[hash[1]], s[1])) : 0;
		!v ? ft_hpipesend(&ft_find_elem(env->hash[hash[1]], s[1])->pipe, ft_find_elem(env->hash[hash[0]], s[0])) : 0;
		!v ? ft_put_map(env, BUFF) : 0;
	}
	else
		v++;
	ft_dbstrdel(s);
	!v ? env->get_pipe = 1 : 0;
	!v ? env->if_pipe = 1 : 0;
	return (v);
}
