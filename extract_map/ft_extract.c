/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/10 19:08:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

#define BUFF env->buff

static void	ft_init_buff(t_env *env, char **str)
{
	if (!env->map)
	{
		*str = ft_strnew(ft_strlen(BUFF));
		env->map = ft_push_map(str, BUFF);
	}
	else
		env->map = ft_push_map(&env->map, BUFF);
	ft_strdel(str);
}

static void	ft_open(t_env *env)
{
	char	*str;
	int		fd;

	while (env->ant == 0 && (fd = get_next_line(env->fd, &BUFF)) == 1)
	{
		if ((BUFF[0] == '#' || BUFF[0] != '#') && BUFF[1] != '#')
			ft_init_buff(env, &str);
		if (BUFF[0] != '#' && !ft_isdigit(BUFF[0]))
			ft_error(env, "Ant {r}error{0} : must be number > to 0");
		else if (BUFF[0] != '#')
		{
			env->ant = ft_atoi_onum(BUFF);
			if (env->ant == -1)
				ft_error(env, "Ant {r}error{0} : must be number > to 0");
		}
		ft_strdel(&BUFF);
	}
	if (fd == -1)
	{
		ft_printf("File {r}error{0} : arg must be a file\n");
		exit(EXIT_FAILURE);
	}
	ft_strdel(&BUFF);
}

static int	ft_zero(int	i, t_env **env)
{
	(!(*env = (t_env *)malloc(sizeof(t_env)))) ? exit(1) : 0;
	ft_set_env(*env);
	(*env)->fd = 0;
	(*env)->mode = i;
	ft_open(*env);
	ft_extract_map(*env, NULL);
	return (1);
}

static int	ft_more(int ac, char **av, t_env **env)
{
	int		i;

	i = 0;
	while (++i < ac)
	{
		(!(*env = (t_env *)malloc(sizeof(t_env)))) ? exit(1) : 0;
		ft_set_env(*env);
		if (((*env)->fd = open(av[i], O_RDONLY)) == -1)
			ft_error(*env, "Opening {r}error{0} : wrong map");
		ft_open(*env);
		ft_extract_map(*env, NULL);
	}
	return (1);
}

void		ft_extract(int ac, char **av, t_env **env)
{
	if (ac == 1)
		ft_zero(0, env);
	else if (ac >= 2)
		ft_strequ(av[1], "-s") ? ft_zero(1, env) : ft_more(ac, av, env);
	else
		ft_putchar('\n');
}
