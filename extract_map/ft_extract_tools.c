/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_tools.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 09:24:55 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/24 22:13:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

void	ft_put_map(t_env *env, char *str)
{
	env->map[env->map_id] = ft_strinit(str);
	env->map_id += 1;
}

char	*ft_join(char *s1, char *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 2);
	ft_strcpy(str, s1);
	ft_strcat(str, "+");
	ft_strcat(str, s2);
	return (str);
}
