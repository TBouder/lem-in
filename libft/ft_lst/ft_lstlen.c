/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/18 18:11:43 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/21 18:23:18 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstlen() goes through the linked list to count the
** number of links in the list.
*/

#include "../libft.h"

int		ft_lstlen(t_list *begin_list)
{
	int		nb;

	nb = 0;
	while (begin_list)
	{
		nb++;
		begin_list = begin_list->next;
	}
	return (nb);
}
