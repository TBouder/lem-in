/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:17:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 00:21:44 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

static t_hroom	*ft_find_good(t_hroom *room, char *str)
{
	// char	**s;

	// s = ft_strsplit(room->id, ' ');
	if (EQU(room->coo_id, str))
	{
		// ft_dbstrdel(s);
		return (room);
	}
	else
		room = ft_find_good(room->next, str);
	// ft_dbstrdel(s);
	return (room);
}

static void		ft_ext_dist(int *dist, int ***nbr, t_path *origin)
{
	t_path	*path;
	int		x;
	int		i;
	int		j;
	int		a;

	path = origin;
	j = 0;
	while (path)
	{
		i = 0;
		x = 0;
		while (i < ft_strcountchar(path->path, ' ') - 1)
		{
			a = ft_power(nbr[j][i][1] - nbr[j][i][0], 2);
			a += ft_power(nbr[j][i + 1][1] - nbr[j][i + 1][0], 2);
			a = ft_sqrt(a);
			i++;
			x += a;
		}
		dist[j++] = x;
		path = path->next;
	}
}

static int		***ft_init_trplnbr(t_path *origin)
{
	int		j;
	int		k;
	int		len;
	int		***nbr;
	t_path	*path;

	path = origin;
	nbr = (int ***)malloc(sizeof(int **) * ft_path_len(path)); //protect
	j = 0;
	while (path)
	{
		len = ft_strcountchar(path->path, ' ');
		nbr[j] = (int **)malloc(sizeof(int *) * len); //protect
		k = 0;
		while (k < len)
		{
			nbr[j][k] = ft_nbrnew(2);
			k++;
		}
		j++;
		path = path->next;
	}
	return (nbr);
}

static void		ft_free_trplnbr(t_path *origin, int ***nbr)
{
	int		j;
	int		k;
	int		len;
	t_path	*path;

	path = origin;
	j = 0;
	while (path)
	{
		len = ft_strcountchar(path->path, ' ');
		k = 0;
		while (k < len)
			free(nbr[j][k++]);
		free(nbr[j]);
		j++;
		path = path->next;
	}
	free(nbr);
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
			t = ft_strsplit(ft_find_good(env->hash[ft_hash_djbtwo(s[i], env->room_len)]->coo, s[i])->id, ' ');
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

void		ft_min_dist(t_env *env)
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

	dist = ft_nbrnew(j - 1);
	ft_ext_dist(dist, nbr, env->paths);
	// ft_nbrendl(dist[0]);
	// ft_nbrendl(dist[1]);

	ft_free_trplnbr(env->paths, nbr);
}
