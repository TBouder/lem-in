/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:12:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/17 18:49:20 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

void	ft_print_mult_moves(t_env *env, int *nbr, char ***str)
{
	int		i;
	int		j;
	int		v;

	i = 0;
	while (i < (env->ant * env->ant))
	{
		j = 0;
		v = 0;
		while (j < env->ant)
		{
			if (nbr[j] >= 1 && nbr[j] < ft_dbstrlen(str[0]))
			{
				ft_display_move(j + 1, str[0][nbr[j]]);
				v++;
			}
			if (j + 1 < env->ant && nbr[j] >= 1 && nbr[j] < ft_dbstrlen(str[1]))
			{
				ft_display_move(j + 2, str[1][nbr[j]]);
				v++;
			}
			nbr[j] += 1;
			j++;
		}
		v != 0 ? ft_putchar('\n') : 0;
		i++;
	}
}

int		ft_path_len(t_path *path)
{
	t_path	*tmp;
	int		i;

	tmp = path;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

void	ft_move_mult(t_env *env)
{
	t_path	*path;
	char	***str;
	int		*nbr;
	int		i;

	str = (char ***)malloc(sizeof(char **) * ft_path_len(env->paths));
	path = env->paths;
	i = 0;
	while (path)
	{
		str[i] = ft_strsplit(path->path, ' ');
		path = path->next;
		i++;
	}
	nbr = ft_init_tab(env->ant);
	// nbr = ft_init_tab(env->ant / 2);
	ft_print_mult_moves(env, nbr, str);
	// ft_dbstrdel(str);
	free(nbr);
}

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
			nbr = ft_init_tab(env->ant);
		ft_print_moves(env, nbr, str);
		ft_dbstrdel(str);
		free(nbr);
	}
	else
		ft_move_mult(env);
	ft_clear_gnl(env);
	ft_free_env(&env, 1);

}
