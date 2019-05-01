/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blist_iter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:40:16 by ndombre           #+#    #+#             */
/*   Updated: 2016/12/08 20:12:42 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blist.h"

void	ft_blist_iteri(struct s_blist *dl, void (*f)(void *d, size_t i))
{
	struct s_blist_elem		*e;
	size_t					i;

	e = dl->next;
	i = 0;
	while (e != NULL)
	{
		(*f)(ft_blist_data(e), i++);
		e = e->next;
	}
}

void	ft_blist_iter(struct s_blist *dl, void (*f)(void *d))
{
	struct s_blist_elem *e;

	e = dl->next;
	while (e != NULL)
	{
		(*f)(ft_blist_data(e));
		e = e->next;
	}
}

void	*ft_blist_find(struct s_blist *dl, int (*f)(void *d,
			void *query), void *query)
{
	struct s_blist_elem *e;

	e = dl->next;
	while (e != NULL)
	{
		if (f(ft_blist_data(e), query) == 0)
			return (ft_blist_data(e));
		e = e->next;
	}
	return (NULL);
}
