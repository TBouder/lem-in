/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:19:32 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/23 15:36:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static t_hroom	*ft_hroomnew(char *str)
{
	t_hroom	*hlist;

	!(hlist = (t_hroom *)malloc(sizeof(t_hroom))) ? exit(1) : 0;
	hlist->id = ft_strinit(str);
	hlist->weight = -1;
	hlist->next = NULL;
	hlist->pipe = NULL;
	return (hlist);
}

void			ft_hroomend(t_hroom **hlist, char *str)
{
	t_hroom	*new_hlist;

	new_hlist = *hlist;
	if (new_hlist)
	{
		while (new_hlist->next != NULL)
			new_hlist = new_hlist->next;
		new_hlist->next = ft_hroomnew(str);
	}
	else
		*hlist = ft_hroomnew(str);
}

static t_hpipe	*ft_hpipenew(t_hroom **str)
{
	t_hpipe	*hlist;

	!(hlist = (t_hpipe *)malloc(sizeof(t_hpipe))) ? exit(1) : 0;
	hlist->room = *str;
	hlist->next = NULL;
	return (hlist);
}

void			ft_hpipesend(t_hpipe **hlist, t_hroom *str)
{
	t_hpipe	*new_hlist;

	new_hlist = *hlist;
	if (new_hlist)
	{
		while (new_hlist->next != NULL)
			new_hlist = new_hlist->next;
		new_hlist->next = ft_hpipenew(&str);
	}
	else
		*hlist = ft_hpipenew(&str);
}
