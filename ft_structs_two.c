/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_structs_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 16:54:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/03 14:21:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static t_path	*ft_pathnew(char *datas)
{
	t_path	*path;

	if (!(path = (t_path *)malloc(sizeof(t_path))))
		return (NULL);
	path->path = ft_strinit(datas);
	path->moves = 0;
	path->next = NULL;
	return (path);
}

void	ft_pathsend(t_path **path, char *datas)
{
	t_path	*new_path;

	new_path = *path;
	if (new_path)
	{
		while (new_path->next)
			new_path = new_path->next;
		new_path->next = ft_pathnew(datas);
	}
	else
		*path = ft_pathnew(datas);
}
