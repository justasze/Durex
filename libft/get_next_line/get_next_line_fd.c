/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:30:24 by ndombre           #+#    #+#             */
/*   Updated: 2017/03/10 20:26:30 by ndombre          ###   ########.fr       */
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

static ssize_t		ft_read_b(int fd, char *buff, size_t size)
{
	ssize_t ret;

	if ((ret = read(fd, buff, size)) <= 0)
		return (ret);
	if (ft_memchr(buff, '\0', ret))
		return (-1);
	return (ret);
}

static	int			ft_gnl_getl(t_list_fd *fdlstd, char **str)
{
	if (fdlstd->start >= fdlstd->end)
	{
		fdlstd->start = 0;
		if ((fdlstd->end = ft_read_b(fdlstd->fd, fdlstd->data, BUFF_SIZE)) <= 0)
		{
			if (*str != NULL && fdlstd->end == 0)
				fdlstd->end = -1;
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
	if (fdlstd->end < 0)
		return (-1);
	return (fdlstd->end != 0);
}

int					get_next_line(const int fd, char **line)
{
	static t_list_fd		f;
	static char				tab[BUFF_SIZE] = {0};
	static t_list_fd		*fdlst = NULL;
	int						ret;

	if (fdlst == NULL)
	{
		fdlst = &f;
		ft_bzero(fdlst, sizeof(t_list_fd));
		fdlst->data = tab;
		fdlst->fd = fd;
	}
	if (line == NULL || fd < 0)
		return (-1);
	*line = NULL;
	ret = ft_gnl_getl(fdlst, line);
	return (ret);
}
