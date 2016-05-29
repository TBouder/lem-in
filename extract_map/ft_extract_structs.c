/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_extract_structs.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/22 18:19:32 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 00:18:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_extract.h"

static t_hroom	*ft_hroomnew(t_env *env, char *str, char **s)
{
	t_hroom	*hlist;
	char	*coo;

	!(hlist = (t_hroom *)malloc(sizeof(t_hroom))) ? exit(1) : 0;
	hlist->id = ft_strinit(str);
	hlist->coo_id = NULL;
	hlist->weight = -1;
	hlist->next = NULL;
	hlist->pipe = NULL;
	coo = ft_join(s);
	hlist->coo = env->hash_coo[ft_hash_djbtwo(coo, env->room_len)];
	free(coo);
	return (hlist);
}

void			ft_hroomend(t_env *env, t_hroom **hlist, char *str, char **s)
{
	t_hroom	*new_hlist;

	new_hlist = *hlist;
	if (new_hlist)
	{
		while (new_hlist->next != NULL)
			new_hlist = new_hlist->next;
		new_hlist->next = ft_hroomnew(env, str, s);
	}
	else
		*hlist = ft_hroomnew(env, str, s);
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
