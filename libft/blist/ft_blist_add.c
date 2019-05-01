/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blist_add.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:28:11 by ndombre           #+#    #+#             */
/*   Updated: 2016/12/07 16:37:38 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blist.h"

struct s_blist_elem	*ft_blist_add_first_elem(struct s_blist *l,
		void const *data)
{
	struct s_blist_elem *elem;

	elem = ft_blist_new_elem(l, data);
	if (elem == NULL)
		return (NULL);
	elem->next = l->next;
	l->next = elem;
	return (elem);
}

struct s_blist_elem	*ft_blist_add_last_elem(struct s_blist *l,
		void const *data)
{
	struct s_blist_elem *cur;

	if (l->next == NULL)
		return (ft_blist_add_first_elem(l, data));
	cur = l->next;
	while (cur->next != NULL)
		cur = cur->next;
	cur->next = ft_blist_new_elem(l, data);
	return (cur->next);
}
