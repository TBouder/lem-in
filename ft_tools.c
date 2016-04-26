/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:51:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/04/26 18:10:53 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

void	ft_error(char *str)
{
	ft_printf("%s\n", str);
	exit(EXIT_FAILURE);
}

long	ft_atoi_onum(const char *str)
{
	long	result;
	int		sign;

	sign = 1;
	result = 0;
	if (ft_strlen(str) == 0 || (*str < 32 && !ft_isspace(*str)))
		ft_error("Ant {r}error{0} : number of ant cannot be 0");
	while (*str <= 32)
		str++;
	if ((*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign = -1;
		str++;
	}
	while (ft_isnumber(*str))
		result = (result + *str++ - '0') * 10;
	if (!(ft_isnumber(*str)) && *str != '\0')
		ft_error("Ant {r}error{0} : number of ant must be a number");
	if (result / 10 * sign == 0)
		ft_error("Ant {r}error{0} : number of ant cannot be 0");
	return (result / 10 * sign);
}

int	ft_dbtablelen(char **str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin_here(char const *s1, char const *s2)
{
	char	*str;

	str = NULL;
	if (s1 != NULL && s2 != NULL)
	{
		str = ft_strnew((ft_strlen(s1) + ft_strlen(s2) + 1));
		ft_strcpy(str, (char *)s1);
		str = ft_strcat(str, s2);
		return (str);
	}
	return (NULL);
}

char	*ft_strjoin_endl(char *s1, char *s2)
{
	char	*str;

	str = ft_strnew(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(str, s1);
	ft_strcat(s1, s2);
	// str = ft_strjoin_here(s1, s2);
	// str = ft_strjoin_here(str, "\n");
	return (str);
}
