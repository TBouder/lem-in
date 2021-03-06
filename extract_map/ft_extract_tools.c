/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 09:24:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/06/01 00:07:03 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

void	ft_put_map(t_env *env, char *str)
{
	env->map[env->map_id] = ft_strinit(str);
	env->map_id += 1;
}

char	*ft_join(char **s)
{
	char	*str;

	str = ft_strnew(ft_strlen(s[1]) + ft_strlen(s[2]) + 3);
	ft_strcpy(str, s[1]);
	ft_strcat(str, " ");
	ft_strcat(str, s[2]);
	return (str);
}

t_hroom	*ft_find_elem(t_hroom *base, char *data)
{
	t_hroom	*tmp;

	tmp = base;
	while (tmp)
	{
		if (EQU(tmp->id, data))
			return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}

int		ft_check_if_already_exist(t_env *env, int hash[2], char **s)
{
	t_hpipe	*debug;
	int		v;

	v = 0;
	debug = ft_find_elem(env->hash[hash[1]], s[1])->pipe;
	while (debug)
	{
		if (EQU(debug->room->id, ft_find_elem(env->hash[hash[0]], s[0])->id))
		{
			v++;
			break ;
		}
		debug = debug->next;
	}
	return (v);
}

void	ft_more(int ac, char **av, t_env **env, t_flg *flg)
{
	int		i;

	i = flg->nb;
	while (++i < ac)
	{
		(!(*env = (t_env *)malloc(sizeof(t_env)))) ? exit(1) : 0;
		ft_init_env(*env);
		if (((*env)->fd = open(av[i], O_RDONLY)) == -1)
			ft_error(*env, "Opening {r}error{0} : wrong map");
		ft_set_flg(*env, *flg);
		ft_get_map(*env);
		ft_find(*env);
		ft_print_map(*env);
		(*env)->flag.f_path && !(*env)->flag.f_dist ? ft_print_path(*env) : 0;
		(*env)->flag.f_dist ? ft_find_min_dist(*env) : 0;
		ft_moves(*env);
		ft_free_env(env, 0);
		i + 1 != ac ? ft_printf("\n\n{155}--------NEXT MAP--------{0}\n\n") : 0;
	}
	exit(0);
}
