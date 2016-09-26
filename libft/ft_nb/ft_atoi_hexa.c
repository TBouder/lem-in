/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_hexa.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Tbouder <Tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/02 17:15:21 by tbouder           #+#    #+#             */
/*   Updated: 2016/02/04 14:06:21 by Tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

static int		ft_hexa(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'A' && c <= 'F')
		return (c - 55);
	else if (c >= 'a' && c <= 'f')
		return (c - 87);
	return (0);
}

static int		ft_convert_base(char *str)
{
	int		*nbrs;
	int		i;
	int		len;
	int		r_value;

	i = 0;
	r_value = 0;
	len = ft_hexalen((char *)str);
	nbrs = ft_nbrnew(len);
	while (str[i] && ft_ishexa(str[i]))
	{
		nbrs[i] = ft_hexa(str[i]) * ft_power(16, (len - 1) - i);
		i++;
	}
	i = 0;
	while (str[i] && ft_ishexa(str[i]))
	{
		r_value += nbrs[i];
		i++;
	}
	return (r_value);
}

int				ft_atoi_hexa(const char *str)
{
	int		result;
	int		sign;

	sign = 1;
	result = 0;
	if (ft_strlen(str) == 0)
		return (0);
	if ((*str == '-' || *str == '+'))
	{
		(*str == '-') ? sign = -1 : 0;
		str++;
	}
	if (ft_ishexa(*str))
		result = ft_convert_base((char *)str);
	return (result * sign);
}
