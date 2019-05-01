/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:30:56 by ndombre           #+#    #+#             */
/*   Updated: 2016/11/10 10:44:55 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstnew(void const *content, size_t content_size)
{
	t_list *ret;

	if (content == NULL)
		content_size = 0;
	ret = ft_malloc(sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	ret->next = NULL;
	if (content != NULL)
		ret->content = ft_memdup(content, content_size);
	else
		ret->content = NULL;
	ret->content_size = content_size;
	return (ret);
}
