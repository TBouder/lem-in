/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:17:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/31 14:27:29 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

static t_hroom	*ft_find_good(t_hroom *room, char *str)
{
	t_hroom	*prev;

	if (!room)
		return (NULL);
	if (EQU(room->coo_id, str))
		return (room);
	else
	{
		prev = room;
		room = ft_find_good(room->next, str);
		if (room == NULL)
			room = prev;
	}
	return (room);
}

static void		ft_ext_dist(int *dist, int ***nbr, t_path *origin)
{
	t_path	*path;
	double	x;
	int		i;
	int		j;
	double	a;

	path = origin;
	j = 0;
	while (path)
	{
		i = 0;
		x = 0;
		while (i < ft_strcountchar(path->path, ' ') - 1)
		{
			a = ft_sqrtt(ft_power(nbr[j][i + 1][0] - nbr[j][i][0], 2) +
				ft_power(nbr[j][i + 1][1] - nbr[j][i][0], 2));
			i++;
			x += a;
		}
		dist[j++] = x;
		path = path->next;
	}
}

static void		ft_find_min(t_env *env, int ***nbr, t_path *path, int *j)
{
	int		i;
	char	**s;
	char	**t;

	while (path)
	{
		i = 0;
		s = ft_strsplit(path->path, ' ');
		while (s[i])
		{
			t = ft_strsplit(ft_find_good(env->hash[ft_hash_djbtwo(s[i],
				env->room_len)]->coo, s[i])->id, ' ');
			nbr[*j][i][0] = ft_atoi(t[0]);
			nbr[*j][i][1] = ft_atoi(t[1]);
			ft_dbstrdel(t);
			i++;
		}
		ft_dbstrdel(s);
		*j += 1;
		path = path->next;
	}
}

static void		ft_find_shortest_path(t_env *env, int *dist, int *j)
{
	t_path	*path;
	t_path	*o;
	int		len;
	int		i;

	len = ft_nbrsmallest(dist, *j);
	i = 0;
	path = env->paths;
	o = path;
	while (path)
	{
		if (!ft_strstr(path->path, "LERR")
			&& ft_strstr(path->path, env->r_end->id))
		{
			if (dist[i] > len)
			{
				path->path = ft_push_path(&path->path, "LERR");
				dist[i] = -42;
			}
			i++;
		}
		path = path->next;
	}
	env->paths = o;
}

void			ft_find_min_dist(t_env *env)
{
	t_path	*path;
	int		***nbr;
	int		*dist;
	int		j;

	j = 0;
	dist = NULL;
	nbr = ft_init_trplnbr(env->paths);
	path = env->paths;
	ft_find_min(env, nbr, path, &j);
	dist = ft_nbrnew_ulls(j);
	ft_ext_dist(dist, nbr, env->paths);
	ft_find_shortest_path(env, dist, &j);
	ft_print_path_dist(env, dist);
	ft_path_remove_if_error(&env->paths, "LERR");
	free(dist);
	ft_free_trplnbr(env->paths, nbr);
}
