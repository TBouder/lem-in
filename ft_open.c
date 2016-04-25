/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:25:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/25 15:57:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_open_stdin(t_env *env)
{
	char	*buff;

	env->fd = 0;
	get_next_line(env->fd, &buff) != -1 ? env->ant = ft_atoi_onum(buff)
		: ft_error("File {r}error{0} : arg must be a file");
	ft_extract_map(env, NULL, NULL);
}

void		ft_open_file(t_env *env, char *map)
{
	char	*buff;

	if ((env->fd = open(map, O_RDONLY)) == -1)
		ft_error("Opening {r}error{0} : wrong map");
	get_next_line(env->fd, &buff) != -1 ? env->ant = ft_atoi_onum(buff)
		: ft_error("File {r}error{0} : arg must be a file");
	ft_extract_map(env, NULL, NULL);
}
