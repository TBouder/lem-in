/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_helper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/24 21:46:17 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/31 18:32:02 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static void	ft_free_env_hash(t_hroom **hash, t_hroom *temp)
{
	t_hroom	*free_hash;
	t_hpipe	*free_pipe;
	t_hpipe	*pipe;

	if (hash != NULL)
	{
		free_hash = *hash;
		while (free_hash)
		{
			temp = free_hash;
			ft_strdel(&temp->id);
			ft_strdel(&temp->coo_id);
			pipe = temp->pipe;
			while (pipe)
			{
				free_pipe = pipe;
				pipe = pipe->next;
				free(free_pipe);
			}
			free_hash = free_hash->next;
			free(temp);
		}
		*hash = NULL;
	}
	hash = NULL;
}

void		ft_free_hash(t_hroom **hash, int len)
{
	int		i;

	i = 0;
	if (hash)
	{
		while (i < len * 50)
		{
			if (hash[i])
			{
				ft_free_env_hash(&hash[i], NULL);
				hash[i] = NULL;
				free(hash[i]);
			}
			i++;
		}
		free(hash);
	}
}

void		ft_clear_gnl(t_env *env)
{
	if (env && env->map)
	{
		ft_strdel(&env->buff);
		while (get_next_line_num(env->fd, &env->buff, NULL) == 1)
			ft_strdel(&env->buff);
		ft_strdel(&env->buff);
	}
}
