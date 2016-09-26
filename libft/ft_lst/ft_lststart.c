/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lststart.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:23:02 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:00:24 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lststart() appends the element content at the
** beginning of the linked list.
*/

#include <stdlib.h>
#include "../libft.h"

void	ft_lststart(t_list **list, void *content, size_t c_size)
{
	t_list	*new_list;

	if (list)
	{
		new_list = ft_lstnew(content, c_size);
		new_list->next = *list;
		*list = new_list;
	}
	else
		*list = ft_lstnew(content, c_size);
}
