/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blist_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:19:06 by ndombre           #+#    #+#             */
/*   Updated: 2016/12/07 19:58:21 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blist.h"

struct s_blist		*ft_blist_new(size_t content_size)
{
	struct s_blist *ret;

	ret = ft_malloc(sizeof(*ret));
	if (ret == NULL)
		return (NULL);
	ret->content_size = content_size;
	ret->next = NULL;
	return (ret);
}

struct s_blist		ft_blist_ini(size_t content_size)
{
	struct s_blist ret;

	ret.content_size = content_size;
	ret.next = NULL;
	return (ret);
}

struct s_blist_elem	*ft_blist_new_elem(struct s_blist *list,
		void const *data)
{
	struct s_blist_elem *ret;

	ret = ft_malloc(sizeof(struct s_blist_elem) + list->content_size);
	if (ret == NULL)
		return (NULL);
	ft_memcpy(((void*)ret) + sizeof(struct s_blist_elem),
			data, list->content_size);
	ret->next = NULL;
	return (ret);
}
