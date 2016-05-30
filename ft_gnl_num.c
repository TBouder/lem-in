/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_gnl_num.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tbouder <tbouder@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 11:59:39 by tbouder           #+#    #+#             */
/*   Updated: 2016/05/30 18:17:58 by tbouder          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lemin.h"

static int		ft_freestr(t_list **str, int rv, t_list *tmp)
{
	int		i;

	i = 1;
	tmp = *str;
	if (ft_lstlen(tmp) != 1)
		while (tmp)
		{
			if (((char *)tmp->content)[0] != '\0')
				return (rv);
			tmp = tmp->next;
		}
	while (str && i == 1)
	{
		(*str)->content--;
		while (((char *)(*str)->content)[0] != '\2')
			(*str)->content--;
		if ((*str)->next == NULL)
			i = 0;
		*str = (*str)->next;
	}
	ft_lstclr(str);
	ft_lstclr(&tmp);
	*str = NULL;
	return (rv);
}

static char		*ft_helper(char *str, char **line)
{
	char	*dst;
	int		i;
	int		j;
	int		len;

	i = 0;
	j = 0;
	len = ft_linelen(str, 0);
	dst = ft_strnew(len);
	if (str[0] == '\2')
	{
		j++;
		len--;
	}
	while (i < len)
	{
		dst[i] = str[j];
		j += 1;
		i += 1;
	}
	str += j;
	*line = ft_strnew(len + 1);
	ft_strncpy(*line, dst, len);
	ft_strdel(&dst);
	return (str);
}

static int		ft_extract_line(int const fd, t_list **s, t_list *lst, int **x)
{
	int				i;
	char			*buffer;
	t_list			*tmp;

	buffer = ft_strnew(BUFF_SIZE);
	while ((i = read(fd, buffer, BUFF_SIZE)) && buffer[0] != '\0')
		ft_lstend(&lst, buffer, i);
	ft_strdel(&buffer);
	if (i == -1)
		return (-1);
	buffer = ft_strnew(ft_lstcontentsize(lst) + 1);
	buffer[0] = '\2';
	tmp = lst;
	while (tmp)
	{
		buffer = ft_strncat(buffer, tmp->content, tmp->content_size);
		tmp = tmp->next;
	}
	x != NULL ? x[0][0] = ft_nbline_gnl(buffer, 1) : 0;
	x != NULL ? x[0][1] = ft_nbline_gnl(buffer, 0) : 0;
	ft_lstclr(&lst);
	ft_lstend(s, buffer, ft_strlen(buffer) + 1);
	ft_strdel(&buffer);
	return (1);
}

static t_list	*ft_change_link(t_list **str, int fd, int **x)
{
	t_list		*tmp;

	if ((size_t)fd != (*str)->content_size)
	{
		tmp = *str;
		while (tmp->next && (size_t)fd != tmp->content_size)
			tmp = tmp->next;
		if (tmp->next == NULL && (size_t)fd != tmp->content_size)
		{
			tmp = *str;
			if (ft_extract_line(fd, &tmp, NULL, x) == -1)
				return (NULL);
			while (tmp->next && (size_t)fd != tmp->content_size)
				tmp = tmp->next;
			tmp->content_size = (size_t)fd;
		}
		return (tmp);
	}
	return (*str);
}

int				get_next_line_num(int const fd, char **line, int **x)
{
	static t_list	*str = NULL;
	t_list			*tmp;
	int				i;

	if (line == NULL)
		return (-1);
	if (!str)
	{
		if ((i = ft_extract_line(fd, &str, NULL, x)) == -1)
			return (-1);
		str->content_size = (size_t)fd;
	}
	if ((tmp = ft_change_link(&str, fd, x)) == NULL)
		return (-1);
	if (((char *)tmp->content)[1] == '\0')
		i = 0;
	tmp->content = ft_helper(tmp->content, line);
	if (((char *)tmp->content)[0] == '\0' && i == 0)
		return (ft_freestr(&str, 0, NULL));
	((char *)tmp->content)[0] == '\n' ? (tmp->content)++ : 0;
	if (((char *)tmp->content)[0] == '\0')
		return (ft_freestr(&str, 1, NULL));
	return (1);
}
