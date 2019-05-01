/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 17:30:35 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/29 14:24:46 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 128

# if BUFF_SIZE < 1
#  error BUFF SIZE < 1
# endif

# include <string.h>
# include <unistd.h>

typedef struct	s_list_fd
{
	struct s_list_fd	*next;
	int					fd;
	int					start;
	int					end;
	char				*data;
}				t_list_fd;

int				get_next_line(const int fd, char **line);

#endif
