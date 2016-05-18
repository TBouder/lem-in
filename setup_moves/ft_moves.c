/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:12:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 12:13:40 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

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


void	ft_print_mult_moves(t_env *env, int *nbr, char ***str)
{
	int		i;
	int		j;
	int		k;
	int		v;

	i = 0;
	while (i < (env->ant * env->ant))
	{
		j = 0;
		v = 0;
		while (j < env->ant)
		{
			k = 0;
			while (k < ft_path_len(env->paths))
			{
				if (nbr[j] >= 1 && nbr[j] < ft_dbstrlen(str[k]))
				{
					ft_display_move(j + 1, str[k][nbr[j]]);
					v++;
				}
				nbr[j] += 1;
				j++;
				k++;
				if (j == env->ant)
					break ;
			}
			// j++;
		}
		v != 0 ? ft_putchar('\n') : 0;
		i++;
	}
}

int		*ft_init_mult_tab(int ant, int len)
{
	int		*nbr;
	int		i;
	int		j;

	i = 0;
	j = 1;
	!(nbr = (int *)malloc(sizeof(int) * ant)) ? exit(1) : 0;
	while (i < ant)
	{
		nbr[i] = j;
		if ((i + 1) % len == 0)
			j--;
		i++;
	}
	return (nbr);
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
	nbr = ft_init_mult_tab(env->ant, i);
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
