/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_moves.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 22:12:20 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/19 16:35:37 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_moves.h"

ULL		*ft_nbrnew_ULL(ULL size)
{
	ULL			*buffer;
	ULL			i;

	i = 0;
	if (!(buffer = (ULL *)malloc(sizeof(ULL) * size)))
		return (NULL);
	while (i < size)
	{
		buffer[i] = 0;
		i++;
	}
	return (buffer);
}

static void	ft_move_mult(t_env *env)
{
	t_path	*path;
	char	***str;
	int		*nbr;
	int		i;

	if (!(str = (char ***)malloc(sizeof(char **) * ft_path_len(env->paths))))
		exit(1);
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
	ft_free_tr(env, str);
	free(nbr);
}

void	ft_moves(t_env *env)
{
	char	**str;
	ULL		*nbr;

	if (env->paths && env->paths->next == NULL)
	{
		str = ft_strsplit(env->paths->path, ' ');
		if (ft_strequ(str[1], END->name))
			nbr = ft_nbrnew_ULL(env->ant);
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
