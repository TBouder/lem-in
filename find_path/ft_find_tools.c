/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/10 19:47:13 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/18 15:40:28 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_find.h"

char		*ft_push_path(char **s1, char *s2)
{
	char	*str;

	if (s1 != NULL)
	{
		str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1);
		ft_strcpy(str, *s1);
		ft_strcat(str, " ");
		ft_strcat(str, s2);
		ft_strdel(s1);
	}
	else
	{
		str = ft_strinit(s2);
		ft_strdel(s1);
	}
	return (str);
}

void 		ft_path_remove_if_error(t_path **begin_path, char *str)
{
	t_path		*to_free;

	if (begin_path && *begin_path)
	{
		if (ft_isstrstr((*begin_path)->path, str))
		{
			to_free = *begin_path;
			*begin_path = (*begin_path)->next;
			ft_strdel(&to_free->path);
			free(to_free);
			ft_path_remove_if_error(begin_path, str);
		}
		else
			ft_path_remove_if_error(&(*begin_path)->next, str);
	}
}

//METTRE DES COULEURS DANS L'AFFICHAGE DU CHEMIN AVEC OPTION -c
void		ft_display_paths(t_path *origin)
{
	t_path	*paths;

	paths = origin;
	while (paths)
	{
		ft_putendl(paths->path);
		paths = paths->next;
	}
	ft_putstr("\n");
}
