/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/28 17:24:24 by tbouder           #+#    #+#             */
/*   Updated: 2016/01/05 20:52:26 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The list function ft_lstadd() appends the list new at the beginning of
** the linked list.
*/

#include "../libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (alst != NULL && new != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
}
