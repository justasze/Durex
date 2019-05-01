/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_blist_dell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndombre <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/07 16:38:23 by ndombre           #+#    #+#             */
/*   Updated: 2016/12/09 11:41:38 by ndombre          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "blist.h"

void	ft_blist_del_all(struct s_blist *dl)
{
	struct s_blist_elem *e;
	struct s_blist_elem *old;

	e = dl->next;
	while (e != NULL)
	{
		old = e;
		e = e->next;
		ft_free(old);
	}
}

void	ft_blist_del_feast(struct s_blist *dl)
{
	struct s_blist_elem *old;

	if (dl->next == NULL)
		return ;
	old = dl->next;
	dl->next = dl->next->next;
	ft_free(old);
}
