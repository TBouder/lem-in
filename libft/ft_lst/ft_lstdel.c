/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:53:16 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/04 11:36:42 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstdel() deletes a link and all the links after with
** the del function and free these links.
*/

#include <stdlib.h>
#include "../libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list		*temp;
	t_list		*lst;

	temp = *alst;
	while (temp)
	{
		lst = temp->next;
		del(temp->content, temp->content_size);
		free(temp);
		temp = lst;
	}
	*alst = NULL;
}
