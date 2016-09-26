/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strinit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/02 14:47:28 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/02 14:48:54 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_strinit() function mallocs a new string with s1 inside.
*/

#include "../libft.h"

char	*ft_strinit(char *s1)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1));
	ft_strcpy(str, s1);
	return (str);
}
