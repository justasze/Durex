/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:30:24 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/29 15:32:36 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "get_next_line.h"
#include <unistd.h>
#include "libft.h"

static char			*ft_strjoinf(char *str, char *buffer, int l)
{
	char	*ret;
	size_t	strs;
	char	*t;

	if (str == NULL)
	{
		if ((ret = malloc(l + 1)) == NULL)
			return (NULL);
		t = ft_memccpy(ret, buffer, '\n', l);
		if (t != NULL)
			*(t - 1) = '\0';
		else
			ret[l] = '\0';
		return (ret);
	}
	strs = ft_strlen(str);
	if ((ret = malloc(strs + l + 1)) == NULL)
		return (NULL);
	ret[strs + l] = '\0';
	ft_strcpy(ret, str);
	if ((t = ft_memccpy(ret + strs, buffer, '\n', l)) != NULL)
		*(t - 1) = '\0';
	free(str);
	return (ret);
}

static	int			ft_gnl_getl(t_list_fd *fdlstd, char **str)
{
	if (fdlstd->end == -5)
		return (0);
	if (fdlstd->start >= fdlstd->end)
	{
		fdlstd->start = 0;
		if ((fdlstd->end = read(fdlstd->fd, fdlstd->data, BUFF_SIZE)) <= 0)
		{
			if (*str != NULL && fdlstd->end == 0)
				fdlstd->end = -5;
			return (fdlstd->end);
		}
	}
	if ((*str = ft_strjoinf(*str, fdlstd->data + fdlstd->start,
			fdlstd->end - fdlstd->start)) == NULL)
		return (-1);
	while (fdlstd->start < fdlstd->end && fdlstd->data[fdlstd->start] != '\n')
		fdlstd->start++;
	if (fdlstd->start < fdlstd->end && fdlstd->data[fdlstd->start] == '\n')
		fdlstd->start++;
	else
		ft_gnl_getl(fdlstd, str);
	return (fdlstd->end != 0);
}

static t_list_fd	*ft_gnl_getfd(t_list_fd **fdlstd, int fd)
{
	t_list_fd		*fdlst;

	if (*fdlstd == NULL)
	{
		if ((*fdlstd = ft_memalloc(sizeof(t_list_fd))) == NULL)
			return (NULL);
		(*fdlstd)->fd = fd;
		return (*fdlstd);
	}
	if ((*fdlstd)->fd == fd)
		return (*fdlstd);
	fdlst = *fdlstd;
	while (fdlst->next)
		if ((fdlst = fdlst->next) && fdlst->fd == fd)
			return (fdlst);
	if ((fdlst->next = ft_memalloc(sizeof(t_list_fd))) == NULL)
		return (NULL);
	fdlst->next->fd = fd;
	return (fdlst->next);
}

static void			ft_gnl_dellit(t_list_fd **fdlst, int fd)
{
	t_list_fd	*elem;
	t_list_fd	*tmp;

	elem = *fdlst;
	if ((*fdlst)->fd == fd)
	{
		*fdlst = (*fdlst)->next;
		if (elem->data)
			free(elem->data);
		free(elem);
		return ;
	}
	while (elem->next->fd != fd)
		elem = elem->next;
	tmp = elem->next;
	elem->next = elem->next->next;
	if (tmp->data)
		free(tmp->data);
	free(tmp);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd		*fdlst = NULL;
	t_list_fd				*elem;
	int						ret;

	if (line == NULL || fd < 0 || !(elem = ft_gnl_getfd(&fdlst, fd)))
		return (-1);
	if (*line != NULL)
		free(*line);
	*line = NULL;
	if (elem->data == NULL)
		if ((elem->data = ft_memalloc(BUFF_SIZE)) == NULL)
		{
			ft_gnl_dellit(&fdlst, fd);
			return (-1);
		}
	if ((ret = ft_gnl_getl(elem, line)) != 1)
		ft_gnl_dellit(&fdlst, fd);
	return (ret);
}
