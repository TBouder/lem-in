/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_open.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:25:58 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/22 17:11:09 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_extract_start(t_env *env, int fd)
{
	char	*buff;
	char	**str;

	if (!(env->rooms = (t_rooms *)malloc(sizeof(t_rooms))))
		ft_error("NOP");
	if (get_next_line(fd, &buff) == 1)
	{
		str = ft_strsplit(buff, ' ');
		env->rooms->name = ft_strnew(ft_strlen(str[0]));
		ft_strcpy(env->rooms->name, str[0]);
		env->rooms->x = ft_atoi(str[1]);
		env->rooms->y = ft_atoi(str[2]);
	}

}

void	ft_open_stdin(t_env *env)
{
	char	*buff;

	while (get_next_line(0, &buff)) //REFAIRE GET NEXT LINE
		ft_putstr(buff);
	env->ant = 0;
}

void	ft_open_one(t_env *env, char **av)
{
	int		fd;
	char	*buff;

	if ((fd = open(av[1], O_RDONLY)) == -1)
		ft_error("Opening error : wrong map");
	get_next_line(fd, &buff) != -1 ? env->ant = ft_atoi_onum(buff)
		: ft_error("File error : arg must be a file");
	if (get_next_line(fd, &buff) == 1)
	{
		if (ft_strcmp("##start", buff) == 0)
			ft_extract_start(env, fd);
	}
}

void	ft_open_mult(t_env *env, char *map)
{
	int		fd;
	char	*buff;

	if ((fd = open(map, O_RDONLY)) == -1)
		ft_error("Opening error : wrong map");
	get_next_line(fd, &buff) != -1 ? env->ant = ft_atoi_onum(buff)
		: ft_error("File error : arg must be a file");
	if (get_next_line(fd, &buff) == 1)
	{
		if (ft_strcmp("##start", buff) == 0)
			ft_extract_start(env, fd);
	}
}
