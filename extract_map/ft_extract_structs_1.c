/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_structs_1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:19:32 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 14:52:52 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static t_hroom	*ft_hcoonew(char **s)
{
	t_hroom	*hlist;

	!(hlist = (t_hroom *)malloc(sizeof(t_hroom))) ? exit(1) : 0;
	hlist->id = ft_join(s);
	hlist->coo_id = ft_strinit(s[0]);
	hlist->weight = -1;
	hlist->next = NULL;
	hlist->pipe = NULL;
	hlist->coo = NULL;
	return (hlist);
}

void			ft_hcooend(t_hroom **hlist, char **s)
{
	t_hroom	*new_hlist;

	new_hlist = *hlist;
	if (new_hlist)
	{
		while (new_hlist->next != NULL)
			new_hlist = new_hlist->next;
		new_hlist->next = ft_hcoonew(s);
	}
	else
		*hlist = ft_hcoonew(s);
}
