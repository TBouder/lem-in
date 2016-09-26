/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 10:53:16 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/21 18:23:21 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstend() goes through the linked list and apply the
** f function for all the elements.
*/

#include "../libft.h"

void	ft_lstiter(t_list *lst, void (f)(t_list *elem))
{
	while (lst != NULL)
	{
		f(lst);
		lst = lst->next;
	}
}
