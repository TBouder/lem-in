/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcontentsize.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 11:57:01 by tbouder           #+#    #+#             */
/*   Updated: 2016/09/13 09:23:50 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstsize() gives us the total len of all the
** content_size of the list.
*/

#include "../libft.h"

int			ft_lstcontentsize(t_list *begin_list)
{
	int		len;

	len = 0;
	while (begin_list)
	{
		len += begin_list->content_size;
		begin_list = begin_list->next;
	}
	return (len);
}
