/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:25:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/23 12:28:16 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void		ft_open_stdin(t_env *env)
{
	char	*buff;

	while (get_next_line(0, &buff)) //REFAIRE GET NEXT LINE
		ft_putstr(buff);
	env->ant = 0;
}

void		ft_open_file(t_env *env, char *map)
{
	int		fd;
	char	*buff;

	if ((fd = open(map, O_RDONLY)) == -1)
		ft_error("Opening error : wrong map");
	get_next_line(fd, &buff) != -1 ? env->ant = ft_atoi_onum(buff)
		: ft_error("File error : arg must be a file");
	ft_extract_map(env, fd, NULL, NULL);
}
