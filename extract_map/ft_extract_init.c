/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_init.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:20:40 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:28:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

void		ft_init_env(t_env *env)
{
	env->ant = 0;
	env->id = 0;
	env->fd = 0;
	env->start = 0;
	env->end = 0;
	env->map_id = 0;
	env->room_len = 0;
	env->get_ant = 0;
	env->get_room = 0;
	env->get_pipe = 0;
	env->if_pipe = 0;
	env->f_soft = 0;
	env->f_path = 0;
	env->f_color = 0;
	env->r_start = NULL;
	env->r_end = NULL;
	env->buff = NULL;
	env->null = NULL;
	env->hash = NULL;
	env->hash_coo = NULL;
	env->map = NULL;
}

static void	ft_initnew(t_env *env, int lines)
{
	int		i;

	i = 0;
	while (i < lines)
	{
		env->map[i] = NULL;
		i++;
	}
	i = 0;
	while (i < lines * 50)
	{
		env->hash[i] = NULL;
		i++;
	}
	i = 0;
	while (i < lines * 50)
	{
		env->hash_coo[i] = NULL;
		i++;
	}
}

void		ft_malloc_env(t_env *env, int *line)
{
	if (!env->map && !env->hash && !env->hash_coo)
	{
		env->map = (char **)malloc(sizeof(char*) * line[1] + 1);
		env->hash = (t_hroom **)malloc(sizeof(t_hroom *) * (line[1] * 100));
		env->hash_coo = (t_hroom **)malloc(sizeof(t_hroom *) * (line[1] * 100));
		ft_initnew(env, line[1]);
	}
	if (!env->map || !env->hash || !env->hash_coo)
		ft_error(env, ERR01);
}
