/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 19:25:18 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:00:07 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstprint() prints the linked list.
*/

#include "../libft.h"
#include <unistd.h>

void		ft_lstprint(t_list *begin_list)
{
	while (begin_list)
	{
		write(1, begin_list->content, begin_list->content_size);
		begin_list = begin_list->next;
	}
}
