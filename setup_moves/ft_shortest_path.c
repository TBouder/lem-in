/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shortest_path.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/29 15:17:36 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 14:30:34 by tbouder          ###   ########.fr       */
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
	!(nbr = (int ***)malloc(sizeof(int **) * ft_path_len(path))) ? exit(1) : 0;
	j = 0;
	while (path)
	{
		len = ft_strcountchar(path->path, ' ');
		!(nbr[j] = (int **)malloc(sizeof(int *) * len)) ? exit(1) : 0;
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
		while (k < len - 1)
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

static void		ft_print_path_dist(t_env *env, int *dist)
{
	t_path	*path;
	int		i;

	path = env->paths;
	i = 0;
	while (path)
	{
		if (dist[i] == -42)
			i++;
		if (!ft_strstr(path->path, "LERR")
			&& ft_strstr(path->path, env->r_end->id))
		{
			ft_printf("%s : %d units\n", path->path, dist[i]);
			i++;
		}
		path = path->next;
	}
	ft_putchar('\n');
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
				// *j += 1;
			}
			i++;
		}
		path = path->next;
	}
	env->paths = o;
}

static void			ft_path_remove_if_error(t_path **begin_path, char *str) //EXISTE DEJA
{
	t_path		*to_free;

	if (begin_path && *begin_path)
	{
		if (ft_isstrstr((*begin_path)->path, str))
		{
			to_free = *begin_path;
			*begin_path = (*begin_path)->next;
			ft_strdel(&to_free->path);
			free(to_free);
			ft_path_remove_if_error(begin_path, str);
		}
		else
			ft_path_remove_if_error(&(*begin_path)->next, str);
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

	dist = ft_nbrnew(j);
	ft_ext_dist(dist, nbr, env->paths);
	ft_find_shortest_path(env, dist, &j);
	ft_print_path_dist(env, dist);
	ft_path_remove_if_error(&env->paths, "LERR");
	free(dist);
	ft_free_trplnbr(env->paths, nbr);
}
