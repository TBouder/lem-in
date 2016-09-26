/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:23:05 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/05 17:40:49 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstend() appends the element content at the
** end of the linked list.
*/

#include <stdlib.h>
#include "../libft.h"

void	ft_lstend(t_list **list, void *content, size_t c_size)
{
	t_list	*new_list;

	new_list = *list;
	if (new_list)
	{
		while (new_list->next != NULL)
			new_list = new_list->next;
		new_list->next = ft_lstnew(content, c_size);
	}
	else
		*list = ft_lstnew(content, c_size);
}
