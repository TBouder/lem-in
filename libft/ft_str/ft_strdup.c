/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/23 15:36:36 by tbouder           #+#    #+#             */
/*   Updated: 2015/12/25 14:37:19 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strdup() function allocates sufficient memory for a copy of the
** string s1, does the copy, and returns a pointer to it.
*/

#include "../libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*ptr;

	if ((ptr = (char*)malloc(sizeof(*ptr) * (ft_strlen(s1) + 1))) == NULL)
		return (NULL);
	ft_strcpy(ptr, s1);
	return (ptr);
}
