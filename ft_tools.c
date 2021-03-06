/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tools.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/22 15:51:08 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/31 23:57:27 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

ULL			ft_atoi_onum(char *str)
{
	ULL		result;

	result = 0;
	if (ft_strlen(str) == 0 || *str <= 32 || *str == '-' || *str == '+')
		return (0);
	while (ft_isnumber(*str))
	{
		result = (result + *str++ - '0');
		if (ft_isnumber(*str))
			result *= 10;
		if (result > 2147483647)
			return (0);
	}
	if ((!(ft_isnumber(*str)) && *str != '\0') || (result == 0))
		return (0);
	return (result);
}

int			ft_nbline_gnl(char *str, int x)
{
	int		i;
	int		r;

	i = 0;
	r = 0;
	while (str[i])
	{
		if (str[i] == '-' && x == 1)
			break ;
		if (str[i] == '\n')
			r++;
		i++;
	}
	return (r);
}

int			ft_gnl_helper(int fd, t_list **lst, int j, int c)
{
	int				i;
	char			*buffer;
	int				k;

	buffer = ft_strnew(BUFF_SIZE);
	k = 0;
	while (c && (i = read(fd, buffer, BUFF_SIZE)) && buffer[0] != '\0')
	{
		!ft_isnumber(buffer[0]) && j == 0 ? ft_err_nothing(ERR10) : 0;
		if (i == 1 && buffer[0] == '\n')
			break ;
		ft_lstend(lst, buffer, i);
		j++;
	}
	ft_strdel(&buffer);
	return (1);
}

char		*ft_push_path(char **s1, char *s2)
{
	char	*str;

	if (s1 != NULL)
	{
		str = ft_strnew(ft_strlen(*s1) + ft_strlen(s2) + 1);
		ft_strcpy(str, *s1);
		ft_strcat(str, " ");
		ft_strcat(str, s2);
		ft_strdel(s1);
	}
	else
	{
		str = ft_strinit(s2);
		ft_strdel(s1);
	}
	return (str);
}

void		ft_path_remove_if_error(t_path **begin_path, char *str)
{
	t_path		*to_free;

	if (begin_path && *begin_path)
	{
		if (ft_isstrstr((*begin_path)->path, str))
		{
			to_free = *begin_path;
			*begin_path = (*begin_path)->next;
			ft_strdel(&to_free->path);
			free(to_free);
			ft_path_remove_if_error(begin_path, str);
		}
		else
			ft_path_remove_if_error(&(*begin_path)->next, str);
	}
}
