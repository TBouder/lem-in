/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lemin.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 12:16:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/28 19:13:31 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

/*
** BONUS
** - Lecture plusieurs fichiers a la fois (Neccessite OPEN)
*/

void		ft_putstrr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\0')
			break;
		ft_putchar(str[i]);
		i++;
	}
	ft_putchar('\n');
}

void		ft_print_infos(t_env *env)
{
	ft_printf("Number of ant(s) : %d\n", env->ant);
	while (ROOMS)
	{
		if (ROOMS->pos == 1)
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", ROOMS->name, ROOMS->id, ROOMS->x, ROOMS->y);
		else if (ROOMS->pos == 2)
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", ROOMS->name, ROOMS->id, ROOMS->x, ROOMS->y);
		else
			ft_printf("{g}%s (%d) {0}: (%d, %d)\n", ROOMS->name, ROOMS->id, ROOMS->x, ROOMS->y);
		while (ROOMS->pipes_prev)
		{
			ft_printf("\t{p}Prev pipe{0} : %s\n", ROOMS->pipes_prev->id);
			ROOMS->pipes_prev = ROOMS->pipes_prev->next;
		}
		while (ROOMS->pipes_next)
		{
			ft_printf("\t{b}Next pipe{0} : %s\n", ROOMS->pipes_next->id);
			ROOMS->pipes_next = ROOMS->pipes_next->next;
		}
		ROOMS = ROOMS->next;
	}
}


static void	ft_init_buff(t_env *env, char **str)
{
	if (!env->map)
	{
		*str = ft_strnew(ft_strlen(env->buff));
		env->map = ft_strjoin_endl(str, env->buff);
	}
	else
		env->map = ft_strjoin_endl(&env->map, env->buff);
	ft_strdel(str);
}

static void	ft_open(t_env *env)
{
	char	*str;
	int		fd;

	while (env->ant == 0 && (fd = get_next_line(env->fd, &env->buff)) == 1)
	{
		ft_init_buff(env, &str);		
		if (env->buff[0] == '#')
			;
		else if (!ft_isdigit(env->buff[0]))
			ft_error(env, "Ant {r}error{0} : must be number > to 0");
		else
		{
			env->ant = ft_atoi_onum(env->buff);
			if (env->ant == -1)
				ft_error(env, "Ant {r}error{0} : must be number > to 0");
		}
		ft_strdel(&env->buff);
	}
	if (fd == -1)
	{
		ft_printf("File {r}error{0} : arg must be a file\n");
		exit(EXIT_FAILURE);
	}
	ft_strdel(&env->buff);
	ft_extract_map(env, NULL);
}

static int	ft_zero(void)
{
	t_env	*env;

	if (!(env = (t_env *)malloc(sizeof(t_env))))
		return (0);
	env->fd = 0;
	env->ant = 0;
	env->map = NULL;
	env->id = 0;
	ROOMS = NULL;
	ft_open(env);
	ft_putstrr(env->map);
	// ft_print_infos(env);
	ft_clear_gnl(env);
	ft_free_all(&env, 1);
	return (1);
}

static int	ft_more(int ac, char **av)
{
	t_env	*env;
	int		i;

	i = 0;
	while (++i < ac)
	{
		if (!(env = (t_env *)malloc(sizeof(t_env))))
			return (0);
		if ((env->fd = open(av[i], O_RDONLY)) == -1)
			ft_error(env, "Opening {r}error{0} : wrong map");
		env->ant = 0;
		env->map = NULL;
		env->id = 0;
		ROOMS = NULL;
		ft_open(env);
		ft_putstr(env->map);
		// ft_print_infos(env);
		ft_clear_gnl(env);
		ft_free_all(&env, 1);
	}
	return (1);
}

int			main(int ac, char **av)
{
	int		i;

	i = 0;
	if (ac == 1)
		ft_zero();
	else if (ac >= 2)
		ft_more(ac, av);
	else
		ft_putchar('\n');
	return (0);
}
