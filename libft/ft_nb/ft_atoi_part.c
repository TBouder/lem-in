/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_part.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/20 01:06:43 by tbouder           #+#    #+#             */
/*   Updated: 2016/03/16 13:58:01 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_atoi_part() function converts a portion of the string pointed to
** by str from the index i to int representation.
*/

#include "../libft.h"

int		ft_atoi_part(const char *str, int i)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (ft_strlen(str) == 0 || (str[i] < 32 && !ft_isspace(str[i])))
		return (0);
	while (str[i] <= 32)
		i++;
	if ((str[i] == '-' || str[i] == '+'))
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
		result = (result + str[i++] - '0') * 10;
	return (result / 10 * sign);
}
