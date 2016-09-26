/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_adler_thirtytwo.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/21 01:07:00 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/25 12:39:41 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** alder32 hash algo, 17933/20000 ~
*/

#include "../libft.h"

unsigned long int	adler_thirtytwo(const void *str, unsigned int len)
{
	const unsigned char *buff = (const unsigned char *)str;
	unsigned long int	hash;
	unsigned long int	s1;
	unsigned long int	s2;
	unsigned int		n;

	s1 = 1;
	s2 = 0;
	n = 0;
	while (buff[n])
	{
		s1 = (s1 + buff[n]) % 65521;
		s2 = (s2 + s1) % 65521;
		n++;
	}
	hash = (s2 << 16) | s1;
	len += len / 2;
	return (hash % len);
}
