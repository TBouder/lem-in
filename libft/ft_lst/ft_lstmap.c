/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/29 11:07:30 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/05 10:55:36 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstmap() goes through the linked list to apply the
** f() function by each link and save the result in a new t_list. At the
** end, it returns this t_list
*/

#include "../libft.h"
#include <stdlib.h>

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new = f(lst);
	if (lst->next)
		new->next = ft_lstmap(lst->next, f);
	return (new);
}
